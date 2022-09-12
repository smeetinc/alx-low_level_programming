#include <stdio.h>

/**
 * main - Entry Point
 * Return: Always 0 (Success)
 */

int main(void)
{
	int tens;
	int unit;

	for (tens = 0; tens <= 9; tens++)
	{
		for (unit = 0; unit <= 9; unit++)
		{
			if (unit > tens)
			{
				putchar(tens + '0');
				putchar(unit + '0');
				if (!(tens == 8 && unit == 9))
				{
					putchar(',');
					putchar(' ');
				}
			}
		}
	}
	putchar('\n');
	return (0);
}
