#include "shell.h"

/**
 *find_command_in_path - test if input command is in any possible PATH
 * @PATH: Double pointer to a matrix with PATHS tokens
 * @command: String with input command
 *
 * Description:
 * Searches on the matrix that contains all the PATH tokens, concatenates them with the command, and tests if the command is in that curren PATH token.
 *
 * Return:
 * If found, returns theconcatenation string in which the input command is.
 * If not found, returns NULL.
 */
char *find_command_in_path(char **PATH, char *command )
{
	int i = 0;
	char *concat;
	struct stat buf;

	while (PATH[i] != NULL)
	{
		/*Concatanate matrix[i] with command*/
		concat = str_concat(PATH[i], command);
		/* Find if concat is in PATH*/
		if ((stat(concat, &buf)) == 0)
		{
			printf("Found concat link at PATH[%i], %s", i, concat);
			return (concat);
		}
		i++;
	}
	/* If it is not found return NULL */
	return (NULL);
}
