#include <stdlib.h>
#include "dog.h"

/**
 * free_dog - function to free up memory
 * @d: function param
 * Return: void
 */

void free_dog(dog_t *d)
{
	if (d)
	{
		free((*d).name);
		free(d->owner);
		free(d);
	}
}
