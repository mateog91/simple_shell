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
	/*
	int status;*/
	pid_t child_pid;
	int status;

	child_pid = fork();
	if (child_pid == -1)
	{
		perror("Error:");

	}
	if (child_pid == 0)
	{
	if (execve(str_concat("/bin/",bus->tokens[0]), bus->tokens, bus->env) == -1)
		print_error_not_found(bus, NULL);
	}

	wait(&status);
	/*
	child_pid = fork();
	if (child_pid == -1)
	{
		perror("Error:");

	}
	if (child_pid == 0)
	{
		if (execve(bus->tokens[0], bus->tokens, bus->env) == -1)
		{

		}
	}
	*/
	/*wait(&status);*/
	return (0);
}
