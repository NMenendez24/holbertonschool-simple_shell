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

/*---------- Evironment ----------*/

extern char **environ;
/*----------- FUNCTIONS ----------*/

char *_getenv(const char *name);

char *_getcommand(char *path, char *command);

int _argcounter(char *inp);

void _puts(char *str);

int _putchar(char c);

#endif
