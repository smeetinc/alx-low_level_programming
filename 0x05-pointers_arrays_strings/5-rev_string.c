/**
 * rev_string - reverse a string function
 * @s: function param
 * Return: void
 */

void rev_string(char *s)
{
	int i, j;
	char a;

	for (i = 0; s[i] != '\0'; ++i)
		;
	for (j = 0; j < i / 2; ++j)
	{
		a = s[j];
		s[j] = s[i - 1 - j];
		s[i - 1 - j] = a;
	}
}
