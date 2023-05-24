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
	int i;

	env = environ;
	if (handle_builtins(command, parameters))
		return;

	if (strcmp(command, "/bin/ls") == 0)
	{
		pid = fork();
		if (pid == -1)
		{
			perror("fork");
			exit(1);
		}
		else if (pid == 0)
		{
			execve(command, parameters, env);
			perror("error");
			exit(1);
		}
		else
		{
			wait(NULL);
			return;
		}
	}

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
	{
		wait(NULL);
		for (i = 0; parameters[i] != NULL; i++)
			free(parameters[i]);
	}
}


