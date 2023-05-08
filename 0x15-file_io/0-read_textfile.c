#include "main.h"

/**
 * read_textfile - reads text files and prints
 * @filename: func input 1
 * @letters: func input 2
 * Return: 0 to exit if fail
 */

ssize_t read_textfile(const char *filename, size_t letters)
{
	int file_des;
	ssize_t check_read, word_count;
	char *buffer;

	
	if (!filename)
		return (0);
	file_des = open(filename, O_RDONLY);
	if (file_des == -1)
		return (0);

	buffer = malloc(sizeof(char) * letters);
	if (!buffer)
	{
		free (buffer);
		return (0);
	}
	check_read = read(file_des, buffer, letters);
	if (check_read == -1)
		return (0);
	word_count = write(STDOUT_FILENO, buffer, check_read);
	if (word_count == -1 || check_read != word_count)
		return (0);
	free(buffer);
	close(file_des);
	return (word_count);
}
