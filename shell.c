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

	UNUSED(argv);
	UNUSED(len_line);
	UNUSED(sign);

	while (1)
	{
		countExec++;
/*Prompt*/
		if (isatty(fileno(stdin)))
			write(STDOUT_FILENO, prompt, _strlen(prompt));

/* Get line */
		sign = getline(&line, &len_line, stdin);
		printf("sing is: %i\n", sign);
		main_get_line(tokenDirectory, tokens, pathPtr, executablePath, line, sign, flag);
		printf("ejecuto main_get_line\n");
/* Parse line into tokens*/
		tokens = create_tokens(line, delim);
		printf("ejecuto createtokens\n");
		/*
		assignTokens(line, tokens, delim);
		*/
		if (main_parse(&tokens, &line, delim) == 1)
		{
			printf("return is 1\n");
			if (line == NULL)
				printf("line is NULL\n");
			if (tokens == NULL)
				printf("tokens is NULL\n");
			continue;
		}
		printf("main_parse return 0\n");
		/*
		if (tokens[0] == NULL)
		{
			free(line);
			free(tokens);
			line = NULL;
			tokens = NULL;
			continue;
		}
		*/
/* check if is built in*/
		f = check_built_in(tokens[0]);
		if (f != NULL)
		{

			if ((temp = f(tokens[0])) == 50)/*Exec & stores retVal*/
			{
				free_exit(tokens, tokenDirectory, line,
					  pathPtr, executablePath, flag);
			}
			else
				printf("Retorno= %i\n", 1);

			free(line);
			free(tokens);
			line = NULL;
			tokens = NULL;
			continue;
		}

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
			printf("running executable through PATH concatenation\n");
			errno = 0;
			executable_function(executablePath, tokens);
			if (errno != 0)
			{
				print_error_not_found(argv[0], tokens[0], countExec, -1);
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
			printf("(stat is telling us a 'true')I am running executable function at local dir \n");
			executable_function(tokens[0], tokens);
			errno = 0;
			if (errno != 0)
				print_error_not_found(argv[0], tokens[0], countExec, -1);
			free(line);
			free(tokens);
			line = NULL;
			tokens = NULL;
			continue;
		}
		else
		{
			printf("Case: not found\n");
			errno = 0;
			print_error_not_found(argv[0], tokens[0], countExec,0);
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
