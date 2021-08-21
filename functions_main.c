#include "shell.h"

/**
 * printMatrix - Print element by element in a gived Matrix
 * @matrix: Memory Address of a matrix
 * Return: Void
 */

void printMatrix(char **matrix)
{
	int i = 0;

	while (matrix[i] != NULL)
	{
		_puts(matrix[i]);
		i++;
	}
}
/**
 * assignTokens - Function that fill a **char with a parse resource
 * @lineReaded: Buffer readed by stdi
 * @tokens: **char to fill
 * @delim: Delim of the function
 * Return: Nothing - void
 */
void assignTokens(char *lineReaded, char **tokens, const char *delim)
{
	char *token = NULL;
	int count = 0;

	token = strtok(lineReaded, delim);
	tokens[count] = token;
	while (token != NULL)
	{
		count++;
		token = strtok(NULL, delim);
		tokens[count] = token;
	}
	tokens[count] = NULL;
}
/**
 * **create_tokens - use memory dinamicly to create an empty **char
 * @buffer: Buffer used to create tokens
 * @delim: Delim of the function
 * Return: empty matrix where will be store parse data
 */
char **create_tokens(char *buffer, const char *delim)
{
	char **tokens = NULL;
	int i = 0, j = 0, count_words = 1;

	if (buffer == NULL)
		return (NULL);

	while (buffer[i] != '\0')
	{
		while (delim[j] != '\0')
		{
			if (buffer[i] == delim[j])
				count_words++;
			j++;
		}
		j = 0;
		i++;
	}
	tokens = malloc(sizeof(buffer) * (count_words + 1));
	if (tokens == NULL)
	{
		perror("Error: tokens not created");
		return (NULL);
	}
	return (tokens);
}
