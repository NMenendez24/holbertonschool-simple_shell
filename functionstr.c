#include "shell.h"

/**
 * *_strcat - concatenate the strings
 * @dest: pointer destination
 * @src: pointer source
 * Return: dest
 */

char *_strcat(char *dest, char *src)
{
	int i;
	int n;

	for (i = 0 ; dest[i] != '\0' ; i++)
		;
	for (n = 0 ; src[n] != '\0' ; n++)
	{
		dest[i] = src[n];
		i++;
	}
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
 * *_strncpy - function copies a string
 * @dest: pointer destination
 * @src: pointer source
 * @n: bytes
 * Return: dest
 */

char *_strncpy(char *dest, char *src, int n)
{
	int i;
	{
		for (i = 0 ; i < n && src[i] != '\0' ; i++)
			dest[i] = src[i];
		for ( ; i < n; i++)
			dest[i] = '\0';
	}
		return (dest);
}

/**
 *_strcmp - compares two strings
 *@s1: pointer first string to be compared
 *@s2: pointer second string to be compare
 *Return: s1[i] - s2[i]
 */

int _strcmp(char *s1, char *s2)
{
	int i;

	for (i = 0 ; s1[i] - s2[i] == 0 && s1[i] != '\0' ; i++)
		;
		return (s1[i] - s2[i]);
}


