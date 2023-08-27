#include "lists.h"

/**
 * add_dnodeint - adds new node at the head
 * @head: list head
 * @n: data in list
 * Return: addr of new element
 */

dlistint_t *add_dnodeint(dlistint_t **head, const int n)
{
	dlistint_t *newNode;
	dlistint_t *h;

	newNode = malloc(sizeof(dlistint_t));
	if (newNode == NULL)
		return (NULL);

	newNode->n = n;
	newNode->prev = NULL;
	h = *head;

	if (h != NULL)
	{
		while (h->prev != NULL)
			h = h->prev;
	}
	newNode->next = h;
	if (h != NULL)
		h->prev = newNode;
	*head = newNode;
	return (newNode);
}
