#include "shell.h"

int main(int argc, char **args, char **argenv)
{
	int i = 0;
	char *token;
	char *DELIM = " ";

	UNUSED(argc);
	UNUSED(args);
	UNUSED(argenv);

	/* Printing args like they are passed by*/
	while (args[i])
	{
		printf("%s\n", args[i]);
		i++;
	}

	

	return (0);
}
