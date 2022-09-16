#include "main.h"

/**
 * more_numbers - function to print more numbers
 * Return - no return value
 */

void more_numbers(void)
{
	int i, char j;

	i = 0;
	while (i < 10)
	{
		j = 0;
		while (j <= 10)
		{
			if (j > 9)
			{
				_putchar((j / 10) + '0');
				_putchar((j % 10) + '0');
				j++;
			}
		}
		_putchar('\n');
		i++;
	}
}
