#include "main.h"

/**
 * print_alphabet - function to print abc
 * Return: no return value, so void
 */

void print_alphabet(void)
{
	char c;

	for (c = 'a'; c <= 'z'; c++)
	{
		_putchar(c);
	}
	_putchar('\n');
}
