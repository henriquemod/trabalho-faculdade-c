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
    char phoneNumber[32];
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
    printf("Telefone: ");
    scanf("%[^\n]", driver->phoneNumber);
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


void createDriver()
{
    struct Driver *driver = NULL;
    driver = (struct Driver *)malloc(sizeof(struct Driver));
    if (driver == NULL)
    {
        printf("Memory allocation failed\n");
        exit(1);
    }

    newDriver(driver);

    printf("Name:\n\t%s %s\n", driver->name, driver->subName);
    printf("CNH:\n\t%s\n", driver->cnh);

    free(driver);
    driver = NULL;
}


struct Driver *getDrivers()
{
    struct Driver *drivers = NULL;
    drivers = (struct Driver *)malloc(sizeof(struct Driver) * 3);
    if (drivers == NULL)
    {
        printf("Memory allocation failed\n");
        exit(1);
    }

    struct Driver driver_1 = {"João", "Silva", "123", "47991929394", false, SINGLE};
    struct Driver driver_2 = {"Maria", "Silva", "456", "47991912394", true, MARRIED};
    struct Driver driver_3 = {"José", "Silva", "789", "47991944412", false, DIVORCED};

    drivers[0] = driver_1;
    drivers[1] = driver_2;
    drivers[2] = driver_3;

    return drivers;
}