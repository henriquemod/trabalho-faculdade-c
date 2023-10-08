#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#ifdef _WIN32
#define CLEAR_SCREEN "cls"
#else
#define CLEAR_SCREEN "clear"
#endif

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

struct Driver *getDrivers()
{
    struct Driver *drivers = NULL;
    drivers = (struct Driver *)malloc(sizeof(struct Driver) * 3);
    if (drivers == NULL)
    {
        printf("Memory allocation failed\n");
        exit(1);
    }

    struct Driver driver_1 = {"Joao", "Albuquerque", "90347299714", "47991929394", false, SINGLE};
    struct Driver driver_2 = {"Maria", "Silva", "44600117876", "47991912394", true, MARRIED};
    struct Driver driver_3 = {"Jose", "Amaral", "81067030611", "47991944412", false, DIVORCED};

    drivers[0] = driver_1;
    drivers[1] = driver_2;
    drivers[2] = driver_3;

    return drivers;
}

void createDriver(struct Driver *drivers, int size)
{
    system(CLEAR_SCREEN);

    struct Driver *driver = NULL;
    driver = (struct Driver *)malloc(sizeof(struct Driver));
    if (driver == NULL)
    {
        printf("Memory allocation failed\n");
        exit(1);
    }

    printf("Cadastro de motorita\n\n");

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
    int criminalRecord;
    scanf("%d[^\n]", &criminalRecord);
    driver->criminalRecord = criminalRecord;
    getchar();

    system(CLEAR_SCREEN);
    printf("Motorista cadastrado com sucesso\n\n");
    printf("Nome: %s %s\n", driver->name, driver->subName);
    printf("CNH: %s\n", driver->cnh);
    printf("\n\nPressione ENTER para retornar ao continuar...");
    getchar();
    system(CLEAR_SCREEN);

    drivers[size - 1] = *driver;
}