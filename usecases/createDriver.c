#include <stdio.h>
#include <stdlib.h>
#include "../entities/driver.h"

// const char *getSizeString(enum CivilStatus size)
// {
//     switch (size)
//     {
//     case SINGLE:
//         return "Solteiro";
//     case MARRIED:
//         return "Casado";
//     case DIVORCED:
//         return "Divorciado";
//     case WIDOWED:
//         return "Viúvo";
//     default:
//         return "unknown";
//     }
// }

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