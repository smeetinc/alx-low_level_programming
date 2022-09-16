#include "main.h"

/**
 * _isupper - vary return value based on character case
 * @c : function parameter
 * Return: varies depending on condition
 */

int _isupper(int c)
{
	if (c >= 'A' && c <= 'Z')
	{
		return (1);
	}
	else
	{
		return (0);
	}
}
