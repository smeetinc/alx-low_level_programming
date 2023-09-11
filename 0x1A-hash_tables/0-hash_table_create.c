#include "hash_tables.h"

/**
 * hash_table_create - func to create hash table
 * @size: size of array
 * Return: NULL || pointer
 */

hash_table_t *hash_table_create(unsigned long int size)
{
	hash_table_t *hashTable;
	unsigned long int i;

	hashTable = malloc(sizeof(hash_table_t));
	if (hashTable == NULL)
		return (NULL);
	hashTable->size = size;
	hashTable->array = malloc(sizeof(hash_node_t *) * size);
	if (hashTable->array == NULL)
		return (NULL);
	for (i = 0; i < size; i++)
		hashTable->array[i] = NULL;
	return (hashTable);
}
