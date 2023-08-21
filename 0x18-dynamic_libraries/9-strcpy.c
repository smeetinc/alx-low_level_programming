/**
 * _strcpy - function to copy a string from a pointer to another
 * @src: source string
 * @dest: destination string
 * Return: dest pointer
 */

char *_strcpy(char *dest, char *src)
{
	int a, b = 0;

	for (a = 0; src[a] != '\0'; ++a)
	{
		dest[b] = src[a];
		++b;
	}
	dest[b] = '\0';
	return (dest);
}
