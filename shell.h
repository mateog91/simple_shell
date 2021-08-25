#ifndef _SHELL_H_
#define _SHELL_H_

extern char **environ;

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <sys/wait.h>
#include <limits.h>
#include <signal.h>
#include <errno.h>

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

/* main functions */
void main_get_line(char **tokenDirectory, char **tokens, char *pathPtr,
		   char *executablePath, char *line, int sign, int flag);
int main_parse(char ***Dtokens, char **Dline, const char *delim);
int main_check_built_in(char ***tokens, char ***tokenDirectory, char **line,
			char **pathPtr, char **executablePath, int flag);

/* function others */
int (*check_built_in(char *str_to_check))(char *);

char *getPath(char **env);
char *find_command_in_path(char **PATH, char *command);
int executable_function(char *command, char **tokens);

/* Built in functions*/
int ls_function(char *str);
int function_env(char *env);
int function_exit(char *command);

/* Manage memory functions */
void *_realloc(void *ptr, unsigned int old_size, unsigned int new_size);
void free_all(char **tokens, char **tokenDirectory,
	      char *line, char *pathPtr, char *executablePath);
char **copy_enviroment(char **env);
void free_matrix(char **matrix);
void free_exit(char **tokens, char **tokenDirectory, char *line,
	       char *pathPtr, char *executablePath, int flag);

/* Print Functions*/
int _putchar(char c);
void _puts(char *str);
void _puts2(char *str);
void print_number(int n);

/* String basic functions  */
int _strcmp(char *s1, char *s2);
int _strlen(char *str);

/* Errors print functions*/

void print_error_not_found(char *argv0, char *tokens0, int countExec);

/* String Malloc functions */
char *str_concat(char *s1, char *s2);
char *_strdup(char *str);

/* Functions that were in main */
void printMatrix(char **matrix);
void assignTokens(char *lineReaded, char **tokens, const char *delim);
char **create_tokens(char *buffer, const char *delim);

#endif /* _SHELL_H_ */
