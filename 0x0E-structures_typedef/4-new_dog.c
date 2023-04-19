#include <stdlib.h>
#include "dog.h"

/**
 * _strlen - Function to get string length
 * @str: function param
 * Return: str value
 */

int _strlen(const char *str)
{
	int l = 0;

	while (*str++)
		l++;
	return (l);
}

/**
 * _strcopy - function to copy string
 * @src: func param 1
 * @dest: func param 2
 * Return: copied string
 */

char *_strcopy(char *dest, char *src)
{
	int i;

	for (i = 0; src[i]; i++)
		dest[i] = src[i];
	dest[i] = '\0';
	return (dest);
}

/**
 * new_dog - Function to create a new dog
 * @name: dog name
 * @age: dog age
 * @owner: dog owner
 * Return: struct pointer dog or NULL
 */

dog_t *new_dog(char *name, float age, char *owner)
{
	dog_t *dog;

	if (!name || age < 0 || !owner)
		return (NULL);

	dog = (dog_t *) malloc(sizeof(dog_t));
	if (dog == NULL)
		return (NULL);

	(*dog).name = malloc(sizeof(char) * (_strlen(name) + 1));
	if ((*dog).name == NULL)
	{
		free(dog);
		return (NULL);
	}

	(*dog).owner = malloc(sizeof(char) * (_strlen(owner) + 1));
	if ((*dog).owner == NULL)
	{
		free((*dog).name);
		free(dog);
		return (NULL);
	}

	(*dog).name = _strcopy(dog->name, name);
	dog->age = age;
	dog->owner = _strcopy(dog->owner, owner);
	return (dog);
}
