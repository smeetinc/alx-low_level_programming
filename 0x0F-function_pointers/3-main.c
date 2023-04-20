#include "3-calc.h"
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

/**
 * main - Program entry point
 * Description: program to do math operation on two int
 * @argc: argument counter
 * @argv: vector
 * Return: 0 to exit
 */

int main(int argc, char *argv[])
{
	int num1, num2;
	char *func;

	if (argc != 4)
	{
		printf("Error\n");
		exit(98);
	}
	num1 = atoi(argv[1]);
	func = argv[2];
	num2 = atoi(argv[3]);

	if (get_op_func(func) == NULL || func[1] != '\0')
	{
		printf("Error\n");
		exit(99);
	}
	if ((*func == 47 || *func == 37) && num2 == 0)
	{
		printf("Error\n");
		exit(100);
	}
	printf("%d\n", get_op_func(func)(num1, num2));
	return (0);
}
