#include "shell.h"
/**
 * execute_command - a function that executes executable commands
 * @command: parameter to store built in commands
 * @parameters: parameter to store executable commands
 * Return:void
 */
void execute_command(char *command, char **parameters)
{
	char cmd[100];
	char **env;

	env = environ;
	if (handle_builtins(command, parameters))
		return;

	if (fork() != 0)
		wait(NULL);
	else
	{
		_strcpy(cmd, "/bin/");
		_strcat(cmd, command);
		execve(cmd, parameters, env);

		perror("error");
		exit(1);
	}
}


