#include <unistd.h>

/**
 * _putchar - write to stdout
 * @c: func param
 * Return: 1 || -1
 */

int _putchar(char c)
{
	return (write(1, &c, 1));
}
