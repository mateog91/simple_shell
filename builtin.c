#include "shell.h"

/**
 * check_built_in - Check if a string gived is a built in function
 * @str_to_check: Splited buffer whic correspond to position 0
 * Return: status 1 if found 0 if not
 *
 */
int (*check_built_in(char *str_to_check))(char *str_to_check)
{
	int i = 0;

	built_in cases[] = {
		{ls, ls_function},
		{NULL, NULL}
	}

		while (cases[i].function_name)
		{
			if (*(cases[i].function_name) == *str_to_check)
				break;
			i++;
		}

	return (cases[i].f);

}
