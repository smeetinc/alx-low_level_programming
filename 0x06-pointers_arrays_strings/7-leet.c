#include "main.h"
/**
 * leet - function to encode string
 * @s: function param
 * Return: pointer to function input
 */

char *leet(char *s)
{
	int i, j;
	char s1[] = "aAeEoOtTlL";
	char s2[] = "4433007711";

	for (i = 0; s[i] != '\0'; i++)
	{
		for (j = 0; j < 10; j++)
		{
			if (s[i] == s1[j])
			{
				s[i] = s2[j];
			}
		}
	}
	return (s);
}
