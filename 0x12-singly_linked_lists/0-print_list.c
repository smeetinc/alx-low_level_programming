#include "lists.h"
/**
 * print_list - this will print al elements of a list
 * @h: singly linked list
 * Return: element count in list
 */

size_t print_list(const list_t *h)
{
	size_t mylist;

	mylist = 0;
	while (h != NULL)
	{
		if (h->str == NULL)
			printf("[%d] %s\n", 0, "(nil)");
		else
			printf("[%d] %s\n", h->len, h->str);
		h = h->next;
		mylist++;
	}
	return (mylist);
}
