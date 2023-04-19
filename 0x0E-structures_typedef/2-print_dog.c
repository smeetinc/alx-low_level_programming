#include "dog.h"
#include <stdio.h>

/**
 * print_dog - function to print dog
 * @d: the function param
 * Return: void
 */

void print_dog(struct dog *d)
{
	if (d != NULL)
	{
		printf("Name: ");
		(*d).name == NULL ? printf("(nil)\n") : printf("%s\n", (*d).name);
		printf("Age: %f\n", d->age);
		printf("Owner: ");
		d->owner == NULL ? printf("(nil)\n") : printf("%s\n", (*d).owner);
	}
}
