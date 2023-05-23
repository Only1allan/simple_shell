#ifndef SHELL_H
#define SHELL_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/wait.h>
#include <fcntl.h>
#include <signal.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <ctype.h>

extern char **environ;

void type_prompt(void);
void read_command(char cmd[], char *par[]);
void execute_command(char *command, char **parameters);
size_t my_getline(char *line, size_t size, FILE *stream);

int _strlen(char *s);
char *_strcat(char *dest, char *src);
int _strcmp(char *s1, char *s2);
char *_strcpy(char *dest, char *src);
char *_strdup(const char *str);

int _atoi(char *s);

#endif

