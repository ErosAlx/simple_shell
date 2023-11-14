#include "hsh.h"

/**
 * _strtok - split line (commands) with delim
 * @input: line (commands) entered by user
 * @delim: delimiter (" \t")
 *
 * Return: commands
 */

char **_strtok(char *input, char *delim)
{
	char **arr;
	char *token;
	char *tmp_str;
	int counter;
	int i;

	tmp_str = strdup(input);
	token = strtok(tmp_str, delim);
	counter = 0;
	while (token)
	{
		counter++;
		token = strtok(NULL, delim);
	}
	arr = malloc(sizeof(char *) * (counter + 1));
	if (arr == NULL)
		return (NULL);

	i = 0;
	token = strtok(input, delim);
	while (token)
	{
		arr[i] = token;
		token = strtok(NULL, delim);
		i++;
	}
	arr[i] = NULL;
	free(tmp_str);
	return (arr);
}
