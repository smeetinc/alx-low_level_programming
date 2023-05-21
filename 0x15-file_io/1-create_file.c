#include "main.h"

/**
 * create_file - func to create file
 * @filename: name of file
 * @text_content: content of file
 * Return: 1 || -1
 */

int create_file(const char *filename, char *text_content)
{
	int file_des;
	int numlets;
	int perm;

	if (!filename)
		return (-1);

	file_des = open(filename, O_CREAT | O_WRONLY | O_TRUNC, 0600);
	if (file_des == -1)
		return (-1);
	if (!text_content)
		text_content = "";
	for (numlets = 0; text_content[numlets]; numlets++)
		;
	perm = write(file_des, text_content, numlets);
	if (perm == -1)
		return (-1);
	close(file_des);
	return (1);
}
