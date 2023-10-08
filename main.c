#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "structs/service.h"
#include "structs/employee.h"
#include "structs/person.h"

#define INITIAL_DRIVER_SIZE 3;
#define INITIAL_PERSON_SIZE 1;

struct Person client;
struct Order order;

int main()
{
    struct Employee *employees = getEmployees();
    struct Person *persons = getPersons();
    struct Service *services = getServices();
    struct Driver *drivers = getDrivers();
    int numDrivers = INITIAL_DRIVER_SIZE;
    int numPersons = INITIAL_PERSON_SIZE;

    bool authorized = false;
    bool exit = false;

    while (authorized == false)
    {
        bool allowed = authenticate(employees);
        if (allowed == false)
        {
            printf("Usuário ou senha inválidos\n");
        }
        else
        {
            authorized = true;
            system("clear");
        }
    }

    while (exit == false)
    {
        printf("1 - Buscar CPF\n");
        printf("2 - Cadastrar cliente\n");
        printf("3 - Cadastrar motorista\n");
        printf("4 - Sair\n");
        printf("Escolha uma opção: ");
        int option;
        scanf("%d", &option);
        getchar();
        switch (option)
        {
            case 1:
                client = findCpf(persons, numPersons);
                chooseService(services, drivers, numDrivers);
                break;
            case 2:
                numPersons++;
                persons = realloc(persons, sizeof(struct Person) * (numPersons));
                createNewUser(persons, numPersons);
                break;
            case 3:
                numDrivers++;
                drivers = realloc(drivers, sizeof(struct Driver) * (numDrivers));
                createDriver(drivers, numDrivers);
                break;
            case 4:
                exit = true;
                break;
            default:
                printf("Opção inválida\n");
                break;
        }
    }

    return 0;
}
