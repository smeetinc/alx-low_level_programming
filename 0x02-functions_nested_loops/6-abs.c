#include "main.h"

/**
 * _abs - function that givess the absolute value of an integer
 * @c:  function parameter
 * Return: value of c depending on condition
 */

int _abs(int c)
{
	if (c > 0 || c == 0)
	{
		return (c);
	}
	else
		return (c * -1);
}
