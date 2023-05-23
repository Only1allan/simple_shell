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
	int pid, sig;
	char **env;

	env = environ;

	if (_strcmp(command, "kill") == 0)
	{
		pid = _atoi(parameters[1]);
		sig = _atoi(parameters[2]);
		kill(pid, sig);
		return;
	}

	if (_strcmp(command, "exit") == 0)
	{
		if (parameters[1] == NULL)
			exit(0);
		else
			exit(_atoi(parameters[1]));
	}

	if (_strcmp(command, "env") == 0)
	{
		while (*env != NULL)
		{
			write(STDOUT_FILENO, *env, _strlen(*env));
			write(STDOUT_FILENO, "\n", 1);
			env++;
		}
		return;
	}

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


