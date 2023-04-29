#include "main.h"
/**
 * strlen_recursion - recursive func to print length
 * @s: func param
 * Return: length of @s
 */

int _strlen_recursion(char *s)
{
	if (*s != '\0')
		return (1 + _strlen_recursion(s + 1));
	else
		return (0);
}
