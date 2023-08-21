/**
 * _strncpy -  function to copy string
 * @dest: pointer to dest
 * @src: pointer to source
 * @n: source bytes
 * Return: destination pointer
 */

char *_strncpy(char *dest, char *src, int n)
{
	int i;

	for (i = 0; i < n && src[i] != '\0'; i++)
		dest[i] = src[i];
	while (i < n)
	{
		dest[i] = '\0';
		i++;
	}
	return (dest);
}
