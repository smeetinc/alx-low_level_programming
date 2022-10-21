#include <stdio.h>
#include "lists.h"
#include <stdlib.h>

/**
 * print_list - prints all elements of a list_t list
 * @h: singly linked list to print
 * Return: number of nodes in the list
 */

size_t print_list(const list_t *h)
{
	const list_t *tmp;
	unsigned int i;

	tmp = h;
	for (i = 0; tmp; i++)
	{
		if (tmp->str != NULL)
			printf("[%u] %s\n", tmp->len, tmp->str);
		else
			printf("[0] (nil)\n");
		tmp = tmp->next;
	}
	return (i);
}
