#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/**
 * main - Generates and prints passwords.
 * @argc: args count
 * @argv: prog array
 * Return: 0 || 1
 */

int main(int argc, char **argv)
{
	char password[8];
	char *str;
	int len = strlen(argv[1]), i, tmp;

	str = "A-CHRDw87lNS0E9B2TibgpnMVys5XzvtOGJcYLU+4mjW6fxqZeF3Qa1rPhdKIouk";
	if (argc != 2)
	{
		printf("Usage: %s <username>\n", argv[0]);
		return (1);
	}
	tmp = (len ^ 59) & 63;
	password[0] = str[tmp];
	tmp = 0;
	for (i = 0; i < len; i++)
		tmp += argv[1][i];
	password[1] = str[(tmp ^ 79) & 63];
	tmp = 1;
	for (i = 0; i < len; i++)
		tmp *= argv[1][i];
	password[2] = str[(tmp ^ 85) & 63];
	tmp = 0;
	for (i = 0; i < len; i++)
	{
		if (argv[1][i] > tmp)
			tmp = argv[1][i];
	}
	srand(tmp ^ 14);
	password[3] = str[rand() & 63];
	tmp = 0;
	for (i = 0; i < len; i++)
		tmp += (argv[1][i] * argv[1][i]);
	password[4] = str[(tmp ^ 239) & 63];
	for (i = 0; i < argv[1][0]; i++)
		tmp = rand();
	password[5] = str[(tmp ^ 229) & 63];
	password[6] = '\n';
	password[7] = '\0';
	printf("%s", password);
	return (0);
}
