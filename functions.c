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
			return (str);
		}
	}
	return (NULL);
}

char *_getcommand(char *path, char *command)
{
	int c = 0, child_check;
	char *token, *buff, *aux;
	struct stat st;

	token = malloc(strlen(path) + 3);	
	token = strtok(path, ":\0");
	token = strcat(token, "/");
	token = strcat(token, command);
	printf("%s\n", token);
	while (stat(token, &st) == -1 && token)
	{
		token = strtok(NULL, ":");
		strcat(token, "/");
		strcat(token, command);
	}
	if(stat(token, &st) == 0)
	{
		return(token);
	}
	return(NULL);
}
	/*while (token)
	{
		buff = strcat(token, "/");
		buff = strcat(buff, command);
		for (; c == -1;)
		{
			child_check = fork();
			{
				if (child_check == 0)
				{
					c = execve(buff, &buff, environ);
				}
			}
		}
		printf("%s\n", buff);
		return (buff);
	} */


void main(void)
{
	char *str = "PATH";
	char *path = _getenv(str);
	char *command = "ls";
	char *aux;

	aux = _getcommand(str, command);
	printf("%s", aux);
	return;	
}
