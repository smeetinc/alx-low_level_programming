#include "main.h"
#include <stdlib.h>

/**
 * *string_nconcat - concatenates two strings
 * @s1: first string (first param)
 * @s2: second string (second param)
 * @n: limit of s2 (third param)
 * Return: pointer to new space in memory
 */

char *string_nconcat(char *s1, char *s2, unsigned int n)
{
	char *strr;
	int i;
	unsigned int j;

	if (s1 == NULL)
		s1 = "";
	if (s2 == NULL)
		s2 = "";
	i = 0;
	while (s1[i] != '\0')
		i++;
	strr = malloc(sizeof(char) * (i + n + 1));
	if (strr == NULL)
		return (NULL);
	i = j = 0;
	while (s1[i] != '\0')
	{
		strr[i] = s1[i];
		i++;
	}
	while (j < n && s2[j] != '\0')
	{
		strr[i] = s2[j];
		i++, j++;
	}
	strr[i] = '\0';
	return (strr);
}
