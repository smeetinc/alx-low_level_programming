#include "main.h"
#include <stdlib.h>
#include <stdio.h>
#include <ctype.h>

/**
 * check_zero - check num for zero
 * @argv: array with command
 * Return: side effect
 */

void check_zero(char *argv[])
{
	int i;
	int num1_check = 1;
	int num2_check = 1;

	for (i = 0; argv[1][i]; i++)
		if (argv[1][i] != '0')
		{
			num1_check = 0;
			break;
		}
	for (i = 0; argv[2][i]; i++)
		if (argv[2][i] != '0')
		{
			num2_check = 0;
			break;
		}
	if (num1_check == 1 || num2_check == 2)
	{
		printf("0\n");
		exit(0);
	}
}

/**
 * array_init - set initial value of array
 * @my_array: func param 1
 * @array_len: func param 2
 * Return: my_array
 */

char *array_init(char *my_array, int array_len)
{
	int i;

	for (i = 0; i < array_len; i++)
		my_array[i] = '0';
	my_array[array_len] = '\0';
	return (my_array);
}

/**
 * len_check - check length of number
 * @argv: array with command
 * @n: array row
 * Return: len
 */

int len_check(char *argv[], int n)
{
	int len;

	for (len = 0; argv[n][len]; len++)
		if (!isdigit(argv[n][len]))
		{
			printf("Error\n")
				exit(98);
		}
	return (len);
}

/**
 * main - Program entry point
 * @argc: func param 1
 * @argv: func param 2
 * Return: 0 to exit on success
 */

int main(int argc, char *argv[])
{
	int a, b, c, d, e, f, g, h, i;
	char *mul;

	if (argc != 3)
		printf("Error\n"), exit(98);
	a = len_check(argv, 1), b = len_check(argv, 2);
	check_zero(argv), c = a + b, mul = malloc(c + 1);
	if (mul == NULL)
		printf("Error\n"), exit(98);
	mul = array_init(mul, c);
	i = c - 1, f = a - 1, g = b - 1, h = e = 0;
	for (; i >= 0; i--, f--)
	{
		if (f < 0)
		{
			if (e > 0)
			{
				d = (mul[i] - '0') + e;
				if (d > 9)
					mul[i - 1] = (d / 10) + '0';
				mul[i] = (d % 10) + '0';
			}
			f = a - 1, g--, e = 0, h++, i = c - (1 + h);
		}
		if (g < 0)
		{
			if (mul[0] != '0')
				break;
			c--;
			free(mul), mul = malloc(c + 1), mul = array_init(mul, c);
			i = c - 1, f = a - 1, g = b - 1, h = e = 0;
		}
		if (g >= 0)
		{
			d = ((argv[1][f] - '0') * (argv[2][g] - '0')) + (mul[i] - '0') + e;
			e = d / 10, mul[i] = (d % 10) + '0';
		}
	}
	printf("%s\n", mul);
	return (0);
}

