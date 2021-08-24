#include "shell.h"
/**
 * main_get_line - resolves what to be done with line and frees accordingly
 * @tokenDirectory: matrix with tokenDirectory of Paths
 * @tokens: matrix with tokenized line
 * @pathPtr: pointer to path
 * @executablePath: pointer with an executable path
 * @line: pointer to line from command line
 * @sign: return value from getline
 * @flag: value of flag
 * 
 * Description:
 * Handles what to be done after getline is executed
 * If sign is < 0 means a signal of end of file is found
 * With this, it frees the functions accordingly
 *
 * Returns: Nothing
 */
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

int main_parse(char **tokens, char *line, const char *delim)
{
        tokens = create_tokens(line, delim);
        assignTokens(line, tokens, delim);
        if (tokens[0] == NULL)
        {
                free(line);
                free(tokens);
                line = NULL;
                tokens = NULL;
                return (1);
        }
	return (0);
}
