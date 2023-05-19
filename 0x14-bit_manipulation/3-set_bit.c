#include "main.h"

/**
 * set_bit - func to set bit value to 1
 * @n: addr of an uint
 * @index: bit index
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
