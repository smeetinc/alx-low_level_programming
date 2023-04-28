#include "lists.h"
/**
 * add_node - func to add nodes
 * @head: head of linked list
 * @str: string
 * Return: addr of the head
 */

list_t *add_node(list_t **head, const char *str)
{
	list_t *new;
	size_t newchar;

	new = malloc(sizeof(list_t));
	if (new == NULL)
		return (NULL);
	new->str = strdup(str);
	for (newchar = 0; str[newchar]; newchar++)
		;
	new->len = newchar;
	new->next = *head;
	*head = new;
	return (*head);
}
