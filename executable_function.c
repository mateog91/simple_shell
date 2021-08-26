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
int executable_function(char *command, char **tokens, c_variables *variables)
{
	pid_t child_pid;
	int status;

	child_pid = fork();
	if (child_pid == -1)
	{
		perror("Error:");
		return (1);
	}
	if (child_pid == 0)
	{
		if (execve(command, tokens, variables->env) == -1)
		{
			/*perror("Error: execve failed");*/
			return (-1);
		}
	}
	wait(&status);
	return (0);
}
