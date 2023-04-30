#include "main.h"
/**
 * sqrt_dependency - to return natural square root
 * @n: func input
 * @c: increment
 * Return: sqrt || -1
 */

int sqrt_dependency(int n, int c)
{
	if (c % (n / c) == 0)
	{
		if (c * (n / c) == n)
			return (c);
		else
			return (-1);
	}
	return (0 + sqrt_dependency(n, c + 1));
}

/**
 * _sqrt_recursion - returns natural square root
 * @n: func param
 * Return: comput result
 */

int _sqrt_recursion(int n)
{
	if (n < 0)
		return (-1);
	if (n == 0)
		return (0);
	if (n == 1)
		return (1);
	return (sqrt_dependency(n, 2));
}
