/**
 * _strcat - function to concatenate two strings
 * @dest: destination string
 * @src: source string
 * Return: pointer to dest string
 */

char *_strcat(char *dest, char *src)
{
	int a, b;

	a = 0;
	while (dest[a])
		a++;

	for (b = 0; src[b]; b++)
		dest[a++] = src[b];

	return (dest);
}

