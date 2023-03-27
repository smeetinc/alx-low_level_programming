/**
 * _strlen - returns the length of a string
 * @s: the function parameter
 * Return: the count
 */

int _strlen(char *s)
{
	int count;

	for (count = 0; *s != '\0'; ++s)
	{
		++count;
	}
	return (count);
}
