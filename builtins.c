#include "shell.h"
/**
 * handle_builtins - a function that handles built in commands
 * @command: parameter to store builtins
 * @parameters: parameter to store executable commands
 * Return: 1 if command is a built in otherwise 0
*/
int handle_builtins(char *command, char **parameters)
{
	int ret;
	pid_t pid;
	char **env;

	env = environ;
	if (_strcmp(command, "/bin/ls") == 0)
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
			return(0);
		}
	}
	if (_strcmp(command, "exit") == 0)
	{
		if (parameters[1] == NULL)
			exit(0);
		else
			exit(_atoi(parameters[1]));
	}
	if (_strcmp(command, "cd") == 0)
	{
		if (parameters[1] != NULL)
			ret = chdir(parameters[1]);
		else
			ret = chdir(getenv("HOME"));
		if (ret != 0)
			perror("error");

		return (1);
	}
	return (0);
}

