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

	if(stat(command, &st) == 0)
		return(command);
	buff = strdup(path);
	token = strtok(buff, delim);
	while (token)
	{
		token = strtok(NULL, delim);
		aux = malloc(sizeof(char) * (strlen(token) + strlen(command)) + 1);
		strcpy(aux, token);
		strcat(aux, "/");
		strcat(aux, command);
		if(stat(aux, &st) == 0)
		{
			free(buff);
			return (aux);
		}
		free(aux);
		aux = NULL;
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

	printf("Soy el main\n");
	aux = _getcommand(path, command);
	printf("Main final: %s\n", aux);
	return;	
}
*/
