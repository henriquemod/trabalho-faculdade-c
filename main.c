#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "usecases/authenticate.c"
#include "usecases/createUser.c"
#include "usecases/createDriver.c"

int main()
{
    struct Employee *employees = getEmployees();
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
        printf("1 - Cadastrar cliente\n");
        printf("2 - Cadastrar motorista\n");
        printf("3 - Sair\n");
        printf("Escolha uma opção: ");
        int option;
        scanf("%d", &option);
        getchar();
        switch (option)
        {
        case 1:
            createUser();
            break;
        case 2:
            createDriver();
            break;
        case 3:
            exit = true;
            break;
        default:
            printf("Opção inválida\n");
            break;
        }
    }

}
