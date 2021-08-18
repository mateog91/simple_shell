#include "shell.h"

/**
 * deln - find a \n char and chage it by NULL
 * @line: pointer to a buffer
 * Return: Nothing - void
 */
void deln(char *line)
{
	int i = 0;

	while (line[i])
	{
		if (line[i] == '\n')
		{
			line[i] = '\0';
			break;
		}
		i++;
	}

}

/**
 *
 */

void printMatrix(char **matrix)
{
	int i = 0;

	while (matrix[i] != NULL)
	{
		printf("Token[%i] is: %s\n", i, matrix[i]);
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
	int i = 0, count_words = 1;

	while (buffer[i] != '\0')
	{
		if (buffer[i] == *delim)
			count_words++;
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
/**
 * main - function that runs a simple shell
 * @argc: Number of arguments gived by user in main shell
 * @argv: params gived by user in main shell
 * @env: Enviroment variables stored like matrix (char **)
 * Return: Always 0;
 */

int main(int argc __attribute__((unused)), char **argv, char **env)
{
	char *line = NULL;
	size_t len_line;
	char *prompt = "$ ";
	pid_t child_pid;
	int status;
	char **tokens = NULL;
	const char *delim = " ";
	int (*f)(char *);
	char *pathPtr = NULL;
	char **tokenDirectory;
	char *executablePath;
	int sign;
	struct stat buf;
	
	
	UNUSED(argv);
	UNUSED(env);
	UNUSED(line);
	UNUSED(len_line);

	while (1)
	{
		/*Prompt*/
		write(STDOUT_FILENO, prompt, _strlen(prompt));
		/* Get line */
		sign = getline(&line, &len_line, stdin);
		if(sign < 0)
			exit(1);
		/* Parse line into tokens*/
		deln(line);
		tokens = create_tokens(line, delim);
		assignTokens(line, tokens, delim);
		/*free(line);*/

		/* Check if command is executable */
		if (stat(tokens[0], &buf) == 0)
		{
			/*Here goes executable function*/
		}

		/* get PATH*/
		pathPtr = _strdup(getPath(env));
		/* Parse PATH */
		tokenDirectory = create_tokens(pathPtr, ":");
		assignTokens(pathPtr, tokenDirectory, ":");
			/*printMatrix(tokenDirectory);
			printf("i am token Directory: %p\n", tokenDirectory[0]);*/

		/* Find not buil-in in PATH */
		/* Concatenate token line with PATH token*/
		executablePath = find_command_in_path(tokenDirectory, tokens[0]);
			/*printf("executablePath is: %p\n", executablePath);
			printf("PATH is %s\n", pathPtr);
			printTokens(pathPtr, ":");
			printf("PATH is %s\n", );*/
		child_pid = fork();
		if (child_pid == -1)
		{
			perror("Error:");
			return (1);
		}
		wait(&status);
		free(pathPtr);

		if (child_pid == 0)
		{
			f = check_built_in(tokens[0]);
			if (f != NULL)
			{
				/*printf("tokens[0]: %s\n", tokens[0]);*/
				f(tokens[0]);
			}
			else
			{
				/*si algo es tokens[0]*/
				if (execve(executablePath, tokens, NULL) == -1)
				{
					perror("Error: ");
				}
			}
		}
	}

	return (0);
}
