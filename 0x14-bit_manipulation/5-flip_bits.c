#include "main.h"

/**
 * flip_bits - to give num ob bits
 * @n: func param 1
 * @m: func param 2
 * Return: numbits
 */

unsigned int flip_bits(unsigned long int n, unsigned long int m)
{
	unsigned int numbits;

	for (numbits = 0; n || m; n >>= 1, m >>= 1)
	{
		if ((n & 1) != (m & 1))
			numbits++;
	}
	return (numbits);
}
