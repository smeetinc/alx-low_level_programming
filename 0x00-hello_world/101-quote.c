#include <unistd.h>
/**
 * main - Program entry point
 * Description: print text without printf and put function
 * Return: 1 to exit
 */

int main(void)
{
	char q[] = "and that piece of art is useful\" - Dora Korpar, 2015-10-19\n";

	write(1, q, 59);
	return (1);
}
