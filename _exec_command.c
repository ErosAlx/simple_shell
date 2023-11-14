#include "hsh.h"

/**
 * _exec_command - executes a given command
 * @arr: input array
 * @av: the passed argv value
 *
 * Return: nothing
 */

void _exec_command(char **arr, char *av)
{
	int w_status;
	pid_t child_pid;

	child_pid = fork();
	if (child_pid < 0)
		perror("Error");
	else if (child_pid == 0)
	{
		prog.status = 0;
		execve(arr[0], arr, environ);
		perror(av);
		exit(0);
	}
	else
	{
		wait(&w_status);
		if (WIFEXITED(w_status) != 0)
			prog.status = WEXITSTATUS(w_status);
	}
}
