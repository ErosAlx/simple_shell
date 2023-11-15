#include "hsh.h"

/**
 * check_command - checks if command available
 * @command: the executable
 *
 * Return: returns the path if the executable is found, else returns NULL
 */
int check_command(char *command)
{
	struct stat status;

	return (stat(command, &status));
}
