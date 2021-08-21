#include "shell.h"

/**
 * copy_enviroment - allocate a copy of a 2 dimentional array
 * @env: 2 dimentional array to copy
 * Return: 2 dimentional array copied
 */

char **copy_enviroment(char **env)
{
	int i = 0;
	char **copy = NULL;

	while (env[i])
		i++;
	i++;
	copy = malloc(sizeof(*env) * i);
	if (!copy)
	{
		perror("Was not possible the allocation");
		exit(1);
	}
	i = 0;
	while (env[i])
	{
		copy[i] = _strdup(env[i]);
		i++;
	}
	copy[i] = NULL;
	return (copy);
}

/**
 * free_matrix - free allocated memory of a two dimentional array
 * @matrix: Two dimentional array to free
 * Return: Nothing
 */
void free_matrix(char **matrix)
{
	int i = 0;

	while (matrix[i])
	{
		free(matrix[i]);
		i++;
	}
	free(matrix);
}
