#include "shell.h"

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

/**
 *_atoi - convert a string to an integer.
 *@s: string to be converted
 *
 *Return: integer
 */

int _atoi(char *s)
{
	int i = 0, j = 0, output = 0, sign = 1;

	/* Working with the sign */
	while ((s[j] < '0' || s[j] > '9') && (s[j] != '\0')) /*not number*/
	{
		if (s[j] == '-')
			sign = sign * -1;
		j++;
	}
	i = j; /* Saving the loop position */
	while ((s[i] >= '0') && (s[i] <= '9')) /*output depends of itself*/
	{
		output = 10 * output + (s[i] - '0') * sign;
		i++;
	}
	return (output);
}
