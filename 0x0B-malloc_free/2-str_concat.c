#include "main.h"
#include <stdlib.h>

/**
 * *str_concat - concatenates two strings
 * @s1: first string
 * @s2: second string
 * Return: pointer to new space in memory or null
 */

char *str_concat(char *s1, char *s2)
{
	char *strr;
	int i, j;

	if (s1 == NULL)
		s1 = "";
	if (s2 == NULL)
		s2 = "";
	i = j = 0;
	while (s1[i] != '\0')
		i++;
	while (s2[j] != '\0')
		j++;
	strr = malloc(sizeof(char) * (i + j + 1));
	if (strr == NULL)
		return (NULL);
	i = j = 0;
	while (s1[i] != '\0')
	{
		strr[i] = s1[i];
		i++;
	}
	while (s2[j] != '\0')
	{
		strr[i] = s2[j];
		i++, j++;
	}
	strr[i] = '\0';
	return (strr);
}
