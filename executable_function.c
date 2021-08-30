#include "shell.h"

/**
 * executable_function - executes a command given a matrix tokens
 * @command: A string with the command to be executed
 * @tokens: Matrix with the arguments to be run with the command
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
	int status;
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
	/*
	printf("%s", command);
	return (0);*/
	if (child_pid > 0) /* Is parent */
		wait(&status);
	else if (child_pid < 0) /* Error creating child*/
		print_error_not_found(bus, NULL);

	else if (execve(command, bus->tokens, bus->env) == -1)
	{
		print_error_not_found(bus, NULL);
		bus->status = 127;
		return (1);
	}

	return (0);
}
/**
 * 
 * 
 * 
 **/
int execution_not_dir(custom *bus)
{
	char *path, *copy_path, *merge1 = NULL, *merge2 = NULL;
	char **tokensDirectory;
	int i = 0;
	struct stat buf;

	(void)buf;
	path = getPath(bus);
	copy_path = _strdup(path);
	tokensDirectory = create_tokens(copy_path, ":");
	while (tokensDirectory != NULL && tokensDirectory[i] != NULL)
	{
		merge1 = str_concat(tokensDirectory[i], "/");
		merge2 = str_concat(merge1, bus->tokens[0]);

		if (stat(merge2, &buf) == 0)
		{
			executable_function(bus, 2, merge2);
			free(merge1);
			free(merge2);
			break;
		}

		i++;
	}
	free(copy_path);

	return (0);
}