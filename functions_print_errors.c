#include "shell.h"

/**
 * print_error_not_found - Handle the printing errors
 * @argv0: Input to thhe executable file
 * @tokens0: Command typed by the user
 * @countExec: Int that describe number of times execute the loop
 */

void print_error_not_found(char *argv0, char *tokens0, int countExec)
{

	_puts2(argv0);
	_puts2(": ");
	print_number(countExec);
	_puts2(": ");
	_puts2(tokens0);
	if (errno != 0)
	{
		/*printf("errno value is: %i\n", errno);*/
		_puts2(": ");
		perror("");
		errno = 0;
		exit(EXIT_FAILURE);
	}
	else
		puts(": not found");
}
