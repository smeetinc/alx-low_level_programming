#include "main.h"
#include <stdlib.h>

/**
 * string_nconcat - func to concatenates two strings
 * @s1: func input 1
 * @s2: func input 2
 * @n: func param 3
 * Return: ptr to alloc mem
 */

char *string_nconcat(char *s1, char *s2, unsigned int n)
{
	char *strn;
	unsigned int lis1, lis2, listr, i;

	if (s1 == NULL)
		s1 = "";
	if (s2 == NULL)
		s2 = "";
	for (lis1 = 0; s1[lis1] != '\0'; lis1++)
		;
	for (lis2 = 0; s2[lis2] != '\0'; lis2++)
		;
	if (n > lis2)
		n = lis2;
	listr = lis1 + n;
	strn = malloc(listr + 1);
	if (strn == NULL)
		return (NULL);
	for (i = 0; i < listr; i++)
		if (i < lis1)
			strn[i] = s1[i];
		else
			strn[i] = s2[i - lis1];
	strn[i] = '\0';
	return (strn);
}
