#include "lists.h"

/**
 * free_dlistint - function that frees a dlistint_t list
 * @head: node head
 * Return: nothing
 */

void free_dlistint(dlistint_t *head)
{
	dlistint_t *current = head;
	dlistint_t *next;

	while (current != NULL)
	{
		next = current->next;
		free(current);
		current = next;
	}
}
