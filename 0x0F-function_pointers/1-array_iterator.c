#include <stddef.h>

/**
 * array_iterator - function to execute set of functions
 * @array: param 1
 * @size: param 2
 * @action: param 3
 * Return: void
 */

void array_iterator(int *array, size_t size, void (*action)(int))
{
	unsigned int i;

	if (array != NULL && size > 0 && action != NULL)
		for (i = 0; i < size; i++)
			action(array[i]);
}
