#include "shell.h"

/**
 * print_error_not_found - Handle the printing errors
 * @bus: bus of data to process
 * @custom_error: error to print in specific situations
 * Return: Void
 */

void print_error_not_found(custom *bus, char *custom_error)
{

	_puts2(bus->arguments[0]);
	_puts2(": ");
	print_number(bus->execution_number);
	_puts2(": ");
	_puts2(bus->tokens[0]);
	if (custom_error == NULL)
	{
		perror(": ");
	}
	else
		_puts(custom_error);

}
