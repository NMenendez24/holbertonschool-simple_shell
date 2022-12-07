#include "shell.h"

/**
  *
  *
  *
  */

int main(void)
{
	char *buff, *buffdup, *token, **av, *com_path, *aux;
	size_t bufsize = 0;
	int ac = 0, status, pid_check, len = 0, argcount = 0, c = 0;

	while (1)
	{
		if(isatty(STDIN_FILENO) == 1)
			_puts("$ ");
		buff = malloc(bufsize);
		c = getline(&buff, &bufsize, stdin);
		if (c == -1)
		{
			printf("\n");
			exit(0);
		}
		buffdup = strdup(buff);
		argcount = _argcounter(buffdup);
		token = strtok(buffdup, " \t\n");
		if (!token)
			continue;
		av = malloc(sizeof(char *) * argcount + 1);
		if (!av)
		{
			printf("Fallo malloc\n");
			return (-1);
		}
		if(strcmp(token, "exit") == 0)
			exit(0);
		com_path = _getcommand(_getenv("PATH"), token);
		if(com_path == NULL)
			printf("Command: %s not found\n", token);
		av[0] = com_path;
		token = strtok(buff, " \t\n");
		for (ac = 1; ac <= argcount; ac++)
		{
			aux = strtok(NULL, " \t\n");
			av[ac] = aux;
			if (ac == argcount)
				av[ac + 1] = NULL;
		}
		pid_check = fork();
		if (pid_check == 0)
			execve(av[0], av, environ);
		else
			wait(&status);
		free(buff);
		free(av);
	}
}
