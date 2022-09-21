#include "main.h"

/**
 *  _strcpy - copy the string src to dest.
 *  @dest: destination of copied string.
 *  @src: source of string to be copied.
 *  Return: dest.
 */

char *_strcpy(char *dest, char *src)
{
	int l = 0;
	int i = 0;

	while (*(src + l) != '\0')
	{
		l++;
	}
	for ( ; i < l ; i++)
	{
		dest[i] = src[i];
	}
	dest[l] = '\0';
	return (dest);
}
