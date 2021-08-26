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
		exit(EXIT_SUCCESS);
	}
}
/**
 * main_parse - tokenize input string into tokens and stores them in a matrix
 * @tokens: Matrix where each individual token is stored in
 * @line: Input line from user command line.
 * @delim: String of characters to parse with.
 *
 * Description:
 * Parses the given input string line into tokens and store them in the given
 * matrix. Each Parse is done when the delimitator is found.
 *
 * Return:
 * 0 if when the parse is done
 * 1 when there was no parse done
 */
int main_parse(char ***tokens, char **line, const char *delim)
{

	*tokens = create_tokens(*line, delim);
	assignTokens(*line, *tokens, delim);
	if (*tokens[0] == NULL)
	{
		free(*line);
		free(*tokens);
		*line = NULL;
		*tokens = NULL;
		return (1);
	}
	return (0);
}

/**
 * main_check_built_in - checks if the command is a built in function
 * @tokens: Matrix where each individual token is stored in
 * @tokenDirectory: Matrix where Paths are stored in.
 * @line: Input line from user command line.
 * @pathPtr: Pointer to PATH.
 * @executablePath: A current path that holds a possible executable command
 * @flag: Flag that tells if first time running.
 *
 * Description:
 * Checks if the command is in the built in functions, if it finds it runs it.
 *
 * Return:
 * 1 if a built in function is found
 * 50 if exit is found
 * 0 if no built in function is found
 */
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

/**
 * main_get_path - copies PATH enviorment variable and parses it
 * @pathPtr: Pointer to PATH.
 * @env: System enviormental variables
 * @tokenDirectory: Matrix where Paths are stored in.
 * @flag: Flag that tells if first time running.
 *
 * Return: 0 on success
 */
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
			free_matrix(env);
		}
		return (0);
}

/**
 * main_execute - Executes the command line if founds and frees the variables
 * @executablePath: A current path that holds a possible executable command
 * @tokenDirectory: Matrix where Paths are stored in.
 * @tokens: Matrix where each individual token is stored in
 * @argv: Shells executable name file.
 * @countExec: Number of times the shell has run.
 * @line: Input line from user command line.
 *
 * Descritpion:
 * Finds if the command is an executable in the PATH env variable
 * If it finds it it executes it.
 * If not, checks if command is a executable file at locat directory
 * If it is, it executes it
 * If not found, prints error.
 * On all cases it frees variables accordingly.
 *
 * Return:
 * 1 if command is executable at local directory
 * 0 on other cases.
 */

int main_execute(char **executablePath, char ***tokenDirectory,
		char ***tokens, char *argv, int countExec, char **line)
{
		struct stat buf;

		*executablePath = find_command_in_path(*tokenDirectory,
				*tokens[0]);

		if (*executablePath != NULL)
		{	errno = 0;
			executable_function(*executablePath, *tokens);
			if (errno != 0)
				print_error_not_found(argv, *tokens[0], countExec);
			free(*line);
			free(*tokens);
			*line = NULL;
			*tokens = NULL;
			free(*executablePath);
			*executablePath = NULL;
			return (0); }
		else if (stat(*tokens[0], &buf) == 0)
		{
			errno = 0;
			executable_function(*tokens[0], *tokens);
			if (errno != 0)
				print_error_not_found(argv, *tokens[0], countExec);
			free(*line);
			free(*tokens);
			*line = NULL;
			*tokens = NULL;
			return (1); }
		errno = 0;
		print_error_not_found(argv, *tokens[0], countExec);
		free(*line);
		free(*tokens);
		*line = NULL;
		*tokens = NULL;
		free(*executablePath);
		*executablePath = NULL;
		return (0); }
