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
#include <stddef.h>

#define UNUSED(x) (void)(x)

/**
 * struct variables - struct to store variables used in the shell project
 * @arguments: argv get in the main
 * @tokenDirectory: matrix to store a tokenized path
 * @tokens: matrix to store a tokenized command input
 * @line: command gived by the user
 * @sign: variable used to check status of line
 * @env: variable to store enviroment matrix getting in main
 * @execution_number: number that represent the number of interactions
 * taken in the shell execution
 * @status: Possible status to use with exit function
 * @need_to_exit: variable that inform if is necessary kill a child process
 * in an abnormal way
 **/
typedef struct variables
{
	char **arguments;
	char **tokenDirectory;
	char **tokens;
	char *line;
	int sign;
	char **env;
	int execution_number;
	int status;
	int need_to_exit;
} custom;
/**
 * struct functions - struct to compute buitl in functions
 * @function_name: Name of the function
 * @f: Function to execute
 */

typedef struct functions
{
	char *function_name;
	int (*f)(custom *);

} built_in;

/* main functions */
void main_get_line(custom *bus);

/* Execution functions */
int executable_function(custom *bus, int selected, char *buffer);
int execution_not_dir(custom *bus);

/* Path functions */
char *getPath(custom *bus);
char *find_command_in_path(char **PATH, char *command);
int is_dir(custom *bus);
int exist_dir(char *str);

/* advanced functions */
int _in(char c, const char *str);
char *_strtok(char *str, const char *delim);

/* Built in functions*/
int (*check_built_in(custom *bus))(custom *bus);
int function_env(custom *bus);
int function_exit(custom *bus);

/* Manage memory functions */
void *_realloc(void *ptr, unsigned int old_size, unsigned int new_size);
char **copy_enviroment(char **env);
void free_matrix(char **matrix);

/* Print Functions*/
int _putchar(char c);
void _puts(char *str);
void _puts2(char *str);
void print_number(int n);

/* String basic functions  */
int _strcmp(char *s1, char *s2);
int _strlen(char *str);

/* Errors print functions*/

void print_error_not_found(custom *bus, char *custom_error);

/* String Malloc functions */
char *str_concat(char *s1, char *s2);
char *_strdup(char *str);

/* Functions that were in main */
void printMatrix(char **matrix);
char **create_tokens(char *buffer, const char *delim);

#endif /* _SHELL_H_ */
