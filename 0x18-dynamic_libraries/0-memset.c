/**
 * _memset - function that fills memory with constant byte
 * @s: function inpuit 1
 * @b: func params
 * @n: func params
 * Return: pointer to @s
 */

char *_memset(char *s, char b, unsigned int n)
{
	unsigned int i;

	for (i = 0; i < n; i++)
		s[i] = b;
	return (s);
}
