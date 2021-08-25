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
	int sign, flag = 0, countExec = 0;

	while (1)
	{
		countExec++;
/*Prompt*/
		if (isatty(fileno(stdin)) != 0)
			write(STDOUT_FILENO, prompt, _strlen(prompt));
/* Get line */
		sign = getline(&line, &len_line, stdin);
		main_get_line(tokenDirectory, tokens, pathPtr, executablePath, line, sign, flag);
/* Parse line into tokens*/

		if (main_parse(&tokens, &line, delim) == 1)
			continue;
/* check if is built in*/
		if (main_check_built_in(&tokens, &tokenDirectory, &line,
					&pathPtr, &executablePath, flag) == 1)
			continue;
/* Check if command is executable */
		main_get_path(&pathPtr, env, &tokenDirectory, &flag);
/* Find not buil-in in PATH */
/* Concatenate token line with PATH token*/

		if (main_execute(&executablePath, &tokenDirectory, &tokens,
				argv[0], countExec, &line) == 1)
			continue;

/*		executablePath = find_command_in_path(tokenDirectory, tokens[0]);

		if (executablePath != NULL)
		{
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
		else if (stat(tokens[0], &buf) == 0)
		{
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
			errno = 0;
			print_error_not_found(argv[0], tokens[0], countExec);
			free(line);
			free(tokens);
			line = NULL;
			tokens = NULL;
			free(executablePath);
			executablePath = NULL;
		}
		*/
	}
	return (0);
}
