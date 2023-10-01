#include <stdio.h>
#include <stdlib.h>
#include "address.h"
#include "pet.h"

struct Person
{
    char name[16];
    char subName[16];
    char phoneNumber[32];
    struct Pet pet;
    struct Address address;
};

struct Person newPerson(struct Person *person)
{
    printf("Nome: ");
    scanf("%[^\n]", person->name);
    getchar();
    printf("Sobrenome: ");
    scanf("%[^\n]", person->subName);
    getchar();
    printf("Nome do pet: ");
    scanf("%[^\n]", person->pet.name);
    getchar();
    printf("Enter your pet breed: ");
    scanf("%[^\n]", person->pet.breed);
    getchar();
    printf("Peso do pet em kg: ");
    scanf("%d", &person->pet.weight);
    getchar();
    printf("Porte do pot (0 - Pequeno, 1 - Medio, 2 - Grande): ");
    int size;
    scanf("%d[^\n]", &size);
    getchar();
    person->pet.size = (enum PetSize)size;
    printf("Telefone: ");
    scanf("%[^\n]", person->phoneNumber);
    getchar();
    printf("Endereço\n");
    printf("Rua: ");
    scanf("%[^\n]", person->address.street);
    getchar();
    printf("Numero: ");
    scanf("%d", &person->address.number);
    getchar();
    printf("Complemento: ");
    scanf("%[^\n]", person->address.complement);
    getchar();
    printf("Cidade: ");
    scanf("%[^\n]", person->address.city);
    getchar();
    printf("Estado (SC,RJ,SP,etc...): ");
    scanf("%[^\n]", person->address.state);
    getchar();

    return *person;
}