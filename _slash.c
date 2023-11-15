#include "hsh.h"

/**
 * _slash - check for '/' in line
 * @executable: commands entered
 *
 * Return: 0 if slash in line, else return -1
 */

int _slash(char *executable)
{
	int i = 0;

	while (executable[i])
	{
		if (executable[i] == '/')
			return (0);
		i++;
	}
	return (-1);
}
