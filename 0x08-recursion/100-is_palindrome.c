#include "main.h"

/**
 * _strlen_recursion - func to return length of str
 * @str: func param
 * *Return: str
 */

int _strlen_recursion(char *str)
{
	if (*str == '\0')
		return (0);
	else
		return (1 + _strlen_recursion(str + 1));
}

/**
 * compare_recursion - compare characters
 * @str: func param 1
 * @i: func param 2
 * @j: func param 3
 * Return: 0 to exit
 */

int compare_recursion(char *str, int i, int j)
{
	if (*(str + i) == *(str + j))
	{
		if (i == j || i == j + 1)
			return (1);
		return (0 + compare_recursion(str, i + 1, j - 1));
	}
	return (0);
}

/**
 * is_palindrome - check if string is a palindrome
 * @s: func param
 * Return: 1 || 0
 */

int is_palindrome(char *s)
{
	if (*s == '\0')
		return (1);
	return (compare_recursion(s, 0, _strlen_recursion(s) - 1));
}
