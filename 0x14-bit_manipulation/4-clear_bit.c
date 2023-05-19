#include "main.h"

/**
 * clear_bit - change bit val to 0
 * @n: func param 1
 * @index: func param 2
 * Return: 1 || -1
 */

int clear_bit(unsigned long int *n, unsigned int index)
{
	unsigned int i;

	if (index > 63)
		return (-1);
	i = 1 << index;
	if (*n & i)
		*n ^= i;
	return (1);
}
