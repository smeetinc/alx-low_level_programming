#include "main.h"

/**
 * binary_to_uint - binary to uint
 * @b: bin num
 * Return: the uint
 */

unsigned int binary_to_uint(const char *b)
{
	unsigned int i;
	int l, binary;

	if (!b)
		return (0);
	i = 0;
	for (l = 0; b[l] != '\0'; l++)
		;
	for (l--, binary = 1; l >= 0; l--, binary *= 2)
	{
		if (b[l] != '0' && b[l] != '1')
		{
			return (0);
		}
		if (b[l] & 1)
		{
			i += binary;
		}
	}
	return (i);
}
