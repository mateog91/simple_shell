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
 * @env: Enviroment variables stored like matrix (char **)
 * Return: Always 0;
 */

int main(int argc __attribute__((unused)), char **argv, char **env)
{
	char *prompt = "$ ";
	size_t len_line;
	custom bus = {NULL, NULL, NULL, 0, NULL, 0, 0, 0, 0};

	signal(SIGINT, avoid_signal_stop);
	bus.env = env;
	bus.arguments = argv;

	while (1)
	{
		bus.execution_number++;
		if (isatty(fileno(stdin)) != 0)
		{
			bus.interactive = 1;
			write(STDOUT_FILENO, prompt, _strlen(prompt));
		}
		errno = 0;
		bus.sign = getline(&(bus.line), &len_line, stdin);
		main_get_line(&bus);
		bus.tokens = create_tokens(bus.line, " \n\t\r");
		if (bus.tokens != NULL && bus.tokens[0] != NULL)
		{
			if (check_built_in(&bus) == NULL)
			{
				if (is_dir(&bus) == 1)
					executable_function(&bus, 1, "nothing");
				else
					execution_not_dir(&bus);
			}
		}
		free(bus.line);
		free(bus.tokens);
		bus.line = NULL;
		bus.tokens = NULL;
		if (bus.need_to_exit == 1)
			function_exit(&bus);
	}
	return (0);
}
