#include "main.h"

/**
 * _memset - set memory
 * @s: func param
 * @b: func param 2
 * @n: func param 3
 * Return: s
 */

char *_memset(char *s, char b, unsigned int n)
{
	int i = 0;

	for (; n > 0; i++)
	{
		s[i] = b;
		n--;
	}
	return (s);
}
