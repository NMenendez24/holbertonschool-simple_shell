#include "shell.h"

/**
  * main - Command interpreter
  * Return: -1 on error
  */

int main(void)
{	char *buff = NULL, *buffdup = NULL, *token = NULL,
	     **av = NULL, *com_path = NULL, *aux = NULL, *pathaux = NULL;
	size_t bufsize = 0;
	struct stat st;
	int ac = 0, status, pid_check, argcount = 0, c, i = 0;

	while (1)
	{
		(isatty(STDIN_FILENO) == 1) ? _puts("$ ") : (void) 0, i++; /*Print prompt*/
		c = getline(&buff, &bufsize, stdin); /*gets the input*/
		(c == -1 && isatty(STDIN_FILENO) == 1) ? free(buff), _putchar(10), exit(0) :
			(c == -1) ? free(buff), exit(127) : (void) 0; /*Checks for a CTRL + D*/
		buffdup = _strdup(buff), argcount = _argcounter(buffdup);
		token = strtok(buffdup, " \\\t\n");
		if (!token) /*empty input handle*/
		{	free(buffdup);
			continue; }
		av = malloc(sizeof(char *) * (argcount + 2)); /* for the argument vector*/
		if (!av)
		{	free(buff), free(buffdup), write(2, "Fatal error\n", 12);
			return (-1); } /*malloc fail handle*/
		(strcmp(token, "exit") == 0) ? free(buff), free(buffdup),
			free(av), exit(2) : (void) 0; /*exit built-in*/
		if (_strcmp(token, "env") == 0) /*env built-in*/
		{	_printenv(), free(av), free(buffdup);
			continue; }
		if (stat(token, &st) == 0) /*check if the input is already a command*/
			av[0] = token;
		else
		{	pathaux = _getenv("PATH"), com_path = _getcommand(pathaux, token);
		free(pathaux - 5); /*gets the command and searchs it in the path*/
			if (com_path == NULL)
			{	_error(i, token), free(buffdup), free(av);
				continue; } /*Incorrect command handle*/
		av[0] = com_path, token = strtok(buff, " \\\t\n"); }
		for (ac = 1; ac <= argcount; ac++) /*builds the argument vector*/
			aux = strtok(NULL, " \\\t\n"), av[ac] = aux;
		pid_check = fork(); /*creates a parent proccess*/
		(pid_check == 0) ? execve(av[0], av, environ) : 0; /*executes the command*/
		wait(&status);
		free(buffdup), free(av), (com_path) ? free(com_path) : (void) 0; }} /*end*/
