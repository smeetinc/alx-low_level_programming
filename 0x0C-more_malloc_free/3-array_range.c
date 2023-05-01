#include "main.h"
#include <stdlib.h>

/**
 * array_range - func to create array of integers
 * @min: fun param 1
 * @max: func param 2
 * Return: NULL if fails
 */

int *array_range(int min, int max)
{
	int *my_arrray;
	int i;

	if (min > max)
		return (NULL);
	my_array = malloc(sizeof(*my_array) * ((max - min) + 1));
	if (my_array == NULL)
		return (NULL);
	for (i = 0; min <= max; i++, min++)
		my_array[i] = min;
	return (my_array);
}
