#include "main.h"
#include <stdlib.h>

/**
 * *_strdup - returns a pointer to a newly allocated space with copy of arg
 * @str: string to copy
 * Return: pointer to array or null
 **/

char *_strdup(char *str)
{
	char *strr;
	int i, j;

	if (str == NULL)
		return (NULL);
	i = 0;
	while (str[i] != '\0')
		i++;
	i++;
	strr = malloc(sizeof(*str) * i);
	if (strr == NULL)
		return (NULL);
	j = 0;
	while (str[j] != '\0')
	{
		strr[j] = str[j];
		j++;
	}
	return (strr);
}
