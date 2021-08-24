#include "shell.h"

void main_get_line(char **tokenDirectory, char **tokens, char *pathPtr,
		   char *executablePath, char *line, int sign, int flag)
{
	if (sign < 0) /* Is EOF ?*/
	{
		if(sign == EOF)
			_putchar('\n');
		free(line);
		free(tokens);
		if (flag == 1)
		{
			free(pathPtr);
			free(tokenDirectory);
			free(executablePath);
		}
		exit(1);
	}
}
