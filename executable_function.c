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
int executable_function(custom *bus)
{
	pid_t child_pid;
	int status;

	if (is_dir(bus->tokens[0]) == 1)
	{
		if (exist_dir(bus->tokens[0]) == 0) /* Exists*/
		{
			print_error_not_found(bus, ": not found");
			return (-1);
		}
		if (access(bus->tokens[0], X_OK) != 0) /*Is not executable*/
		{
			print_error_not_found(bus, " Permission denied\n");
			bus->status = 126;
			return (-1);
		}
		child_pid = fork(); /* Creating child*/
		if (child_pid > 0)	/* Is parent */
			wait(&status);
		else if (child_pid < 0) /* Error creating child*/
			print_error_not_found(bus, NULL);
		else if (execve(bus->tokens[0], bus->tokens, bus->env) == -1)
		{
			print_error_not_found(bus, NULL);
			bus->status = 127;
			return (1);
		}
	}
	else
	execution_not_dir(bus);

	return (0);
}
