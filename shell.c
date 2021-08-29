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
	/*
	char *line = NULL, *pathPtr = NULL, *prompt = "$ ", *executablePath;
	char **tokens = NULL, **tokenDirectory = NULL;
	size_t len_line;
	const char *delim = " \n\t\r";
	int sign, flag = 0, countExec = 0, counter = 0;
*/
	char *prompt = "$ ";
	size_t len_line;
	custom bus = {NULL, NULL, NULL, NULL, NULL, NULL, 0, 0, NULL, 0, 0};
	int need_to_exit = 0;

	signal(SIGINT, avoid_signal_stop);
	bus.env = env;
	bus.arguments = argv;
	while (1)
	{
		bus.execution_number++;
		/*Prompt.*/
		if (isatty(fileno(stdin)) != 0)
			write(STDOUT_FILENO, prompt, _strlen(prompt));
		/* Get line */
		errno = 0;
		bus.sign = getline(&(bus.line), &len_line, stdin);
		main_get_line(&bus);
		bus.tokens = create_tokens(bus.line, " \n\t\r");
		if (bus.tokens != NULL && bus.tokens[0] != NULL)
		{
			/* built in functions*/
			if (check_built_in(&bus) == NULL)
				need_to_exit = executable_function(&bus);
		}
		/* Free */
		free(bus.line);
		free(bus.tokens);
		bus.line = NULL;
		bus.tokens = NULL;
		if (need_to_exit == 1)
			exit(bus.status);
	}
	return (0);
}
