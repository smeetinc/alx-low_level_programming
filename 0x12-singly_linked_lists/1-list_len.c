#include "list.h"
/**
 * list_len - returns the number of elements in a list
 * @h:func param
 * Return: number of elemnts
 */

size_t list_len(const list_t *h)
{
	size_t mylist;

	mylist = 0;
	while (h!=NULL)
	{
		h = h->next;
		mylist++;
	}
	return (mylist);
}
