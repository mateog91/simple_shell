#include "shell.h"

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
 *
 */

char *_strtok(char *str, const char *delim)
{

	int i = 0;
	char *bu, *token = NULL;

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
	{
		token = NULL;
		return (NULL);
	}
	bu = token + i;
	token = bu;
	i = 0;
	while (token[i])
	{
		if (_in(token[i], delim))
			break;
		i++;
	}
	if (token[i])
	{
		token[i] = '\0';
		token = token + i + 1;
		if (!token[0])
			token = NULL;
	}
	else
		token = NULL;
	return (bu);
}
