#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/**
 *  is_num_checker - input validation function
 *  @a: function param
 *  Return: num
 */

int is_num_checker(char *a)
{
	int i, num, len;

	i = 0;
	num = 0;
	len = strlen(a);
	while (i < len)
	{
		if (a[i] < '0' || a[i] > '9')
		{
			return (-1);
		}
		else
		{
			num = num * 10 + (a[i] - '0');
		}
		i++;
	}
	return (num);
}

/**
 *   main - add positive numbers
 *   @argc: arguement count
 *   @argv: array of pointers to arguement strings
 *   Return: result
 **/

int main(int argc, char *argv[])
{
	int i, num, sum;

	sum = 0;
	for (i = 1; i < argc; i++)
	{
		num = is_num_checker(argv[i]);
		if (num == -1)
		{
			printf("Error\n");
			return (1);
		}
		sum += num;
	}
	printf("%d\n", sum);
	return (0);
}
