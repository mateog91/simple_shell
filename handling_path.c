#include "shell.h"
/**
 * *getPath - get buffer contained in route PATH
 * @env: Matrix containing enviroment variables
 *
 * Return: Pointer to string containing PATH=
 */
char *getPath(char **env)
{
        char *first_part;
        int i = 0, j;

	/*i advances rows of env matrix */
	/*j advances chars of current string in current row i */

        first_part = "PATH";

	/*Go through vector with env viariablis in search of PATH */
        while (env[i])
        {
		/* Compares char by char of current with PATH*/
                for (j = 0; j < 4; j++)
                {
                        if (first_part[j] != env[i][j]) /* Break when not = */
                        {
                                break;
                        }
                }
                if (j == 4) /* All characters match so end and return */
                        break;
                i++;
        }
        return (env[i]);
}
