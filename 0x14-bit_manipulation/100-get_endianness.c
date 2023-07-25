#include "main.h"

/**
 * get_endianness - check for endianness
 * Return: 0 || 1
 */
int get_endianness(void)
{
	unsigned int i;
	char *s;

	i = 1;
	s = (char *) &i;
	return ((int)*s);
}
