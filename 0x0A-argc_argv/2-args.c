#include <stdio.h>

/**
 * main - print out all args given
 * @argc: arg count
 * @argv: array with command
 * Return: 0 to exit on success
 */

int main(int argc, char *argv[])
{
	int i;

	for (i = 0; i < argc; i++)
		printf("%s\n", argv[i]);
	return (0);
}
