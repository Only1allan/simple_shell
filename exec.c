#include "shell.h"
/**
 * execute_command - a function that executes executable commands
 * @command: parameter to store built in commands
 * @parameters: parameter to store executable commands
 * Return:void
 */
void execute_command(char *command, char **parameters)
{
	char **cmd_args;
	char cmd_path[100];
	char **env;
	pid_t pid;
	int i;

	env = environ;

	if (handle_builtins(command, parameters))
		return;

	if (_strcmp(command, "/bin/ls") == 0)
	{
        
        i = 1;
        while (parameters[i] != NULL)
			i++;
		
		cmd_args = malloc(sizeof(char *) * (i + 1));
		cmd_args[0] = "ls";

		for (i = 1; parameters[i] != NULL; i++)
			cmd_args[i] = parameters[i];
		
		cmd_args[i] = NULL;

		_strcpy(cmd_path, "/bin/ls");

		pid = fork();
		if (pid == -1)
		{
			perror("fork");
			exit(1);
		}
		else if (pid == 0)
		{
			execve(cmd_path,  cmd_args, env);
			perror("error");
			exit(EXIT_FAILURE);
		}
		else
			wait(NULL);

		free(cmd_args);

	}
	else
	{
		pid = fork();
		if (pid == -1)
		{
			perror("fork");
			exit(1);
		}
		else if (pid == 0)
		{
			_strcpy(cmd_path, "/bin/");
			_strcat(cmd_path, command);
			execve(cmd_path, parameters, env);

			perror("error");
			exit(1);
		}
		else
			wait(NULL);
	}
}
