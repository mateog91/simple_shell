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
	const char *delim = " \n";
	int sign, flag = 0, (*f)(char *), temp, countExec = 0, flag2 = 0;
	struct stat buf;

	UNUSED(argv);
	while (1)
	{
		countExec++;
/*Prompt*/
		if (isatty(fileno(stdin))){
			write(STDOUT_FILENO, prompt, _strlen(prompt));
		}
/* Get line */
		sign = getline(&line, &len_line, stdin);
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
/* Parse line into tokens*/
		tokens = create_tokens(line, delim);
		assignTokens(line, tokens, delim);
		if (tokens[0] == NULL)
		{
			free(line);
			free(tokens);
			line = NULL;
			tokens = NULL;
			continue;
		}
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
			/*printf("running executable through PATH concatenation\n");*/
			if (executable_function(executablePath, tokens) == -1)
			{
				print_error_not_found(argv[0], tokens[0], countExec, -1);
				flag2 ++;
			}
			free(line);
			free(tokens);
			line = NULL;
			tokens = NULL;
			free(executablePath);
			executablePath = NULL;
			if (flag2)
			{
				flag2 = 0;
				exit(1);
			}
		}
		else if (stat(tokens[0], &buf) == 0)/* is command executable at local file?*/
		{
			printf("I am running executable function \n");

                        if (executable_function(executablePath, tokens) == -1)
                        {
                                print_error_not_found(argv[0], tokens[0], countExec,\
 -1);
                                flag2 ++;
                        }
/*
			executable_function(tokens[0], tokens);
*/
			free(line);
			free(tokens);
			line = NULL;
			tokens = NULL;
                        if (flag2)
                        {
                                flag2 = 0;
                                exit(1);
                        }
			continue;
		}
		else
		{

			/*_puts2(argv[0]); print_number(countExec);*/
			print_error_not_found(argv[0], tokens[0], countExec, 0);
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
