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
 custom bus = {0, NULL, NULL, NULL, NULL, NULL, 0, 0, NULL, 0};

(void)argv;
	signal(SIGINT, avoid_signal_stop);
	bus.env = env;

	while (1)
	{
		bus.execution_number++;
/*Prompt.*/
		if (isatty(fileno(stdin)) != 0)
			write(STDOUT_FILENO, prompt, _strlen(prompt));
/* Get line */
		bus.sign = getline(&(bus.line), &len_line, stdin);
		main_get_line(&bus);
		bus.tokens = create_tokens(bus.line, " \n\t\r");

		printf("%s\n", bus.tokens[1]);
		
	}
	return (0);
}

