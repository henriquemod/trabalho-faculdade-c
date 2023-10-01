#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

enum CivilStatus
{
    SINGLE,
    MARRIED,
    DIVORCED,
    WIDOWED
};

struct Driver
{
    char name[16];
    char subName[16];
    char cnh[11];
    bool criminalRecord;
    enum CivilStatus civilStatus;
};

struct Driver newDriver(struct Driver *driver)
{
    printf("Nome: ");
    scanf("%[^\n]", driver->name);
    getchar();
    printf("Sobrenome: ");
    scanf("%[^\n]", driver->subName);
    getchar();
    printf("CNH: ");
    scanf("%[^\n]", driver->cnh);
    getchar();
    printf("Status Civil (0 - Solteiro, 1 - Casado, 2 - Divorciado, 3 - Viúvo): ");
    int civilStatus;
    scanf("%d[^\n]", &civilStatus);
    getchar();
    driver->civilStatus = (enum CivilStatus)civilStatus;
    printf("Possui antecedentes criminais? (0 - Não, 1 - Sim): ");
    scanf("%d[^\n]", &driver->criminalRecord);
    getchar();

    return *driver;
}