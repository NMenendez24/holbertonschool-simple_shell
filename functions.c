#include "shell.h"

/**
 * _getenv - Returns the environment variable especified
 * Return: Pointer to variable on success, NULL if it fails
 * @name: Name of the variable to find
 */

char *_getenv(const char *name)
{
	int i;
	char *str = NULL;

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

/**
 * _getcommand - Concatenates the command to the path and returns
 * the path to it
 * Return: Path to the command on success, NULL if it fails
 * @path: Full path
 * @command: Name of the comand to find the path
 */

char *_getcommand(char *path, char *command)
{
	char *token = NULL, *aux = NULL, *delim = ":";
	struct stat st;

	if (stat(command, &st) == 0)
		return (command);
	token = strtok(path, delim);
	while (token)
	{
		aux = malloc(sizeof(char) * (strlen(token) + strlen(command)) + 2);
		if (!aux)
		{
			return (NULL);
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

/**
 * _argcounter - Counts the arguments of a string
 * Return: Number of arguments counted
 * @inp: Input
 */

int _argcounter(char *inp)
{
	int len = 0, argcount = 0;

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

/**
 * _printenv - Prints the environment
 * Return: Nothing
 */

void _printenv(void)
{
	int i;

	for (i = 0; environ[i]; i++)
	{
		_putsnl(environ[i]);
	}
}

