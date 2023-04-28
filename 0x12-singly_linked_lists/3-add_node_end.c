#include "lists.h"
/**
 * add_node_end - adds a new node at the end of list
 * @head: func param 1
 * @str: func param 2
 * Return: addr of head
 */

list_t *add_node_end(list_t **head, const char *str)
{
	list_t *new, *tmp;
	size_t newchar;

	new = malloc(sizeof(list_t));
	if (new == NULL)
		return (NULL);

	new->str = strdup(str);

	for (newchar = 0; str[newchar]; newchar++)
		;
	new->len = newchar;
	new->next = NULL;
	tmp = *head;
	if (tmp == NULL)
	{
		*head = new;
	}
	else
	{
		while (tmp->next != NULL)
			tmp = tmp->next;
		tmp->next = new;
	}
	return (*head);
}
