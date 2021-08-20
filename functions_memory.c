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
 * free_all - Frees all allocated memory variables
 * @tokens: Matrix with Tokenized line
 * @tokenDirectory: Matrix with Tokenized Path
 * @line: stdio input variable
 * @pathPtr: Copy of Path envirometn variable
 * @executablePath: Path concatenated with command
 * Return: Nothing
 */
void free_all(char **tokens, char **tokenDirectory,
	      char *line, char *pathPtr, char *executablePath)
{
	if (tokens)
	{
		free(tokens);
		tokens = NULL;
	}
	if (tokenDirectory)
	{
		free(tokenDirectory);
		tokenDirectory = NULL;
	}
	if (line)
	{
		free(line);
		line = NULL;
	}
	if (pathPtr)
	{
		free(pathPtr);
		pathPtr = NULL;
	}
	if (executablePath)
	{
		free(executablePath);
		executablePath = NULL;
	}
}
