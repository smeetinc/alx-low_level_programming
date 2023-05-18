#include "main.h"

/**
 * binary_to_uint - func to convert 01s to uint
 * @b: func param
 * Return: converted uint
 */

unsigned int binary_to_uint(const char *b)
{
	unsigned int uint;
	int length, binary;

	if (!b)
		return (0);
	uint = 0;
	for (length = 0; b[length] != '\0'; length++)
		;
	for (length--, binary = 1; length >= 0; length--, binary *= 2)
	{
		if (b[length] != '0' && b[length] != '1')
		{
			return (0);
		}
		if (b[length] & 1)
		{
			uint += binary;
		}
	}
	return (uint);
}
