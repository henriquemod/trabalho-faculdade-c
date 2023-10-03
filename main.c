#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "entities/service.h"
#include "usecases/authenticate.c"
#include "usecases/findCpf.c"

struct Person foundPerson;
struct Order order;

int main()
{
    struct Employee *employees = getEmployees();
    struct Person *persons = getPersons();
    struct Service *services = getServices();
    struct Driver *drivers = getDrivers();

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
            foundPerson = findCpf(persons);
            chooseService(services, drivers);
            break;
        case 2:
            // createUser();
            break;
        case 3:
            createDriver();
            break;
        case 4:
            exit = true;
            break;
        default:
            printf("Opção inválida\n");
            break;
        }
    }

}
