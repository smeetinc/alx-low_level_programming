#include <unistd.h>
#include "main.h"

/**
 * _putchar - test my ouput
 * @c: param
 * Return: 1or -1
 */

int _putchar(char c)
{
	return (write(1, &c, 1));
}
