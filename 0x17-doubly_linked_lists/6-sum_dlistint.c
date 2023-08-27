i#include "lists.h"

/**
 * sum_dlistint - function that returns the sum of all the data (n) of a list
 * @head: head
 * Return: sum
 */

int sum_dlistint(dlistint_t *head)
{
	dlistint_t *current = head;
	int sum = 0;

	while (current != NULL)
	{
		sum += current->n;
		current = current->next;
	}

	return (sum);
}
