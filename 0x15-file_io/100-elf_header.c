#include "main.h"

/**
 * e_ident[] - set initial bytes mark
 */

/**
 * _elf_check - ELF status
 * @e_ident: pointer to array of bytes
 * Return: void
 */

void _elf_check(unsigned char *e_ident)
{
	int index = 0;

	while (index < 4)
	{
		if (e_ident[index] != 127 && 
			e_ident[index] != 'E' &&
			e_ident[index] != 'L' &&
			e_ident[index] != 'F')
		{
			dprintf(STDERR_FILENO, "Error: Not an ELF file\n");
			exit(98);
		}
		index++;
	}
}

/**
 * _magic - shoe magic number
 * @e_ident: pointer to array of bytes
 * Return: void
 */

void _magic(unsigned char *e_ident)
{
	int index = 0;
	
	printf("  Magic    ");
	while (index < EI_NIDENT)
	{
		printf("%02x", e_ident[index]);
		if (index == EI_NIDENT -1)
			printf("\n");
		else
			printf(" ");
		index++;
	}
}

/**
 * _showclass - print class of ELF file
 * @e_ident: func param
 * return: void
 */

void _showclass(unsigned char *e_ident)
{
	printf("  Class:                             ");

	switch (e_ident[EI_CLASS])
	{
		case ELFCLASSNONE:
			printf("none\n");
			break;
		case ELFCLASS32:
			printf("ELF32\n");
			break;
		case ELFCLASS64:
			printf("ELF64\n");
			break;
		default:
			printf("<unknown: %x>\n", e_ident[EI_CLASS]);
	}
}
/**
 * _showdata - shows data encoding of ELF
 * @e_ident: func param
 * Return: void
 */

void _showdata(unsigned char *e_ident)
{
	printf("  Data:                              ");
	switch (e_ident[EI_DATA])
	{
		case ELFDATANONE:
			printf("none\n");
			break;
		case ELFDATA2LSB:
			printf("2's complement, little endian\n");
			break;
		case ELFDATA2MSB:
			printf("2's complement, big endian\n");
			break;
		default:
			printf("<unknown: %x>\n", e_ident[EI_DATA]);
	}
}

/**
 * _showversion - give version of ELF file
 * @e_ident: func param
 * Return: void
 */

void _showversion(unsigned char *e_ident)
{
	printf("  Version:                           ");
	if (e_ident[EI_VERSION] == EV_CURRENT)
		printf("%d (current)\n", e_ident[EI_VERSION]);
	else
		printf("%i\n", e_ident[EI_VERSION]);
}

/**
 * _showosabi - print OS/ABI
 * @e_ident: func param
 * Return: void
 */

void _showosabi(unsigned char *e_ident)
{
	printf("  OS/ABI:                            ");
	switch (e_ident[EI_OSABI])
	{
		case ELFOSABI_SYSV:
			printf("UNIX - System V\n");
			break;
		case ELFOSABI_HPUX:
			printf("UNIX - HP-UX\n");
			break;
		case ELFOSABI_NETBSD:
			printf("UNIX - NetBSD\n");
			break;
		case ELFOSABI_LINUX:
			printf("UNIX - Linux\n");
			break;
		case ELFOSABI_SOLARIS:
			printf("UNIX - Solaris\n");
			break;
		case ELFOSABI_AIX:
			printf("UNIX - AIX\n");
			break;
		case ELFOSABI_IRIX:
			printf("UNIX - IRIX\n");
			break;
		case ELFOSABI_FREEBSD:
			printf("UNIX - FreeBSD\n");
			break;
		case ELFOSABI_ARM:
			printf("ARM\n");
			break;
		case ELFOSABI_TRU64:
			printf("UNIX - TRU64\n");
			break;
		case ELFOSABI_STANDALONE:
			printf("Standalone App\n");
			break;
		default:
			printf("<unknown: %x>\n", e_ident[EI_OSABI]);
	}
}

/**
 * _showabi: show abi
 * @e_ident: func param
 * Return: void
 */

void _showabi(unsigned char *e_ident)
{
	printf("  ABI Version:                       %d\n",
			e_ident[EI_ABIVERSION]);
}

/**
 * _showtype - give ELF type
 * @e_type: func param 1
 * @e_ident: func param 2
 * Return: void
 */

void _showtype(unsigned int e_type, unsigned char *e_ident)
{
	if (e_ident[EI_DATA] == ELFDATA2MSB)
		e_type >>= 8;
	printf("  Type:                              ");
	switch (e_type)
	{
		case ET_NONE:
			printf("NONE (Unknown type)\n");
			break;
		case ET_REL:
			printf("REL (Relocatable file)\n");
			break;
		case ET_EXEC:
			printf("EXEC (Executable file)\n");
			break;
		case ET_DYN:
			printf("DYN (Shared object file)\n");
			break;
		case ET_CORE:
			printf("CORE (Core file)\n");
			break;
		default:
			printf("<unknown: %x\n", e_type);
	}
}

/**
 * _showentry - give elf file entry point
 * @e_entry: func param 1
 * @e_ident: func param 2
 * Return: void
 */

void _showentry(unsigned long int e_entry, unsigned char *e_ident)
{
	printf("  Entry point address:               ");
	if (e_ident[EI_DATA] == ELFDATA2MSB)
	{
		e_entry = ((e_entry << 8) & 0xFF00FF00) |
			((e_entry >> 8) & 0xFF00FF);
		e_entry = (e_entry << 16) | (e_entry >> 16);
	}
	if (e_ident[EI_CLASS] == ELFCLASS32)
		printf("%#x\n", (unsigned int)e_entry);
	else
		printf("%#lx\n", e_entry);
}

/**
 * _close - close the file
 * @elf_file: func param
 * Return: void
 */

void _close(int elf_file)
{
	if (close(elf_file) == -1)
	{
		dprintf(STDERR_FILENO,
				"Error: can't close fd %d\n", elf_file);
		exit(98);
	}
}

/**
 * main - prog entry point
 * @argc: args count
 * @argv: array of instructions
 * Return: 0 to finish
 */

int main(int __attribute__((__unused__)) argc, char *argv[])
{
	Elf64_Ehdr *elf;
	int elf_file, r_file;

	printf("\n");
	elf_file = open(argv[1], O_RDONLY);
	if (elf_file == -1)
	{
		dprintf(STDERR_FILENO, "Error: Can't read file %s\n", argv[1]);
		exit(98);
	}
	elf = malloc(sizeof(Elf64_Ehdr));
	if (elf == NULL)
	{
		_close(elf_file);
		free(elf);
		dprintf(STDERR_FILENO, "Error; Can't read file %s\n", argv[1]);
		exit(98);
	}
	r_file = read(elf_file, elf, sizeof(Elf64_Ehdr));
	if (r_file == -1)
	{
		free(elf);
		_close(elf_file);
		dprintf(STDERR_FILENO, "Error: `%s`: No such file\n", argv[1]);
		exit(98);
	}
	_elf_check(elf->e_ident);
	printf("ELF Header:\n");
	_magic(elf->e_ident);
	_showclass(elf->e_ident);
	_showdata(elf->e_ident);
	_showversion(elf->e_ident);
	_showosabi(elf->e_ident);
	_showabi(elf->e_ident);
	_showtype(elf->e_type, elf->e_ident);
	_showentry(elf->e_entry, elf->e_ident);
	free(elf);
	_close(elf_file);
	return (0);
}
