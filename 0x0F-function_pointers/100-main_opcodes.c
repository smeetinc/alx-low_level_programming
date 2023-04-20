#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/**
 * main - Program entry point
 * Description: program to print opcodes of its function
 * @argc: arg counter
 * @argv: arg vector
 * Return: 0 if okay
 */

int main(int argc, char *argv[])
{
	int i, nbytes;
	char *ptr = (char *) main;

	if (argc != 2)
	{
		printf("Error\n");
		exit(1);
	}
	nbytes = atoi(argv[1]);
	if (nbytes < 0)
	{
		printf("Error\n");
		exit(2);
	}
	for (i = 0; i < nybtes; i++)
	{
		printf("%02x", ptr[i] & 0xFF);
		if (i != nbytes - 1)
			printf(" ");
	}
	printf("\n");
	return (0);
}
