// #include "createUser.c"
#include "../entities/person.h"

struct Person findCpf (struct Person *people) 
{
    char cpf[12];
    printf("Digite o CPF: ");
    scanf("%[^\n]", cpf);
    getchar();
    struct Person *person = findPerson(people, cpf);
    if (person == NULL)
    {
        return createUser();
    }
    else
    {
        printf("Nome:\n\t%s %s\n", person->name, person->subName);
        printf("Telefone:\n\t%s\n", person->phoneNumber);
        printf("Pet:\n\t%s\n\t%s\n", person->pet.name, person->pet.breed);
        printf("\tPorte: %s\n", getSizeString(person->pet.size));
        printf("Endereço:\n\t%s n%d%s\n", person->address.street, person->address.number, person->address.complement);
        printf("\t%s -  %s\n", person->address.city, person->address.state);

        return *person;
    }
}