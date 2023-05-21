#include "main.h"

/**
 * append_text_to_file - appends text
 * @filename: name of file
 * @text_content: content in file
 * Return: 1 || -1
 */

int append_text_to_file(const char *filename, char *text_content)
{
	int file_des, numlets, perm;

	if (!filename)
		return (-1);
	file_des = open(filename, O_WRONLY | O_APPEND);
	if (file_des == -1)
		return (-1);
	if (text_content)
	{
		for (numlets = 0; text_content[numlets]; numlets++)
			;
		perm = write(file_des, text_content, numlets);
		if (perm == -1)
			return (-1);
	}
	close(file_des);
	return (1);
}
