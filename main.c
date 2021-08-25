#include "shell.h"

/**
 * main - function that runs a simple shell
 * @argc: Number of arguments gived by user in main shell
 * @argv: params gived by user in main shell
 * @env: Enviroment variables stored like matrix (char **)
 * Return: Always 0;
 */

int main(int argc __attribute__((unused)), char **argv, char **env)
{
	char *line = NULL, *pathPtr = NULL, *prompt = "$ ", *executablePath;
	char **tokens = NULL, **tokenDirectory = NULL;
	size_t len_line;
	const char *delim = " \n\t\r";
	int sign, flag = 0, (*f)(char *), temp, countExec = 0;
	struct stat buf;

	while (1)
	{
		countExec++;
/*Prompt*/
		/*printf("errno before isatty value is: %i\n", errno); */
		if (isatty(fileno(stdin)) != 0)
		{
			write(STDOUT_FILENO, prompt, _strlen(prompt));
		}
/* Get line */
		/*printf("errno after isatty value is: %i\n", errno); */
		sign = getline(&line, &len_line, stdin);
		main_get_line(tokenDirectory, tokens, pathPtr, executablePath, line, sign, flag);
/* Parse line into tokens*/

		if (main_parse(&tokens, &line, delim) == 1)
			continue;
/* check if is built in*/
		f = check_built_in(tokens[0]);
		if (f != NULL)
		{
			if ((temp = f(tokens[0])) == 50)/*Exec & stores retVal*/
			{
				free_exit(tokens, tokenDirectory, line,
					  pathPtr, executablePath, flag); }
			else
			/*	printf("Retorno= %i\n", 1);*/
			free(line);
			free(tokens);
			line = NULL;
			tokens = NULL;
			continue; }

/* Check if command is executable */
/*access(tokens[0], X_OK) == 1)*/
/* Optimization by running this only onces */
		if (flag != 1)
		{
/* get PATH*/
			pathPtr = _strdup(getPath(env));
/* Parse PATH */
			tokenDirectory = create_tokens(pathPtr, ":");
			assignTokens(pathPtr, tokenDirectory, ":");
			flag = 1;
		}
/* Find not buil-in in PATH */
/* Concatenate token line with PATH token*/
		executablePath = find_command_in_path(tokenDirectory, tokens[0]);

		if (executablePath != NULL)
		{
/*Here goes executable function*/
			/*printf("running executable through PATH concatenation\n");*/
			errno = 0;
			executable_function(executablePath, tokens);
			if (errno != 0)
			{
				print_error_not_found(argv[0], tokens[0], countExec);
			}

			free(line);
			free(tokens);
			line = NULL;
			tokens = NULL;
			free(executablePath);
			executablePath = NULL;
		}
		else if (stat(tokens[0], &buf) == 0)/* is command executable at local file?*/
		{
			/*printf("(stat is telling us a 'true')I am running executable function at local dir \n");*/
			errno = 0;
			executable_function(tokens[0], tokens);
			if (errno != 0)
				print_error_not_found(argv[0], tokens[0], countExec);
			free(line);
			free(tokens);
			line = NULL;
			tokens = NULL;
			continue;
		}
		else
		{
			/*printf("Case: not found\n");*/
			errno = 0;
			print_error_not_found(argv[0], tokens[0], countExec);
			free(line);
			free(tokens);
			line = NULL;
			tokens = NULL;
			free(executablePath);
			executablePath = NULL;
		}
	}
	return (0);
}