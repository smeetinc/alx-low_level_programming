#include "main.h"

/**
 * more_numbers - function to print more numbers
 * Return - no return value
 */

void more_numbers(void)
{
	int i, int j;

	i = 0;
	while (i < 10)
	{
		j = 0;
		while (j <= 10)
		{
			_putchar(j);
			j++;
		}
		_putchar('\n');
		i++;
	}
}
