#include "hsh.h"

/**
 * _path - path value from the env.
 * @name: path name.
 *
 * Return: line value where variable exist
 */

char *_path(char *name)
{
	size_t size;
	int i = 0;

	size = strlen(name);
	while (environ[i])
	{
		if (strncmp(environ[i], name, size) == 0)
			return (environ[i] + size + 1);
		i++;
	}
	return (NULL);
}
