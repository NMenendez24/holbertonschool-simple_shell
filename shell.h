#ifndef SHELL_H
#define SHELL_H

/*__________ LIBRARIES __________*/

#include <sys/stat.h>
#include <fcntl.h>
#include <stdio.h>
#include <unistd.h>
#include <sys/wait.h>
#include <stdlib.h>
#include <string.h>

/*---------- EVIRONMENT ----------*/

extern char **environ;

/*----------- FUNCTIONS ----------*/

char *_getenv(const char *name);

char *_getcommand(char *path, char *command);

int _argcounter(char *inp);

void _puts(char *str);

int _putchar(char c);

char *_strcat(char *dest, char *src);

int _strlen(char *s);

char *_strcpy(char *dest, char *src);

int _strcmp(char *s1, const char *s2);

char *_strdup(char *str);

void _putsnl(char *str);

void _printenv(void);

void _error(int times, char *command);

#endif
