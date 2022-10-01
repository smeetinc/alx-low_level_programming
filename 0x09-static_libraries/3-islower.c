#include "main.h"

/**
 * _islower - function to check for lowercase character
 * @c:  is the function parameter
 * Return: 0 (to be successful)
 */

int _islower(int c)
{
	if (c >= 'a' && c <= 'z')
	{
		return (1);
	}
	else
		return (0);
}
