#include "shell.h"

char *_getenv(const char *name)
{
	int i;
	char *buff = NULL, *token, *str;

	for (i = 0; environ[i]; i++)
	{
		str = _strdup(environ[i]);
		str = strtok(str, "=");
		if (_strcmp(str, name) == 0)
		{
			str = strtok(NULL, "=");
			return (str);
		}
		free(str);
	}
	return (NULL);
}

char *_getcommand(char *path, char *command)
{
	int c = 0, check = 0;
	char *token = NULL, *buff = NULL, *aux = NULL, *delim = ":";
	struct stat st;

	if (stat(command, &st) == 0)
		return (command);
	token = strtok(path, delim);
	while (token)
	{
		aux = malloc(sizeof(char) * (strlen(token) + strlen(command)) + 2);
		if(!aux)
		{
			return(NULL);
		}
		_strcpy(aux, token);
		_strcat(aux, "/");
		_strcat(aux, command);
		if (stat(aux, &st) == 0)
		{
			return (aux);
		}
		token = strtok(NULL, delim);
		free(aux);
		aux = NULL;
	}
	return (NULL);
}

int _argcounter(char *inp)
{
	int len = 0, argcount = 0;
	char c;

	for (len = 0; len < _strlen(inp); len++)
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

