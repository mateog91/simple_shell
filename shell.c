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
	char *line = NULL;
	size_t len_line;
	char *prompt = "$ ";
	char **tokens = NULL;
	const char *delim = " \n";
	int (*f)(char *);
	char *pathPtr = NULL;
	char **tokenDirectory;
	char *executablePath;
	int sign;
	struct stat buf;
	int flag = 0;

	UNUSED(argv);
	UNUSED(env);
	UNUSED(line);
	UNUSED(len_line);

	while (1)
	{
		/*Prompt*/
		write(STDOUT_FILENO, prompt, _strlen(prompt));
		/* Get line */
		sign = getline(&line, &len_line, stdin);
		if (sign < 0)
			exit(1);
		tokens = create_tokens(line, delim);
		assignTokens(line, tokens, delim);

		if (!tokens[0])
		{
			free(line);
			free(tokens);
			continue;
		}
		/* check if is built in*/
		f = check_built_in(tokens[0]);
		if (f != NULL)
		{
			f(tokens[0]);
			continue;
		}
		/* Check if command is executable */
		if (stat(tokens[0], &buf) == 0)
		{
			/*Here goes executable function*/
			printf("I am running executable function \n");
			executable_function(tokens[0], tokens);
			continue;
		}
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
		/* Concatenate token line with PATH token */
		executablePath = find_command_in_path(tokenDirectory, tokens[0]);
		/* Check if */

		if (executablePath != NULL)
		{
			/*Here goes executable function*/
			printf("running executable through PATH concatenation\n");
			executable_function(executablePath, tokens);
		}
	}
	return (0);
}
