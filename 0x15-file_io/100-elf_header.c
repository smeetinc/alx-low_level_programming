#include "main.h"
#include <stdlib.h>
#include <elf.h>
#include <stdio.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <unistd.h>
#include <fcntl.h>

/**
 * _addr - displays addr
 * @ptr: func param
 * Return: void return
 */
void _addr(char *ptr)
{
	int i, startn;
	char sim;

	printf(" Entry point address:               0x");
	sim = ptr[4] + '0';
	if (sim == '1')
	{
		startn = 26;
		printf("80");
		for (i = startn; i >= 22; i--)
		{
			if (ptr[i] > 0)
				printf("%x", ptr[i]);
			else if (ptr[i] < 0)
				printf("%x", 256 + ptr[i]);
		}
		if (ptr[7] == 6)
			printf("00");
	}
	if (sim == '2')
	{
		startn = 26;
		for (i = startn; i > 23; i--)
		{
			if (ptr[i] >= 0)
				printf("%02x", ptr[i]);
			else if (ptr[i] < 0)
				printf("%02x", 256 + ptr[i]);
		}
	}
	printf("\n");
}
/**
 * _type - gets type
 * @ptr: input
 * Return: void too
 */

void _type(char *ptr)
{
	char type = ptr[16];

	if (ptr[5] == 1)
		type = ptr[16];
	else
		type = ptr[17];
	printf("  Type:                              ");
	if (type == 0)
		printf("NONE (No file type)\n");
	else if (type == 1)
		printf("REL (Relocatable file)\n");
	else if (type == 3)
		printf("DYN (Shared object file)\n");
	else if (type == 2)
		printf("EXEC (Executable file)\n");
	else if (type == 4)
		printf("CORE (Core file)\n");
	else
		printf("<unknown: %x>\n", type);
}

/**
 * _osabi - show OS/ABI
 * @ptr: input
 * Return: void also
 */
void _osabi(char *ptr)
{
	char osabi = ptr[7];

	printf("  OS/ABI:                            ");
	if (osabi == 0)
		printf("UNIX - System V\n");
	else if (osabi == 2)
		printf("UNIX - NetBSD\n");
	else if (osabi == 6)
		printf("UNIX - Solaris\n");
	else
		printf("<unknown: %x>\n", osabi);
	printf("  ABI Version:                       %d\n", ptr[8]);
}
/**
 * _version - get version
 * @ptr: input
 * Return: no void too
 */
void _version(char *ptr)
{
	int version = ptr[6];

	printf("  Version:                           %d", version);
	if (version == EV_CURRENT)
		printf(" (current)");
	printf("\n");
}
/**
 * _data - gets data
 * @ptr: input
 * Return: still nothing
 */
void _data(char *ptr)
{
	char data = ptr[5];

	printf("  Data:                              2's complement");
	if (data == 1)
		printf(", little endian\n");
	if (data == 2)
		printf(", big endian\n");
}
/**
 * _magic - for magic information
 * @ptr: input
 * Return: void too
 */

void _magic(char *ptr)
{
	int n;

	printf("  Magic:  ");
	for (n = 0; n < 16; n++)
		printf(" %02x", ptr[n]);
	printf("\n");
}

/**
 * _sys - for system version
 * @ptr: input
 * Return: still void
 */

void _sys(char *ptr)
{
	char sys = ptr[4] + '0';

	if (sys == '0')
		exit(98);
	printf("ELF Header:\n");
	_magic(ptr);
	if (sys == '1')
		printf("  Class:                             ELF32\n");
	if (sys == '2')
		printf("  Class:                             ELF64\n");
	_data(ptr);
	_version(ptr);
	_osabi(ptr);
	_type(ptr);
	_addr(ptr);
}
/**
 * _elf - elf file check
 * @ptr: input
 * Return: 1 || 0
 */
int _elf(char *ptr)
{
	int addr = (int)ptr[0];
	char E = ptr[1], L = ptr[2], F = ptr[3];

	if (addr == 127 && E == 'E' && L == 'L' && F == 'F')
		return (1);
	return (0);
}
/**
 * main - program entry point
 * @argc: arg count
 * @argv: arg vector
 * Return: 0 to exit on success
 */
int main(int argc, char *argv[])
{
	int r_value, fd;
	char ptr[27];

	if (argc != 2)
	{
		dprintf(STDERR_FILENO, "Usage: elf_header elf_filename\n");
		exit(98);
	}
	fd = open(argv[1], O_RDONLY);
	if (fd < 0)
	{
		dprintf(STDERR_FILENO, "Err: Can't open file\n");
		exit(98);
	}
	lseek(fd, 0, SEEK_SET);
	r_value = read(fd, ptr, 27);

	if (r_value == -1)
	{
		dprintf(STDERR_FILENO, "Err: Can't read file\n");
		exit(98);
	}
	if (!_elf(ptr))
	{
		dprintf(STDERR_FILENO, "Err: File not an ELF\n");
		exit(98);
	}
	_sys(ptr);
	close(fd);
	return (0);
}
