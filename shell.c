#include "shell.h"


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
	printf("count is %i\n", count);
	tokens[count] = NULL;
}
char **creat_tokens(char *buffer, const char *delim)
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




int main(int argc, char **argv, char **env)
{
	char *line = NULL;
	size_t len_line;
	char *prompt = "$ ";
	char *arg[1];
	pid_t child_pid;
	int status;
	char **tokens = NULL;
	const char *delim = " ";

	UNUSED(argc);
	UNUSED(argv);
	UNUSED(env);
	UNUSED(line);
	UNUSED(len_line);
	UNUSED(arg);

	while (1)
	{
		write(1, prompt, strlen(prompt));
		getline(&line, &len_line, stdin);
		deln(line);
		tokens = creat_tokens(line, delim);
		
		assignTokens(line, tokens, delim);
		arg[0] = line;
		arg[1] = NULL;
		
		child_pid = fork();
		if (child_pid == -1)
		{
			perror("Error:");
			return (1);
		}
		wait(&status);
		if (child_pid == 0)
		{
			if(execve(tokens[0], tokens, NULL) == -1)
			{
				perror("......Error:");
			}
		}
	}


	return (0);
}
