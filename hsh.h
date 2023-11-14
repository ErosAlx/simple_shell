#ifndef HSH_H
#define HSH_H

#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <sys/wait.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include <signal.h>

extern char **environ;

/**
 * struct hsh_status - holds information about a command, including its name,
 * command count, and status.
 * @name: pointer takes input from argv
 * @cmd_count: int command counter
 * @status: int status
 */

struct hsh_status
{
	char *name;
	int cmd_count;
	int status;
};
typedef struct hsh_status hsh_t;
extern hsh_t prog;

void main_holder(char *input, char *av);
char **_strtok(char *input, char *delim);
void _exec_command(char **arr, char *av);
void print_str(char *str);
int exit_q(char **arr, char *input);
char *_path(char *name);
int check_command(char *executable);
int check_builtin(char **arr, char *input);
int _slash(char *executable);
int print_env(char **arr);
char *m_buffer(char *command);

#endif
