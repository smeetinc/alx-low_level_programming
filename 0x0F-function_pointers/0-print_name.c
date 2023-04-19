/**
 * print_name - Function to print name
 * @name: function params
 * @f: function pointer with void return value
 * Return: nothing
 */

void print_name(char *name, void (*f)(char *))
{
	if (name && f)
		f(name);
}
