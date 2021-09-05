#include "shell.h"

/**
 * check_built_in - Check if a string gived is a built in function
 * @bus: bus of data to processing
 * Return: status 1 if found 0 if not
 *
 */
int (*check_built_in(custom * bus))(custom * bus)
{
	int i = 0;

	built_in cases[] = {
		{"env", function_env},
		{"exit", function_exit},
		{NULL, NULL}};
	while (cases[i].function_name != NULL)
	{
		if (_strcmp(cases[i].function_name, bus->tokens[0]) == 0)
			break;
		i++;
	}
	/*executing if found*/
	if (cases[i].f != NULL)
		cases[i].f(bus);
	return (cases[i].f);
}

/**
 * function_env - function that prints enviorment variables
 * @bus: bus of data to processing
 *
 * Return: 1 if success
 */
int function_env(custom *bus)
{
	printMatrix(bus->env);
	return (0);
}
/**
 * function_exit - function for built in exit
 * @bus: bus of data to processing
 * Description:
 * It is a help function so that the main knows that it is exit and kills the
 * the process
 *
 * Return: Always 0
 */
int function_exit(custom *bus)
{
	if (bus->need_to_exit == 0) /* Is built in*/
	{
		if (bus->tokens[1] != NULL)
		{
			bus->status = _atoi(bus->tokens[1]);
			if (bus->status < 0)
			{
				bus->status = 2;
				print_error_not_found(bus, ": Illegal number: ", 2);
				_puts(bus->tokens[1]);
			}
		}
		free(bus->line);
		free(bus->tokens);
	}
	exit(bus->status);
	return (0);
}
