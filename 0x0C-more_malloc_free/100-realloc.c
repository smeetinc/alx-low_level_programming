#include "main.h"
#include <stdlib.h>

/**
 * _realloc - func to reallocate mem block
 * @ptr: func param 1
 * @old_size: param 2
 * @new_size: param 3
 * Return: ptr || NULL
 */

void *_realloc(void *ptr, unsigned int old_size, unsigned int new_size)
{
	if (new_size == 0 && ptr != NULL)
	{
		free(ptr);
		return (NULL);
	}
	if (ptr == NULL)
		ptr = malloc(new_size);
	if (new_size == old_size)
		return (ptr);
	free(ptr);
	ptr = malloc(new_size);
	return (ptr);
}
