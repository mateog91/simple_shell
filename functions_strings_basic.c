#include "shell.h"

/**
 * _putchar - writes the character c to stdout
 * @c: The character to print
 *
 * Return: On success 1.
 * On error, -1 is returned, and errno is set appropriately.
 */
int _putchar(char c)
{
	return (write(1, &c, 1));
}


/**
 * _puts - prints a string followed by a new line
 * @str: - pointer to first character of string
 *
 */
void _puts(char *str)
{
	int i;

	for (i = 0; str[i] != '\0'; i++)
		_putchar(str[i]);
	_putchar('\n');
}


/**
 * *_strcmp - compare two strings
 *@s1: pointer 1
 *@s2: pointer 2
 *Return: An integer != 0 if not equal
 */
int _strcmp(char *s1, char *s2)
{
	int i = 0;

	while (*(s1 + i) && *(s2 + i))
	{
		if (s1[i] != s2[i])
			break;
		i++;
	}
	return (s1[i] - s2[i]);
}

/**
 * _strlen - calculate the lenght of a input string
 * @str: pointer string to compute lenght
 * Return: lenght of the string
 */
int _strlen(char *str)
{
	int i = 0;

	while (str[i])
		i++;

	return (i);
}
