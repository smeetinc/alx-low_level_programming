#include "main.h"

/**
 * _showaddr - prints address
 * @ptr: func param
 * Return: void
 */
void _showaddr(char *ptr)
{
	int i;
	int begin;
	char sys;

	printf("  Entry point address:               0x");

	sys = ptr[4] + '0';
	if (sys == '1')
	{
		begin = 26;
		printf("80");
		for (i = begin; i >= 22; i--)
		{
			if (ptr[i] > 0)
				printf("%x", ptr[i]);
			else if (ptr[i] < 0)
				printf("%x", 256 + ptr[i]);
		}
		if (ptr[7] == 6)
			printf("00");
	}

	if (sys == '2')
	{
		begin = 26;
		for (i = begin; i > 23; i--)
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
 * _showtype - prints type
 * @ptr: func param.
 * Return: nothing
 */
void _showtype(char *ptr)
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
	else if (type == 2)
		printf("EXEC (Executable file)\n");
	else if (type == 3)
		printf("DYN (Shared object file)\n");
	else if (type == 4)
		printf("CORE (Core file)\n");
	else
		printf("<unknown: %x>\n", type);
}

/**
 * _showosabi - prints osabi
 * @ptr: func param.
 * Return: void return.
 */
void _showosabi(char *ptr)
{
	char osabi = ptr[7];

	printf("  OS/ABI:                            ");
	if (osabi == 0)
		printf("UNIX - System V\n");
	else if (osabi == 2)
		printf("UNIX - NetBSD\n");
	else if (osabi == 4)
		printf("UNIX - Linux\n");
	else if (osabi == 6)
		printf("UNIX - Solaris\n");
	else
		printf("<unknown: %x>\n", osabi);

	printf("  ABI Version:                       %d\n", ptr[8]);
}


/**
 * _showversion - prints version
 * @ptr: func param.
 * Return: nothing.
 */
void _showversion(char *ptr)
{
	int version = ptr[6];

	printf("  Version:                           %d", version);

	if (version == EV_CURRENT)
		printf(" (current)");

	printf("\n");
}
/**
 * _showdata - prints data
 * @ptr: func param.
 * Return: void
 */
void _showdata(char *ptr)
{
	char data = ptr[5];

	printf("  Data:                              2's complement");
	if (data == 1)
		printf(", little endian\n");

	if (data == 2)
		printf(", big endian\n");
}
/**
 * _showmagic - prints magic info.
 * @ptr: func param.
 * Return: still void.
 */
void _showmagic(char *ptr)
{
	int bytes;

	printf("  Magic:  ");

	for (bytes = 0; bytes < 16; bytes++)
		printf(" %02x", ptr[bytes]);

	printf("\n");

}

/**
 * check_sys_version - check the version system.
 * @ptr: func param.
 * Return: void return.
 */
void check_sys_version(char *ptr)
{
	char sys = ptr[4] + '0';

	if (sys == '0')
		exit(98);

	printf("ELF Header:\n");
	_showmagic(ptr);

	if (sys == '1')
		printf("  Class:                             ELF32\n");

	if (sys == '2')
		printf("  Class:                             ELF64\n");

	_showdata(ptr);
	_showversion(ptr);
	_showosabi(ptr);
	_showtype(ptr);
	_showaddr(ptr);
}

/**
 * _elf_check - check if it is an elf file.
 * @ptr: func param.
 * Return: 1 || 0.
 */
int _elf_check(char *ptr)
{
	int addr = (int)ptr[0];
	char E = ptr[1];
	char L = ptr[2];
	char F = ptr[3];

	if (addr == 127 && E == 'E' && L == 'L' && F == 'F')
		return (1);

	return (0);
}

/**
 * main - program entry point.
 * @argc: number of arguments.
 * @argv: arguments vector.
 * Return: 0 on success.
 */
int main(int argc, char *argv[])
{
	int fd, r_read;
	char ptr[27];

	if (argc != 2)
	{
		dprintf(STDERR_FILENO, "Usage: elf_header elf_filename\n");
		exit(98);
	}

	fd = open(argv[1], O_RDONLY);

	if (fd < 0)
	{
		dprintf(STDERR_FILENO, "Error: file can not be open\n");
		exit(98);
	}

	lseek(fd, 0, SEEK_SET);
	r_read = read(fd, ptr, 27);

	if (r_read == -1)
	{
		dprintf(STDERR_FILENO, "Error: The file can not be read\n");
		exit(98);
	}

	if (!_elf_check(ptr))
	{
		dprintf(STDERR_FILENO, "Error: It is not an ELF\n");
		exit(98);
	}

	check_sys_version(ptr);
	close(fd);

	return (0);
}
