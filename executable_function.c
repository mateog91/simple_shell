#include "shell.h"

int executable_function(char *command, char **tokens)
{
	pid_t child_pid;
	int status;

	child_pid = fork();
	if (child_pid == -1)
	{
		perror("Error:");
		return (1);
	}
	wait(&status);
	/*free(line);*/
	if (child_pid == 0)
	{
	
		/*si algo es tokens[0]*/
		if (execve(command, tokens, NULL) == -1)
		{
			perror("Error: execve failed");
			return (-1);
		}
	}
	return (0);
}
