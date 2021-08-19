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
	char *concat = NULL;
	struct stat buf;

	while (PATH[i] != NULL)
	{
		char *concat1 = NULL;
		/*concat = str_concat(command) */
		/*Concatanate matrix[i] with command*/
		concat1 = str_concat("/", command);
		concat = str_concat(PATH[i], concat1);

		/*printf("concat[%i] is %s\n",i, concat);*/
		/* Find if concat is in PATH*/
		if ((stat(concat, &buf)) == 0)
		{
			/*printf("Found concat link at PATH[%i], %s", i, concat);*/
			free(concat1);
			return (concat);
		}
		i++;
		free(concat);
		free(concat1);
		concat = NULL;
		concat1 = NULL;
	}
	/* If it is not found return NULL */
	return (NULL);
}
