/**
 * _strchr - function to locate a character in a string
 * @s: func param
 * @c: func param
 * Return: first character or null
 */

char *_strchr(char *s, char c)
{
	while (*s != '\0')
	{
		if (*s == c)
			return (s);
		s++;
	}
	if (*s == c)
		return (s);
	return ('\0');
}
