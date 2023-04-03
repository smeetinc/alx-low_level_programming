/**
 * _memcpy - function to copy memory area
 * @dest: where to copy to
 * @src: where to copy from
 * @n: number of bytes of source
 * Return: dest
 */

char *_memcpy(char *dest, char *src, unsigned int n)
{
	unsigned int i;

	for (i = 0; i < n; i++)
		dest[i] = src[i];
	return (dest);
}
