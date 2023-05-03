#include "main.h"

/**
 * _isupper - uppercase letters func
 * @c: func input
 * Return: 0 || 1
 */

int _isupper(int c)
{
	if (c >= 'A' && c <= 'Z')
		return (1);
	else
		return (0);
}
