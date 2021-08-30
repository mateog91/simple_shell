#include "shell.h"
/**
 **getPath - get buffer contained in route PATH
 * @bus: Bus of data to processing
 * Return: Pointer to string containing PATH=
 **/
char *getPath(custom *bus)
{
	char *first_part;
	int i = 0, j;

	first_part = "PATH";

	/*Go through vector with env viariablis in search of PATH */
	while (bus->env[i])
	{
		/* Compares char by char of current with PATH*/
		for (j = 0; j < 4; j++)
		{
			if (first_part[j] != bus->env[i][j]) /* Break when not = */
			{
				break;
			}
		}
		if (j == 4) /* All characters match so end and return */
			break;
		i++;
	}
	return (bus->env[i] + 5);
}

/**
 * is_dir - That inform is there is a / in the buffer
 * @bus: bus of data that contains the buffer to check
 * Return:
 *         1 if find '/'
 *         0 if not find '/'
 **/
int is_dir(custom *bus)
{
	int j = 0;

	while (bus->tokens[0][j] != '\0')
	{
		if (bus->tokens[0][j] == '/')
			return (1);
		j++;
	}
	return (0);
}
/**
 * exist_dir - function that let us know if exist a dir
 * @str: dir to check if exists
 * Return:
 *        1 when exists
 *        0 when doesn't exists
 *
 **/
int exist_dir(char *str)
{
	struct stat buf;

	if (stat(str, &buf) == 0)
		return (1);
	return (0);
}
