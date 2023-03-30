/**
 * leet - function to encode string
 * @s: function param
 * Return: pointer to function input
 */

char *leet(char *s)
{
	int i, j = 0;
	int sl[] = {97, 101, 11, 116, 108};
	int tl [] = {65, 69, 79, 84, 76};
	int n[] = {52, 51, 48, 55, 49};

	while (s[j] != '\0')
	{
		for (i = 0; i < 5; i++)
		{
			if (s[j] == sl[i] || s[j] == tl[i])
			{
				s[j] = n[i];
				break;
			}
		}
		j++;
	}
	return (s);
}
