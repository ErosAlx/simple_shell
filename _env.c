#include "hsh.h"

/**
 * print_str - printing a string
 * @str: string input
 *
 * Return : nothing
 */

void print_str(char *str)
{
	int i = 0;
	char car;

	while (str[i])
	{
		car = str[i];
		write(1, &car, 1);
		i++;
	}
	write(1, "\n", 1);
}

/**
 * print_env - printing the env
 * @arr: array input
 *
 * Return: nothing
 */

int print_env(char **arr)
{
	int i = 0;

	if (arr[1] != NULL)
		return (0);

	while (environ[i] != NULL)
	{
		print_str(environ[i]);
		i++;
	}
	return (1);
}
