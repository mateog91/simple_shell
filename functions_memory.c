#include "shell.h"

/**
 * *_realloc - reallocates a memory block using malloc and free
 * @ptr: pointer to the memory previusly allocated
 * @old_size: the size of ptr
 * @new_size: the size of the required pointer
 * Return: pointer with memory allocated
 *
 */

void *_realloc(void *ptr, unsigned int old_size, unsigned int new_size)
{
	char *pointer, *bu = ptr;
	unsigned int aux, i = 0;

	aux = old_size;
	if (new_size > aux)
		aux = old_size;

	if (!ptr)
	{
		pointer = malloc(new_size);
		return (pointer);
	}
	if (new_size == 0)
	{
		free(ptr);
		return (NULL);
	}
	if (new_size == old_size)
		return (ptr);
	pointer = malloc(new_size);
	if (!pointer)
		return (NULL);


	for (i = 0; i < aux; i++)
		pointer[i] = bu[i];
	free(ptr);

	return (pointer);
}
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
	i = 0;
	while ((tokens[i] = strtok(buffer, delim)) != NULL)
	{
		i++;
		buffer = NULL;
	}
	return (tokens);
}
