#include <stddef.h>
#include "function_pointers.h"

/**
 * int_index - function to look for integers
 * @array: func param 1
 * @size: func param 2
 * @cmp: func param 3
 * Return: an integer
 */

int int_index(int *array, int size, int (*cmp)(int))
{
	int i;
	bool j;

	if (array != NULL && size > 0 && cmp != NULL)
	{
		if (size <= 0)
			return (-1);
		for (i = 0; i < size; i++)
		{
			j = cmp(array[i]);
			if (j == TRUE)
				return (i);
		}
	}
	return (-1);
}
