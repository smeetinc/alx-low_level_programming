/**
 * _strcmp - function to compare strings
 * @s1: string 1
 * @s2: string 2
 * Return: 0 if s1 and s2 are equal, other signs for otherwise
 */

int _strcmp(char *s1, char *s2)
{
	int i = 0, j;

	while (s1[i] != '\0' && s2[i] != '\0')
	{
		if (s1[i] != s2[i])
		{
			j = s1[i] - s2[i];
			break;
		}
		else
		{
			j = s1[i] - s2[i];
		}
		i++;
	}
	return (j);
}
