#include "main.h"

/**
 *   _strstr - a function that locates a substring
 *   @haystack: param 1
 *   @needle: param 2
 *   Return: NULL to terminate at invalid result
 */

char *_strstr(char *haystack, char *needle)
{
	char *h = haystack;
	char *n = needle;

	while (*h)
	{
		n = needle;
		h = haystack;
		while (*n)
		{
			if (*h == *n)
			{
				n++;
				h++;
			}
			else
				break;
		}
		if (*n == '\0')
			return (haystack);
		haystack++;
	}
	return (0);
}
