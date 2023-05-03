#include "main.h"

/**
 * _memcpy - func to copy memory
 * @dest: func param 1
 * @src: func param 2
 * @n: func param 3
 * Return: dest
 */

char *_memcpy(char *dest, char *src, unsigned int n)
{
	int r = 0, i = n;

	for (; r < i; r++)
	{
		dest[r] = src[r];
		n--;
	}
	return (dest);
}
