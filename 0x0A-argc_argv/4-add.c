#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>

/**
 * main - func to add positive numbers
 * @argc: arg count
 * @argv: array with command
 * Return: 0 to exit on success
 */

int main(int argc, char *argv[])
{
	int add = 0, i, j;

	for (i = 1; i < argc; i++)
	{
		for (j = 0; argv[i][j] != '\0'; j++)
		{
			if (!isdigit(argv[i][j]))
			{
				printf("Error\n");
				return (1);
			}
		}
		add = add + atoi(argv[i]);
	}
	printf("%d\n", add);
	return (0);
}
