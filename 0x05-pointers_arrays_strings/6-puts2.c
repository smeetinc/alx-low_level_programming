#include "main.h"

/**
 * puts2 - print pair values.
 * @str: value to be evaluate.
 * Return: not.
 */

void puts2(char *str)
{
	int len = 0;
	int l = 0;
	char *a = str;
	int b;

	while (*a != '\0')
	{
		a++;
		len++;
	}
	l = len - 1;
	for (b = 0 ; b <= l ; b++)
	{
		if (b % 2 == 0)
		{
			_putchar(str[b]);
		}
	}
	_putchar('\n');
}
