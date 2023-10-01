#include <stdio.h>
#include <stdlib.h>
#include "../entities/person.h"

const char *getSizeString(enum PetSize size)
{
    switch (size)
    {
    case SMALL:
        return "Pequeno";
    case MEDIUM:
        return "Medio";
    case LARGE:
        return "Grande";
    default:
        return "unknown";
    }
}

void createUser()
{
    struct Person *person = NULL;
    person = (struct Person *)malloc(sizeof(struct Person));
    if (person == NULL)
    {
        printf("Memory allocation failed\n");
        exit(1);
    }

    newPerson(person);

    printf("Name:\n\t%s %s\n", person->name, person->subName);
    printf("Phone number:\n\t%s\n", person->phoneNumber);
    printf("Pet:\n\t%s\n\t%s\n", person->pet.name, person->pet.breed);
    printf("\tSize: %s\n", getSizeString(person->pet.size));
    printf("Address:\n\t%s n%d%s\n", person->address.street, person->address.number, person->address.complement);
    printf("\t%s -  %s\n", person->address.city, person->address.state);

    free(person);
    person = NULL;
}