#include "main.h"
#include <stdlib.h>

/**
 * malloc_checked - func to allocate memory
 * @b: func param
 * Return: exit status 98 if fail
 */

void *malloc_checked(unsigned int b)
{
	char *ptr;

	ptr = malloc(b);
	if (ptr == NULL)
		exit(98);
	return (ptr);
}
