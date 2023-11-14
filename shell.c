#include "hsh.h"
#include "global_var.h"
/**
 * main - the entry point.
 * @argc: the argument counter.
 * @argv: the argument vector.
 *
 * Return: exit_success in case of success, -1 otherwise.
 */

int main(int argc __attribute__ ((unused)), char **argv)
{
	char *input = NULL;
	size_t len = 0;
	ssize_t n;

	prog.name = argv[0];

	while (1)
	{
		if (isatty(STDIN_FILENO))
			write(1, "$ ", 2);
		n = getline(&input, &len, stdin);
		prog.cmd_count++;
		if (n < 1)
		{
			if (isatty(STDIN_FILENO))
				write(1, "\n", 1);
			free(input);
			exit(prog.status);
		}
		input[n - 1] = '\0';
		main_holder(input, argv[0]);
	}
}
