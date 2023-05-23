#include "shell.h"
/**
 * handle_builtins - a function that handles built in commands
 * @command: parameter to store builtins
 * @parameters: parameter to store executable commands
 * Return: 1 if command is a built in otherwise 0
*/
int handle_builtins(char *command, char **parameters)
{
	char **env = environ;

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
			write(STDOUT_FILENO, "*env", _strlen(*env));
			write(STDOUT_FILENO, "\n", 1);
			env++;
		}
		return (1);
	}
	if (_strcmp(command, "cd") == 0)
	{
		if (parameters[1] != NULL)
			chdir(parameters[1]);
		else
			chdir(getenv("HOME"));
	}
	return (0);

}

