#ifndef _SHELL_H_
#define _SHELL_H_


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


#endif /* _SHELL_H_ */
