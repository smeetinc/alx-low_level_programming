#include "main.h"

/**
 * puts_half - produce half of the string.
 * @str: function input.
 * Return: void.
 */

void puts_half(char *str)
{
	int len = 0;
	char *a = str;
	int n;

	while (*a != '\0')
	{
		a++;
		len++;
	}
	if (len % 2 == 0)
	{
		n = len / 2;
	}
	else
	{
		n = (len + 1) / 2;
	}
	for ( ; n < len ; n++)
	{
		_putchar(str[n]);
	}
	_putchar('\n');
}
