#include "dog.h"

/**
 * init_dog - function to initialize dog struct
 * @d: func param 1
 * @name: func param 2
 * @age: func param 3
 * @owner: func param 4
 * Return: void
 */

void init_dog(struct dog *d, char *name, float age, char *owner)
{
	if (d)
	{
		d->name = name;
		d->age = age;
		d->owner = owner;
	}
}
