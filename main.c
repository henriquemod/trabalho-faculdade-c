#include <stdio.h>
#include <stdlib.h>

enum PetSize
{
    SMALL,
    MEDIUM,
    LARGE
};

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

struct Address
{
    char street[64];
    char city[32];
    char state[2];
    char complement[128];
    int number;
};

struct Pet
{
    char name[16];
    char breed[32];
    int weight;
    enum PetSize size;
};

struct Person
{
    char name[16];
    char subName[16];
    char phoneNumber[32];
    struct Pet pet;
    struct Address address;
};

struct Person createPerson(struct Person *person)
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
}

int main()
{
    struct Person *person = NULL;
    person = (struct Person *)malloc(sizeof(struct Person));
    if (person == NULL)
    {
        printf("Memory allocation failed\n");
        exit(1);
    }

    createPerson(person);

    printf("Name:\n\t%s %s\n", person->name, person->subName);
    printf("Phone number:\n\t%s\n", person->phoneNumber);
    printf("Pet:\n\t%s\n\t%s\n", person->pet.name, person->pet.breed);
    printf("\tSize: %s\n", getSizeString(person->pet.size));
    printf("Address:\n\t%s n%d%s\n", person->address.street, person->address.number, person->address.complement);
    printf("\t%s -  %s\n", person->address.city, person->address.state);

    free(person);
    person = NULL;

    return 0;
}
