#include "hsh.h"
/**
 * m_buffer - modifies buffer to the newelly
 * assigned executable
 * @command: executable
 *
 * Return: the folder where command was found in, else returns null
 */

char *m_buffer(char *command)
{
	char path_v[1024];
	char **buf;
	int i = 0, len, buf_len;
	char *tmp_arr;

	tmp_arr = _path("PATH");
	if (tmp_arr == NULL)
		return (NULL);
	strcpy(path_v, tmp_arr);
	buf = _strtok(path_v, ":");

	len = strlen(command);
	while (buf[i])
	{
		buf_len = strlen(buf[i]);
		tmp_arr = malloc(sizeof(char) * (buf_len + len + 2));
		strcpy(tmp_arr, buf[i]);
		strcat(tmp_arr, "/");
		strcat(tmp_arr, command);
		if (check_command(tmp_arr) == 0)
		{
			free(buf);
			return (tmp_arr);
		}
		free(tmp_arr);
		i++;
	}
	free(buf);
	return (NULL);
}
