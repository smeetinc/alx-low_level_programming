#include "main.h"
/**
 * append_text_to_file - append text func
 * @filename: name of file
 * @text_content: appened text
 * Return: 1 || -1
 */

int append_text_to_file(const char *filename, char *text_content)
{
	int fd, numletrs, rwr;

	if (!filename)
		return (-1);
	fd = open(filename, O_WRONLY | O_APPEND);
	if (fd == -1)
		return (-1);
	if (text_content)
	{
		for (numletrs = 0; text_content[numletrs]; numletrs++)
			;
		rwr = write(fd, text_content, numletrs);
		if (rwr == -1)
			return (-1);
	}
	close(fd);
	return (1);
}
