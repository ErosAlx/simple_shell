#include "hsh.h"

/**
 * main_holder - execute the passed
 * parameter by the main (shell.c)
 * @input: user input
 * @av: executable used to run
 *
 * Return: nothing
 */

void main_holder(char *input, char *av)
{
	char **arr, *tmp_arr;
	int slash_status, builtin_status, command_status;

	arr = _strtok(input, " \t");
	if (arr == NULL)
		return;
	if (arr[0] == NULL)
	{
		free(arr);
		return;
	}

	builtin_status = check_builtin(arr, input);
	if (builtin_status == 1)
	{
		free(arr);
		return;
	}

	command_status = check_command(arr[0]);
	slash_status = _slash(arr[0]);
	if (slash_status == 0 || command_status == 0)
		_exec_command(arr, av);
	else
	{
		tmp_arr = arr[0];
		arr[0] = m_buffer(arr[0]);
		if (arr[0] == NULL)
		{
			prog.status = 127;
			fprintf(stderr, "%s: %d: %s: not found\n",
					prog.name, prog.cmd_count, tmp_arr);
		}
		else
		{
			_exec_command(arr, av);
			free(arr[0]);
		}
	}
	free(arr);
}
