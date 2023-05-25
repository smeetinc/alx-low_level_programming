#include "main.h"
#include <stdio.h>

/**
 * check_file -func to check file use state
 * @origin: input 1
 * @dest: input 2
 * @argv: input 3
 * Return: void return
 */

void check_file(int origin, int dest, char *argv[])
{
	if (origin == -1)
	{
		dprintf(STDERR_FILENO, "Error: Can't read from file %s\n", argv[1]);
		exit(98);
	}
	if (dest == -1)
	{
		dprintf(STDERR_FILENO, "Error: Can't write to %s\n", argv[2]);
		exit(99);
	}
}

/**
 * main - program logic to copy
 * @argc: arg count
 * @argv: arg vector
 * Return: an integer for sure
 */

int main(int argc, char *argv[])
{
	int origin, dest, error_on_close;
	ssize_t numchars, perm;
	char buffer[1024];

	if (argc != 3)
	{
		dprintf(STDERR_FILENO, "%s\n", "Usage: cp file_from file_to");
		exit(97);
	}
	origin = open(argv[1], O_RDONLY);
	dest = open(argv[2], O_CREAT | O_WRONLY | O_TRUNC | O_APPEND, 0664);
	check_file(origin, dest, argv);
	numchars = 1024;
	while (numchars == 1024)
	{
		numchars = read(origin, buffer, 1024);
		if (numchars == -1)
			check_file(-1, 0, argv);
		perm = write(dest, buffer, numchars);
		if (perm == -1)
			check_file(0, -1, argv);
	}
	error_on_close = close(origin);
	if (error_on_close == -1)
	{
		dprintf(STDERR_FILENO, "Error: Can't close fd %d\n", origin);
		exit(100);
	}
	error_on_close = close(dest);
	if (error_on_close == -1)
	{
		dprintf(STDERR_FILENO, "Error: Can't close fd %d\n", dest);
		exit(100);
	}
	return (0);
}
