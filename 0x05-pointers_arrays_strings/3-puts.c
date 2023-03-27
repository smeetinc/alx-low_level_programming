#include "main.h"

/**
 * _puts - funtion to print a string with newline at the end
 * @str: function param
 * Return: void
 */

void _puts(char *str)
{
	while (*str != '\0')
	{
		_putchar(*str + 0);
		++str;
	}
	_putchar('\n');
}
