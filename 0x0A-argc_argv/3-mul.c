#include <stdio.h>
#include <stdlib.h>

/**
 * main - func to multiply two numbers
 * @argc: arg count
 * @argv: array with command
 * Return: 0 to exit on success
 */

int main(int argc, char *argv[])
{
	int mul;

	if (argc != 3)
	{
		printf("Error\n");
		return (1);
	}
	mul = atoi(argv[1]) * atoi(argv[2]);
	printf("%d\n", mul);
	return (0);
}
