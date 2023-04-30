#include "main.h"
/**
 * prime_check - func for prime control
 * @n: func param 1
 * @c: func param 2
 * Return: 1 || 0
 */

int prime_check(unsigned int n, unsigned int c)
{
	if (n % c == 0)
	{
		if (n == c)
			return (1);
		else
			return (0);
	}
	return (0 + prime_check(n, c + 1));
}

/**
 * is_prime_number - check if an input is a prime number
 * @n: func param
 * Return: 1 || 0
 */

int is_prime_number(int n)
{
	if (n == 0)
		return (0);
	else if (n < 0)
		return (0);
	else if (n == 1)
		return (0);
	else
		return (prime_check(n, 2));
}
