#include "main.h"
#include <stdlib.h>

/**
 * _calloc - func to allocate mem for array
 * @nmemb: fun param 1
 * @size: func param 2
 * Return: NULL on fail
 */

void *_calloc(unsigned int nmemb, unsigned int size)
{
	char *ptr;
	unsigned int i;

	if (nmemb == 0 || size == 0)
		return (NULL);
	ptr = malloc(nmemb * size);
	if (ptr == NULL)
		return (NULL);
	for (i = 0; i < (nmemb * size); i++)
		ptr[i] = 0;
	return (ptr);
}
