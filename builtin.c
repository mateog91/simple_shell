#include "shell.h"

/**
 * check_built_in - Check if a string gived is a built in function
 * @str_to_check: Splited buffer whic correspond to position 0
 * Return: status 1 if found 0 if not
 *
 */
int (*check_built_in(custom *bus))(custom *bus)
{
	int i = 0;

	built_in cases[] = {
		{"cd", ls_function},
		{".", ls_function},
		{"env", function_env},
		{"exit", function_exit},
		{NULL, NULL}
	};
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
 * ls_function - function that prints an input string
 * @str: String to print
 * Return: 1 if is executed
 */
int ls_function(custom *bus)
{
	UNUSED(bus);

	/*"%s\n", str);*/
	printf("case cd");
	return (1);
}
/**
 * function_env - function that prints enviorment variables
 * @env: Double pointer to enviormental variables
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
 * @command: Input command from command line
 *
 * Description:
 * It is a help function so that the main knows that it is exit and kills the
 * the process
 *
 * Return: Always 50, a distinctive integer so main functions knows it is exit
 */
int function_exit(custom *bus)
{
	free(bus->line);
	free(bus->tokens);
	exit(EXIT_SUCCESS);
	return (0);
}
