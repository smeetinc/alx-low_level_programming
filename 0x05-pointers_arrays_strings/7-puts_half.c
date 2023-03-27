#include "main.h"

/**
 * puts_half - half a string and print it
 * @str: function input
 * Return: void
 */

void puts_half(char *str)
{
	int a, b;

	for (a = 0; str[a] != '\0'; ++a)
		;
	if (a % 2 == 0)
	{
		for (b = a / 2; str[b] != '\0'; ++b)
			_putchar(str[b]);
	} else
	{
		for (b = ((a - 1) / 2) + 1; str[b] != '\0'; ++b)
			_putchar(str[b]);
	}
	_putchar('\n');
}
