#include "hsh.h"
#include <ctype.h>

/**
 * exit_q - exit
 * @arr: array holder.
 * @input: user input.
 *
 * Return: int by exiting (SUCCESS).
 */

int exit_q(char **arr, char *input)
{
	int index;
	char *tmp_arr;

	if (arr[1] == NULL)
	{
		free(input);
		free(arr);
		_exit(prog.status);
	}

	tmp_arr = arr[1];
	for (index = 0; tmp_arr[index] != '\0'; index++)
	{
		if (isdigit(tmp_arr[index]) == 0)
		{
			fprintf(stderr, "%s: %d: exit: Illegal number: %s\n",
					prog.name, prog.cmd_count, tmp_arr);
			prog.status = 2;
			return (1);
		}
	}
	prog.status = atoi(arr[1]);
	free(input);
	free(arr);
	_exit(prog.status);
}
