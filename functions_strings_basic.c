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
 * _in - Check if a char is in a string
 * @c: Char to check
 * @str: string to look into
 * Return: 1 if match, 0 if not match
 */
int _in(char c, const char *str)
{
	int i = 0;

	while (str[i])
	{
		if (str[i] == c)
			return (1);
		i++;
	}
	return (0);
}

/**
 * _strtok - Making a strtok including handle
 * of #
 * @str: String to create tokens
 * @delim: Delim to use with str
 * Return: If delim succed A token at right
 * if not succed a NULL
 */

char *_strtok(char *str, const char *delim)
{
	int i = 0;
	char *bu, *token;

	if (str)
		token = str;
	bu = token;
	if (!bu)
		return (NULL);
	while (token[i])
	{
		if (!_in(token[i], delim))
			break;
		i++;
	}
	if (!token[i] || token[i] == 35)
	{/* Case never found delim*/
		token = NULL;
		return (NULL);
	}
/* Case found: point to next position of char found*/
	bu = token + i;
	token = bu;
	i = 0;
	while (token[i])
	{
		if (_in(token[i], delim))
			break;
		i++;
	}
	if (token[i]) /* In a second match set null */
	{ /* The other part will be resolve with a second strtok*/
		token[i] = '\0';
		token = token + i + 1;/* Input string ends after the null*/
		if (!token[0])
			token = NULL;
	}
	else
		token = NULL; /* Reach null byte */
	return (bu);
}
