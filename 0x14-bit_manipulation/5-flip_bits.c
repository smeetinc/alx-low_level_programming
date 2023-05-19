#include "main.h"

/**
 * flip_bits - loop through num and get count
 * @n: func param 1
 * @m: func param 2
 * Return: count
 */

unsigned int flip_bits(unsigned long int n, unsigned long int m)
{
	unsigned int count;

	for (count = 0; n || m; n >>= 1, m >>= 1)
	{
		if ((n & 1) != (m & 1))
			count++;
	}
	return (count);
}
