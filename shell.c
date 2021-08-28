#include "shell.h"


/**
 * avoid_signal_stop - stop ^C signal
 * @sig: input required
 *
 * Return: Nothing
 */
static void avoid_signal_stop(int sig)
{
	char *prompt = "\n$ ";

	UNUSED(sig);
	write(STDIN_FILENO, prompt, _strlen(prompt));
}

/**
 * main - function that runs a simple shell
 * @argc: Number of arguments gived by user in main shell
 * @argv: params gived by user in main shell
 * @env_original: Enviroment variables stored like matrix (char **)
 * Return: Always 0;
 */

int main(int argc __attribute__((unused)), char **argv, char **env)
{
	char *line = NULL, *pathPtr = NULL, *prompt = "$ ", *executablePath;
	char **tokens = NULL, **tokenDirectory = NULL;
	size_t len_line;
	const char *delim = " \n\t\r";
	int sign, flag = 0, countExec = 0;
	custom bus = {0};

	signal(SIGINT, avoid_signal_stop);

	test(&bus);
	printf("%i", bus.test_int);
	while (1)
	{
		countExec++;
/*Prompt*/
		if (isatty(fileno(stdin)) != 0)
			write(STDOUT_FILENO, prompt, _strlen(prompt));
/* Get line */
		sign = getline(&line, &len_line, stdin);
		main_get_line(tokenDirectory, tokens, pathPtr, executablePath,
				line, sign, flag);
/* Parse line into tokens*/

		if (main_parse(&tokens, &line, delim) == 1)
			continue;
/* check if is built in*/
		if (main_check_built_in(&tokens, &tokenDirectory, &line,
					&pathPtr, &executablePath, flag) == 1)
			continue;
/* Check if command is executable */
		main_get_path(&pathPtr, env, &tokenDirectory, &flag);
/* Execution */
		if (main_execute(&executablePath, &tokenDirectory, &tokens,
				argv[0], countExec, &line) == 1)
			continue;
	}
	return (0);
}
