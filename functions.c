#include "shell.h"

char *_getenv(const char *name)
{
	int i;
	char *buff, *token, *str;

	
	printf("En funcion getenv name: %s\n", name);
	buff = malloc(sizeof(char *) * 100);
	for (i = 0; environ[i]; i++)
	{
		str = strtok(environ[i], "=");
		if (strcmp(str, name) == 0)
		{
			str = strtok(NULL, "=");
			free(buff);
			return (str);
		}
	}
	return (NULL);
}

char *_getcommand(char *path, char *command)
{
	int c = 0, child_check, check = 0;
	char *token, *buff, *aux;
	struct stat st;

	printf("En funcion getcommand path: %s\n", path);
	printf("En funcion getcommand command: %s\n", command);
	buff = path;
	token = strtok(buff, ":");
	while (stat(token, &st) == -1 && token != NULL)
	{
		token = strcat(token, "/");
		token = strcat(token, command);
		token = strtok(NULL, ":");
	}
	if(stat(token, &st) == 0)
	{
		return(token);
	}
	return(NULL);
}

/*
void main(void)
{
	char *str = "PATH";
	char *path = _getenv(str);
	char *command = "ls";
	char *aux;

	aux = _getcommand(path, command);
	printf("Main final: %s\n", aux);
	return;	
}
*/
