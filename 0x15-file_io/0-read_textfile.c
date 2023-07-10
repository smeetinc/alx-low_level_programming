#include "main.h"

/**
 * read_textfile - read and print txt
 * @filename: name of file
 * @letters: num letters printed
 * Return: 0 on fail
 */

ssize_t read_textfile(cont char *filename, size_t letters)
{
	int fd;
	ssize_t numrd, numwrt;
	char *buffer;

	if (!filename)
		return (0);
	fd = open(filename, O_RDONLY);

	if (fd == -1)
		return (0);
	buffer = malloc(sizeof(char) * (letters));
	if (!buffer)
		return (0);
	numrd = read(fd, buffer, letters);
	numwrt = write(STDOUT_FILENO, buffer, numrd);
	close(fd);
	free(buffer);
	return (numwrt);
}
