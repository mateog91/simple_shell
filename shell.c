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
	int sign, flag = 0, (*f)(char *);
	struct stat buf;

	setenv("PRUEBA", "CONTENIDO0", 0);
	setenv("PRUEBA", "CONTENIDO1", 1);
	setenv("PRUEBA", "CONTENIDO2", 0);
	setenv("PRUEBA1", "CONTENIDO1", 1);

	UNUSED(argv);
	while (1)
	{
/*Prompt*/
		write(STDOUT_FILENO, prompt, _strlen(prompt));
/* Get line */
		sign = getline(&line, &len_line, stdin);
		if (sign < 0)
		{
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
			f(tokens[0]);
			free(line);
			free(tokens);
			line = NULL;
			tokens = NULL;
			continue;
		}

/* Check if command is executable */
		/*	if (stat(tokens[0], &buf) == 0 && access(tokens[0], X_OK) == 1)*/
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
			executable_function(executablePath, tokens);
			free(line);
			free(tokens);
			line = NULL;
			tokens = NULL;
			free(executablePath);
			executablePath = NULL;
		}
		else if (stat(tokens[0], &buf) == 0)
		{

/*Here goes executable function*/
			printf("I am running executable function \n");
			executable_function(tokens[0], tokens);
			free(line);
			free(tokens);
			line = NULL;
			tokens = NULL;
			continue;
		}
		else
		{
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
