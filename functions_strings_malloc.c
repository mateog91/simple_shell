#include "shell.h"

/**
 * str_concat - function that concatenates two strings.
 * @s1: Input string 1.
 * @s2: Input string 2.
 *
 * Description:
 * The returned pointer should point to a newly allocated space in
 * memory which contains the contents of s1, followed by the contents
 * of s2, and null terminated.
 * If passed NULL treat as empty string.
 *
 * Return:
 * NULL on failure.
 * On succes, pointer to new allocated string.
 */
char *str_concat(char *s1, char *s2)
{
	int size, i, j;
	char *ptr;

	if (s1 == NULL)
		s1 = "";
	if (s2 == NULL)
		s2 = "";

	/* Recorrer s1 y s2 y calcular tamaño total */
	for (i = 0; s1[i]; i++)
		;
	size = i;

	for (i = 0; s2[i]; i++)
		;
	size = size + i + 1;

	/* Allocate memory for new string */
	ptr = malloc(sizeof(char) * size);
		if (ptr == NULL)
			return (NULL);

	/* Recorrer s1 y pegar en ptr */
	j = 0;
	for (i = 0; s1[i]; i++)
	{
		ptr[i] = s1[i];
	}

	/* Recorrer s2 y pegar desde final de s1 en ptr hasta final de s2*/
	for (j = 0; s2[j]; j++)
	{
		ptr[i] = s2[j];
		i++;
	}
	ptr[i] = '\0';

	return (ptr);
}

/**
 * _strdup - function that returns a pointer to a newly allocated space in
 * memory,which contains a copy of the string given as a parameter.
 * @str: pointer to input string to be copied.
 *
 * Description:
 * The _strdup() function returns a pointer to a new string which is a
 * duplicate of the string str. Memory for the new string is obtained with
 * malloc, and can be freed with free.
 *
 * Return:
 * NULL if 1) str == NULL 2) Insufficient memory was available
 * On success returns pointer to new duplicate of input string.
 */
char *_strdup(char *str)
{
	int i, size;
	char *ptr;

	/* Check if input string is NULL */
	if (str == NULL)
		return (NULL);

	/* Find size of input string */
	for (size = 0; str[size] != '\0'; size++)
	{
	}

	/* Allocate memory for new string */
	ptr = malloc(sizeof(*str) * size + 1);
	if (ptr == NULL)
		return (NULL);

	/* Copy input string to new string */
	for (i = 0; i <= size; i++)
	{
		ptr[i] = str[i];
	}

	return (ptr);

}
