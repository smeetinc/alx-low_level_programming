#include "main.h"

/**
 * create_file - func to create file
 * @filename: name of file
 * @text_content: as name implies
 * Return: 1 || -1 on success or failure
 */

int create_file(const char *filename, char *text_content)
{
	int fd, numletrs, rwr;

	if (!filename)
		return (-1);
	fd = open(filename, O_CREAT | O_WRONLY | O_TRUNC, 0600);

	if (fd == -1)
		return (-1);
	if (!text_content)
		text_content = "";
	for (numletrs = 0; text_content[numletrs]; numletrs++)
		;
	rwr = write(fd, text_content, numletrs);
	if (rwr == -1)
		return (-1);
	close(fd);
	return (1);
}
