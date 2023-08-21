/**
 * _strspn - function to get length of prefix substring
 * @s: func params
 * @accept: func params 2
 * Return: number of bytes in @s
 */

unsigned int _strspn(char *s, char *accept)
{
	int i, j, k;

	i = 0;
	while (s[i] != '\0')
	{
		j = 0;
		k = 1;
		while (accept[j] != '\0')
		{
			if (s[i] == accept[j])
			{
				k = 0;
				break;
			}
			j++;
		}
		if (k == 1)
			break;
		i++;
	}
	return (i);
}
