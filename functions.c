#include "shell.h"

char *_getenv(const char *name)
{
	int i;
	char *buff, *token, *str;

	buff = malloc(sizeof(char *) * 100);
	for (i = 0; environ[i]; i++)
	{
		str = strtok(environ[i], "=");
		if (strcmp(str, name) == 0)
		{
			str = strtok(NULL, "=");
			free(buff);
			printf("Path en getenv: %s\n", str);
			return (str);
		}
	}
	return (NULL);
}

char *_getcommand(char *path, char *command)
{
	int c = 0, child_check, check = 0;
	char *token = NULL, *buff = NULL, *aux = NULL, *delim = ":";
	struct stat st;

	printf("Before Token\n");
	buff = strdup(path);
	token = strtok(buff , delim);
	printf("Token\n");
	while (token)
	{
		token = strtok(NULL, delim);
		printf("token: %s\n", token);
		aux = malloc(2);
//		aux = malloc(sizeof(char) * (strlen(token) + strlen(command)) + 2);
		strcpy(aux, token);
		strcat(aux, "/");
		strcat(aux, command);
		printf("%s\n", aux);
		if(stat(aux, &st) == 0)
		{
			free(buff);
			return (aux);
		}
		free(aux);
		aux = NULL;
		/**aux = malloc(1024);
		strcpy(aux, token);
		strcat(aux, "/");
		strcat(aux, command);
		if(stat(aux, &st) == 0)
		{
			return(aux);
		}
		else
			free(aux);*/
	}
	return(NULL);
}


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

