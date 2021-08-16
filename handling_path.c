#include "shell.h"
/**
 * *getPath - get buffer contained in route PATH
 * @env: enviroment variable
 * Return: Path
 *
 */
char *getPath(char **env)
{
        char *first_part;
        int i = 0, j;
        first_part = "PATH";
        while (env[i])
        {
                for (j = 0; j < 4; j++)
                {
                        if (first_part[j] != env[i][j])/*Any prev match */
                        {
                                break;
                        }
                }
                if (j == 4)/*All char matches */
                        break;
                i++;
        }
        return (env[i]);
}
