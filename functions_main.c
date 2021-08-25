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
		if (sign == EOF && errno == 0)
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

int main_parse(char ***Dtokens, char **Dline, const char *delim)
{

	*Dtokens = create_tokens(*Dline, delim);
	assignTokens(*Dline, *Dtokens, delim);
	if (*Dtokens[0] == NULL)
	{
		free(*Dline);
		free(*Dtokens);
		*Dline = NULL;
		*Dtokens = NULL;
		return (1);
	}
	return (0);
}
int main_check_built_in(char ***tokens, char ***tokenDirectory, char **line,
			char **pathPtr, char **executablePath, int flag)
{
	int (*f)(char *);

	f = check_built_in(*tokens[0]);
	if (f != NULL)
	{
		if (f(*tokens[0]) == 50)/*Exec & stores retVal*/
		{
			free_exit(*tokens, *tokenDirectory, *line,
				  *pathPtr, *executablePath, flag);
		}

		free(*line);
		free(*tokens);
		*line = NULL;
		*tokens = NULL;
		return (1);
	}
	else
		return (0);
}
int main_get_path(char **pathPtr, char **env, char ***tokenDirectory,
		int *flag)
{
		if (*flag != 1) /* Optimization by running this only onces */
		{
/* get PATH*/
			*pathPtr = _strdup(getPath(env));
/* Parse PATH */
			*tokenDirectory = create_tokens(*pathPtr, ":");
			assignTokens(*pathPtr, *tokenDirectory, ":");
			*flag = 1;
		}
		return (0);
}


int main_execute(char **executablePath, char ***tokenDirectory,
		char ***tokens, char *argv, int countExec, char **line)
{
		struct stat buf;

		*executablePath = find_command_in_path(*tokenDirectory,
				*tokens[0]);

		if (*executablePath != NULL)
		{
/*Here goes executable function*/
			/*printf("running executable through PATH concatenation\n");*/
			errno = 0;
			executable_function(*executablePath, *tokens);
			if (errno != 0)
			{
				print_error_not_found(argv, *tokens[0], countExec);
			}

			free(*line);
			free(*tokens);
			*line = NULL;
			*tokens = NULL;
			free(*executablePath);
			*executablePath = NULL;
		}
		else if (stat(*tokens[0], &buf) == 0)/* is command executable at local file?*/
		{
			/*printf("(stat is telling us a 'true')I am running executable function at local dir \n");*/
			errno = 0;
			executable_function(*tokens[0], *tokens);
			if (errno != 0)
				print_error_not_found(argv, *tokens[0], countExec);
			free(*line);
			free(*tokens);
			*line = NULL;
			*tokens = NULL;
			return (1);
		}
		else
		{
			/*printf("Case: not found\n");*/
			errno = 0;
			print_error_not_found(argv, *tokens[0], countExec);
			free(*line);
			free(*tokens);
			*line = NULL;
			*tokens = NULL;
			free(*executablePath);
			*executablePath = NULL;
		}
		return (0);
}
