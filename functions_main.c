#include "shell.h"
/**
 * main_get_line - resolves what to be done with line and frees accordingly
 * @bus: bus of data to process
 * Description:
 * Handles what to be done after getline is executed
 * If sign is < 0 means a signal of end of file is found
 * With this, it frees the functions accordingly
 *
 * Returns: Nothing
 */
void main_get_line(custom *bus)
{
	if (bus->sign < 0) /* Is EOF ?*/
	{
		if (errno != 0)
			perror("");
		else if (bus->sign == EOF) /*CTRL ^ d event*/
			_putchar('\n');
		free(bus->line);
		exit(EXIT_SUCCESS);
	}
}
