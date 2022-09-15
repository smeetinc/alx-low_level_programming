#include "main.h"

/**
* print_times_table - Prints n times table
* @n: determines size of the times table
* Return: no return value
*/
void print_times_table(int n)
{
	int a, b, act;
if (n >= 0 && n <= 15)
	{
	for (a = 0; a <= n; a++)
	{
	_putchar(48);
	for (b = 1; b <= n; b++)
	{
		act = a * b;
		_putchar(44);
		_putchar(32);
		if (act <= 9)
		{
		_putchar(32);
		_putchar(32);
		_putchar(act + 48);
		}
		else if (act <= 99)
		{
		_putchar(32);
		_putchar((act / 10) + 48);
		_putchar((act % 10) + 48);
		}
		else
		{
		_putchar(((act / 100) % 10) + 48);
		_putchar(((act / 10) % 10) + 48);
		_putchar((act % 10) + 48);
		}
	}
	_putchar('\n');
	}
	}
}
