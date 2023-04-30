#include <stdio.h>

/**
 * main - func to print its name
 * @argc: arg count
 * @argv: array with command
 * Return: 0 to exit with success
 */

int main(int argc __attribute__((unused)), char *argv[])
{
	printf("%s\n", argv[0]);
	return (0);
}
