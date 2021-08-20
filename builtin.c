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
		{"cd", ls_function},
		{".", ls_function},
		{"env", function_env},
		{NULL, NULL}
	};

	while (cases[i].function_name != NULL)
	{
		if (_strcmp(cases[i].function_name, str_to_check) == 0)
			break;
		i++;
	}

	return (cases[i].f);

}

/**
 * ls_function - function that prints an input string
 * @str: String to print
 * Return: 1 if is executed
 */
int ls_function(char *str)
{
	printf("%s\n", str);

	return (1);
}
/**
 * function_env - function that prints enviorment variables
 * @env: Double pointer to enviormental variables
 *
 * Return: 1 if success
 */
int function_env(**env)
{
	printMatrix(env);
	return (1);
}
