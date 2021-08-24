#include "shell.h"

/**
 *
 */

void print_error_not_found(char *argv0, char *tokens0, int countExec, int return_error)
{
	UNUSED(return_error);
	_puts2(argv0);
	_puts2(": ");
	print_number(countExec);
	_puts2(": ");
	_puts2(tokens0);

	if (errno != 0)
	{
		perror("");
		errno = 0;
		exit(1);
	}
	else
		puts(": not found");
}
