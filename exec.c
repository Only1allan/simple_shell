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
	pid_t pid;

	env = environ;

	if (handle_builtins(command, parameters))
		return;

	pid = fork();
	if (pid == -1)
	{
		perror("fork");
		exit(1);
	}
	else if (pid == 0)
	{
		_strcpy(cmd, "/bin/");
		_strcat(cmd, command);
		execve(cmd, parameters, env);

		perror("error");
		exit(1);
	}
	else
		wait(NULL);
}
