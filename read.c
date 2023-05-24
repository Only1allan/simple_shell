#include "shell.h"
/**
 * read_command - a function that reads and tokenizes user input
 * @cmd : an array storing user commands
 * @par: an array of pointers to user parameters
 * Return: void
 */
void read_command(char cmd[], char *par[])
{
	char *pch, *line = NULL;
	size_t len = 0;
	ssize_t nread;
	int i = 0;

	signal(SIGINT, SIG_IGN);
	nread = getline(&line, &len, stdin);

	if (nread != -1)
	{
		line[nread - 1] = '\0';
		if (_strlen(line) > 0)
		{
			pch = strtok(line, " ");
			while (pch != NULL)
			{
				par[i++] = _strdup(pch);
				pch = strtok(NULL, " ");
			}
			_strcpy(cmd, par[0]);
			par[i] = NULL;
		}

	}
	else
	{
		write(1, "Exiting success\n", 16);
		exit(EXIT_SUCCESS);
	}
	free(line);

}
