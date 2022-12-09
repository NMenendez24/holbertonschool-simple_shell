#include "shell.h"

/**
 * *_strcat - concatenate the strings
 * @dest: pointer destination
 * @src: pointer source
 * Return: dest
 */

char *_strcat(char *dest, char *src)
{
	char *dest_aux;
	const char *src_aux;

	dest_aux = dest;
	src_aux =  src;

	while (*dest_aux != '\0')
		dest_aux++;

	while (*src_aux != '\0')
		*dest_aux++ = *src_aux++;
	*dest_aux = '\0';
	return (dest);
}
/**
 * _strlen - function than retunr the length of a text string
 * @s: pointer to the adress of the string
 * Return: all elements of the string
 */

int _strlen(char *s)
{
	int n = 0;

	while (s[n] != '\0')
		n++;
	return (n);
}

/**
 * *_strcpy - Copy a string to another pointer
 * Return: dest
 * @dest: destinatio pointer
 * @src: source pointer
 */

char *_strcpy(char *dest, char *src)
{
	int i = 0;

	for (i = 0; src[i] != '\0'; i++)
		dest[i] = src[i];
	dest[i] = '\0';
	return (dest);
}

/**
 *_strcmp - compares two strings
 *@s1: pointer first string to be compared
 *@s2: pointer second string to be compare
 *Return: s1[i] - s2[i]
 */

int _strcmp(char *s1, const char *s2)
{
	int i = 0;

	for (i = 0 ; s1[i] - s2[i] == 0 && s1[i] != '\0' ; i++)
		;
	return (s1[i] - s2[i]);
}

/**
 * _strdup - Duplicates a string
 * Return: NULL if the program fails, nstr on success
 * @str: Initial String
 */

char *_strdup(char *str)
{
	unsigned int i = 0, j = 0;
	char *nstr = NULL;

	if (str == NULL)
		return (NULL);
	for (j = 0; str[j] != '\0'; j++)
	{
	}
	nstr = malloc(sizeof(char) * (j + 1));

	if (nstr == NULL)
		return (NULL);
	for (i = 0; i <= j; i++)
		nstr[i] = str[i];
	return (nstr);

}
