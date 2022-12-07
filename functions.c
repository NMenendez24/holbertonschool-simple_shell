#include "shell.h"

char *_getenv(const char *name)
{
	int i;
	char *buff, *token, *str;

	for (i = 0; environ[i]; i++)
	{
		str = strdup(environ[i]);
		str = strtok(str, "=");
		if (strcmp(str, name) == 0)
		{
			str = strtok(NULL, "=");
			printf("Path en getenv: %s\n", str);
			return (str);
		}
		free(str);
	}
	return (NULL);
}

char *_getcommand(char *path, char *command)
{
	int c = 0, child_check, check = 0;
	char *token = NULL, *buff = NULL, *aux = NULL, *delim = ":";
	struct stat st;

	if (stat(command, &st) == 0)
		return (command);
	buff = strdup(path);
	token = strtok(buff, delim);
	while (token)
	{
		token = strtok(NULL, delim);
		aux = malloc(sizeof(char) * (strlen(token) + strlen(command)) + 1);
		strcpy(aux, token);
		strcat(aux, "/");
		strcat(aux, command);
		if (stat(aux, &st) == 0)
		{
			free(buff);
			return (aux);
		}
		free(aux);
		aux = NULL;
	}
	return (NULL);
}

int _argcounter(char *inp)
{
	int len = 0, argcount = 0;
	char c;

	printf("Input: %s\n", inp);
	for (len = 0; len < strlen(inp); len++)
	{
		if (inp[len] == ' ' && inp[len + 1] != ' ' && inp[len + 1] != '\t')
			argcount += 1;
		else if (inp[len] == '\t' && inp[len + 1] != ' ' && inp[len + 1] != '\t')
			argcount += 1;
	}
	if ((inp[0] == ' ' || inp[0] == '\t') && (inp[1] == ' ' || inp[1] == '\t'))
		argcount -= 2;
	return (argcount + 1);
}

