#include "shell.h"

/**
 * executable_function - executes a command given in a dir concatenation
 * @bus: bus of data to process
 * @selected: selection betwwen case if command started with dir or not
 * @buffer: Buffer only useful when is needed to compute a calculated path to
 * execute the function
 *
 * Description:
 * Runs a function in a child process given the command and the arguments
 * inside the matrix tokens, kills the child process and keeps running.
 *
 * Return: 0 on success, -1 on failure.
 */
int executable_function(custom *bus, int selected, char *buffer)
{
	pid_t child_pid;
	char *command = NULL;

	if (selected == 1)
		command = bus->tokens[0];
	else
		command = buffer;
	if (exist_dir(command) == 0) /* Exists*/
	{
		print_error_not_found(bus, ": not found");
		return (-1);
	}
	if (access(command, X_OK) != 0) /*Is not executable*/
	{
		print_error_not_found(bus, " Permission denied\n");
		bus->status = 126;
		return (-1);
	}
	child_pid = fork(); /* Creating child*/
	if (child_pid > 0)
	{ /* Is parent */
		wait(&bus->status);
		if (WIFEXITED(bus->status) != 0)
		{
			bus->status = WEXITSTATUS(bus->status);
			bus->need_to_exit = 1;
		}
	}
	else if (child_pid < 0) /* Error creating child*/
		print_error_not_found(bus, NULL);

	else if (execve(command, bus->tokens, bus->env) == -1)
	{
		print_error_not_found(bus, NULL);
		bus->need_to_exit = 1;
		bus->status = 127;
		return (1);
	}

	return (0);
}
/**
 * execution_not_dir - function that execute a command not gived
 * like a dir concatenation
 * @bus: Bus of data to process
 * Return: Always 0
 **/
int execution_not_dir(custom *bus)
{
	char *path, *copy_path, *merge1 = NULL, *merge2 = NULL;
	char **tokensDirectory;
	int i;
	struct stat buf;

	path = getPath(bus);
	if (path != NULL)
	{
		copy_path = _strdup(path);
		tokensDirectory = create_tokens(copy_path, ":");
		for (i = 0; tokensDirectory != NULL && tokensDirectory[i] != NULL;
			 i++, free(merge2), free(merge1))
		{
			merge1 = str_concat(tokensDirectory[i], "/");
			merge2 = str_concat(merge1, bus->tokens[0]);
			if (stat(merge2, &buf) == 0)
			{
				executable_function(bus, 2, merge2);
				free(merge2);
				free(merge1);
				break;
			}
		}
		if (tokensDirectory == NULL || tokensDirectory[i] == NULL)
		{
			bus->status = 127;
			print_error_not_found(bus, ": not found");
		}
		free(copy_path);
	}
	free(tokensDirectory);
	return (0);
}
