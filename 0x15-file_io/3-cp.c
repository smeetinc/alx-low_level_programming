#include "main.h"
#include <stdio.h>

/**
 * error_check - check error on file
 * @file_src: source file
 * @file_to: file des
 * @argv: arg vector
 * Return: void
 */

void error_check(int file_src, int file_to, char *argv[])
{
	if (file_src == -1)
	{
		dprintf(STDERR_FILENO, "Error: Can't read from file %s\n", argv[1]);
		exit(98);
	}
	if (file_to == -1)
	{
		dprintf(STDERR_FILENO, "Error: Can't write to %s\n", argv[2]);
		exit(99);
	}
}

/**
 * main - code entry
 * @argc: num of args
 * @argv:array of progs
 * Return: 0
 */

int main(int argc, char *argv[])
{
	int file_src, file_to, close_err;
	ssize_t numchars, nwr;
	char buffer[1024];

	if (argc != 3)
	{
		dprintf(STDERR_FILENO, "%s\n", "Usage: cp file_src file_to");
		exit(97);
	}
	file_src = open(argv[1], O_RDONLY);
	file_to = open(argv[2], O_CREAT | O_WRONLY | O_TRUNC | O_APPEND, 0664);
	error_check(file_src, file_to, argv);

	numchars = 1024;
	while (numchars == 1024)
	{
		numchars = read(file_src, buffer, 1024);
		if (numchars == -1)
			error_check(-1, 0, argv);
		nwr = write(file_to, buffer, numchars);
		if (nwr == -1)
			error_check(0, -1, argv);
	}
	close_err = close(file_src);
	if (close_err == -1)
	{
		dprintf(STDERR_FILENO, "Error: Can't close fd %d \n", file_src);
		exit(100);
	}
	close_err = close(file_to);
	if (close_err == -1)
	{
		dprintf(STDERR_FILENO, "Error: Can't close fd %d \n", file_src);
		exit(100);
	}
	return (0);
}
