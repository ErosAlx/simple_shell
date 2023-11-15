#include "hsh.h"

/**
 * check_builtin - checks for "env" "exit" builtin commands
 * @arr: array input.
 * @input: user input
 *
 * Return: returs 0 if "env", call exit_q() in  "exit"
 */

int check_builtin(char **arr, char *input)
{
	if (strcmp(arr[0], "exit") == 0)
	{
		exit_q(arr, input);
		return (1);
	}
	else if (strcmp(arr[0], "env") == 0)
		return (print_env(arr));
	return (0);
}
