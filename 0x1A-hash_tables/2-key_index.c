#include "hash_tables.h"

/**
 * key_index - func to give key index
 * @key: func param 1
 * @size: func param 2
 * Return: 0 || key index
 */

unsigned long int key_index(const unsigned char *key, unsigned long int size)
{
	if (key == NULL || size == 0)
		return (0);
	return (hash_djb2(key) % size);
}
