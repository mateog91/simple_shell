#ifndef _SHELL_H_
#define _SHELL_H_

/* Compiling an executing program by:*/
/* gcc -Wall -Werror -Wextra -pedantic -std=gnu89 *.c -o hsh && ./hsh*/
/*  valgrind --tool=memcheck --vgdb=yes --vgdb-error=0 ./prog */
/* valgrind --leak-check=full --track-origins=yes --show-leak-kinds=all */

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <sys/wait.h>
#include <limits.h>
#include <signal.h>

#define UNUSED(x) (void)(x)

/**
 * struct functions - struct to compute buitl in functions
 * @function_name: Name of the function
 * @f: Function to execute
 */

typedef struct functions
{
	char *function_name;
	int (*f)(char *);

} built_in;

int (*check_built_in(char *str_to_check))(char *);

int ls_function(char *str);
char *getPath(char **env);
char *find_command_in_path(char **PATH, char *command);
/* String operation functions  */
int _strcmp(char *s1, char *s2);
int _strlen(char *str);
char *str_concat(char *s1, char *s2);

#endif /* _SHELL_H_ */
