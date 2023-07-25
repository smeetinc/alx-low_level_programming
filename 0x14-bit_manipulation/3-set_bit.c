#include "main.h"

/**
 * set_bit - make bit value 1
 * @n: pointer to unsigned long int
 * @index: index of bit
 * Return: 1 || -1
 */

int set_bit(unsigned long int *n, unsigned int index)
{
	unsigned int i;

	if (index > 63)
		return (-1);
	i = 1 << index;
	*n = (*n | i);
	return (1);
}
