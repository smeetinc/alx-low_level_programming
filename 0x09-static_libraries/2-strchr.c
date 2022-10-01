#include "main.h"

/**
 *   _strchr - locates character in string
 *   @s: locating string
 *   @c: character to search
 *   Return: 0 to end
 */

char *_strchr(char *s, char c)
{
	int i;

	for (i = 0; s[i] != '\0'; i++)
	{
		if (s[i] == c)
		{
			return (s + i);
		}
	}
	if (s[i] == c)
		return (s + i);
	return (0);
}
