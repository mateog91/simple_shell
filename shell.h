#ifndef _SHELL_H_
#define _SHELL_H_

/* Compiling an executing program by:*/
/* alias shell="gcc -Wall -Werror -Wextra -pedantic -std=gnu89 *.c -o hsh && ./hsh" */
/*  valgrind --tool=memcheck --vgdb=yes --vgdb-error=0 ./prog */
/* alias valgr="valgrind --leak-check=full --track-origins=yes --show-leak-kinds=all ./hsh" */

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
	int (*f)(char *, char *, char **);

} built_in;

extern char **environ;

int (*check_built_in(char *str_to_check))(char *, char *, char **);

char *getPath(char **env);
char *find_command_in_path(char **PATH, char *command);
int executable_function(char *command, char **tokens);

/* Built in functions*/
int ls_function(char *str, char *line, char **tokens);
int function_env(char *env, char *line, char **tokens);
int function_exit(char *command, char *line, char **tokens);

/* Manage memory functions */
void *_realloc(void *ptr, unsigned int old_size, unsigned int new_size);
void free_all(char **tokens, char **tokenDirectory,
              char *line, char *pathPtr, char *executablePath);
char **copy_enviroment(char **env);
void free_matrix(char **matrix);

/* String operation functions  */
int _strcmp(char *s1, char *s2);
int _strlen(char *str);
char *str_concat(char *s1, char *s2);
char *_strdup(char *str);

/* Functions that were in main */
void deln(char *line);
void printMatrix(char **matrix);
void assignTokens(char *lineReaded, char **tokens, const char *delim);
char **create_tokens(char *buffer, const char *delim);

#endif /* _SHELL_H_ */
