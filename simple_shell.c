#include "shell.h"

/**
  *
  *
  *
  */

int main(void)
{	char *buff = NULL, *buffdup = NULL, *token = NULL,
	     **av = NULL, *com_path = NULL, *aux = NULL, *pathaux = NULL;
	size_t bufsize = 0;
	struct stat st;
	int ac = 0, status, pid_check, argcount = 0, c;

	while (1)
	{
		if (isatty(STDIN_FILENO) == 1)
			_puts("$ ");
		c = getline(&buff, &bufsize, stdin);
		if (c == -1 && isatty(STDIN_FILENO) == 1)
			free(buff), _putchar(10), exit(0);
		else if (c == -1)
			free(buff), exit(0);
		buffdup = _strdup(buff), argcount = _argcounter(buffdup);
		token = strtok(buffdup, " \\\t\n");
		if (!token)
		{	free(buffdup);
			continue; }
		av = malloc(sizeof(char *) * (argcount + 1));
		if (!av)
		{	free(buff), free(buffdup);
			return (-1); }
		if (_strcmp(token, "exit") == 0)
			free(buff), free(buffdup), free(av), exit(0);
		if (_strcmp(token, "env") == 0)
		{	_printenv(), free(av), free(buffdup);
			continue; }
		if (stat(token, &st) == 0)
			av[0] = token;
		else
		{	pathaux = _getenv("PATH"), com_path = _getcommand(pathaux, token);
		free(pathaux - 5); 
			if (com_path == NULL)
			{	/*free(buff),*/ free(buffdup), free(av);
				perror("Command not found");
				continue; }
			av[0] = com_path, token = strtok(buff, " \\\t\n"); }
		for (ac = 1; ac <= argcount; ac++)
			aux = strtok(NULL, " \\\t\n"), av[ac] = aux;
		pid_check = fork();
		if (pid_check == 0)
			execve(av[0], av, environ);
		wait(&status);
//		if (isatty(STDIN_FILENO) == 1)
//			free(buffdup);
		free(buffdup), free(av);
		if (com_path)
			free(com_path); } }
