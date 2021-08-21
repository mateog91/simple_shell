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
 * print_number - Function that prints an integer number
 *@n: int to print
 *
 *Return: print
 */

void print_number(int n)
{
unsigned int bu = n;

	if (n < 0)
	{
		_putchar('-');
		bu = bu * -1;
	}

	if ((bu / 10) > 0)
		print_number(bu / 10);
	_putchar((bu % 10) + '0');
}
