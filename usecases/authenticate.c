#include <stdio.h>
#include <stdbool.h>
#include "../entities/employee.h"

bool authenticate(struct Employee *employees)
{
    char username[16];
    char password[16];
    printf("Username: ");
    scanf("%[^\n]", username);
    getchar();
    printf("Password: ");
    scanf("%[^\n]", password);
    getchar();
    struct Employee *employee = findEmployee(employees, username, password);
    if (employee == NULL)
    {
        return false;
    }
    return true;
}