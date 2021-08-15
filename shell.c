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


int main(int argc, char **argv, char **env)
{

	char *line = NULL;
	size_t len_line;
	char *prompt = "$ ";
	char *arg[1];
	char *argv2[] = {"/bin/ls", "-l", "/usr/", NULL};


	UNUSED(argc);
	UNUSED(argv);
	UNUSED(env);
	UNUSED(line);
	UNUSED(len_line);
	UNUSED(arg);
	UNUSED(argv2);

	while (1)
	{
		write(1, prompt, strlen(prompt));
		getline(&line, &len_line, stdin);
		deln(line);
		arg[0] = line;

/*		arg[1] = "-l";
		arg[2] = "/usr/";*/
		arg[3] = NULL;

		if(execve(arg[0], arg, NULL) == -1)
		{
			perror("......Error:");
		}
	}


	return (0);
}
