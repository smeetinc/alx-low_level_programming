#ifndef DOG_H
#define DOG_H

/**
 * struct dog - the description of the dog struct
 * @name: the name of the dog variable
 * @age: age of the dog variable
 * @owner: The dog owner variable
 */

struct dog
{
	char *name;
	float age;
	char *owner;

	/* Dog struct */
};

typedef struct dog dog_t;

void init_dog(struct dog *d, char *name, float age, char *owner);
void print_dog(struct dog *d);
dog_t *new_dog(char *name, float age, char *owner);
void free_dog(dog_t *d);

#endif
