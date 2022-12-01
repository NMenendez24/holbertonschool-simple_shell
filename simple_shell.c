#include "shell.h"

/**
  *
  *
  *
  */

int main(void)
{
	char *buff, *buffdup, **av;
	size_t bufsize = 0;
	int ac = 0, status, pid_check, len = 0, argcount = 0;

	while (1)
	{
		printf("$ ");
		getline(&buff, &bufsize, stdin);
		buffdup = strdup(buff);
		buff = strtok(buff, " \n");
		if (buff == NULL)
		{
			printf("Cagaste Light\n");
			return (-1);
		}
		for (len = 0; buffdup[len] != '\0'; len++)
			if (buffdup[len] == ' ' || buffdup[len] == '\n')
				argcount += 1;
		av = malloc(sizeof(char *) * argcount + 1);
		if (!av)
		{
			printf("Fallo malloc\n");
			return (-1);
		}
		av[0] = buff;
		for (ac = 1; ac <= argcount; ac++)
		{
			av[ac] = strtok(NULL, " \n");
			if (ac == argcount)
				av[ac + 1] = NULL;
		}
		pid_check = fork();
		wait(&status);
		if (pid_check == 0)
		{
			execve(av[0], av, environ);
		}
		free(buffdup);
		free(av);
	}
}
