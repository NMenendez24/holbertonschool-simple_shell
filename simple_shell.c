#include "shell.h"

/**
  *
  *
  *
  */

int main(void)
{
	char *buff = NULL, *buffdup = NULL, *token = NULL, **av, *com_path = NULL, *aux = NULL, *pathaux = NULL;
	size_t bufsize = 0;
	int ac = 0, status, pid_check, len = 0, argcount = 0, c;

	while (1)
	{
		if(isatty(STDIN_FILENO) == 1)
			_puts("$ ");
		c = getline(&buff, &bufsize, stdin);
		if (c == -1 && isatty(STDIN_FILENO) == 1)
			free(buff), _putchar(10), exit(0);
		else if (c == -1)
			free(buff), exit(0);
		buffdup = _strdup(buff);
		argcount = _argcounter(buffdup);
		token = strtok(buffdup, " \t\n");
		if (!token)
		{
			free(buff), free(buffdup);
			continue;
		}
		av = malloc(sizeof(char *) * (argcount + 1));
		if (!av)
		{
			free(buff), free(buffdup);
			printf("Fallo malloc\n");
			return (-1);
		}
		if(_strcmp(token, "exit") == 0)
			free(buff), free(buffdup), free(av), exit(0);
		pathaux = _getenv("PATH"), com_path = _getcommand(pathaux, token);
		free(pathaux - 5);
		if(com_path == NULL)
		{
			free(buff), free(buffdup), free(av);
			perror("sopa de guiso");
			continue;
		}
		av[0] = com_path;
		token = strtok(buff, " \t\n");
		for (ac = 1; ac <= argcount; ac++)
		{
			aux = strtok(NULL, " \t\n");
			av[ac] = aux;
		}
		pid_check = fork();
		if (pid_check == 0)
			execve(av[0], av, environ);
		else
			wait(&status);
		free(buffdup), free(av), free(com_path);
	}
}
