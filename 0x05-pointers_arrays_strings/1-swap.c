/**
 * swap_int - function to swap two integers
 * @a: params 1
 * @b: params 2
 * Return: void
 */

void swap_int(int *a, int *b)
{
	int tmp;

	tmp = *a;
	*a = *b;
	*b = tmp;
}
