#include <stdio.h>

/**
 * main - prints arg count
 * @argc: arg count
 * @argv: array with command
 * Return: 0 to exit on success
 */

int main(int argc, char *argv[] __attribute__((unused)))
{
	printf("%d\n", argc - 1);
	return (0);
}
