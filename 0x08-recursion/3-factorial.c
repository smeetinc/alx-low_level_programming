#include "main.h"
/**
 * factorial - gives factorial of a number
 * @n: func param
 * Return: result of factorial
 */

int factorial(int n)
{
	if (n < 0)
		return (-1);
	else if (n == 0)
		return (1);
	else
		return (n * factorial(n - 1));
}
