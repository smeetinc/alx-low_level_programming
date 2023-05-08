#ifndef _MAIN_H
#define _MAIN_H

#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include <fcntl.h>
#include <stdlib.h>

ssize_t read
_textfile(const char *filename, size_t letters);
int creat_file(const char *filename, char *text_content);
int append_text_to_file(const char *filename, char *text_content);

#endif


