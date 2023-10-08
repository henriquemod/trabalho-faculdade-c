#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

struct Employee
{
    char name[16];
    char username[16];
    char password[16];
};

struct Employee *findEmployee(struct Employee *employees, char *username, char *password)
{
    for (int i = 0; i < 3; i++)
    {
        if (strcmp(employees[i].username, username) == 0 && strcmp(employees[i].password, password) == 0)
        {
            return &employees[i];
        }
    }
    return NULL;
}

struct Employee *getEmployees()
{
    struct Employee *employees = NULL;
    employees = (struct Employee *)malloc(sizeof(struct Employee) * 2);
    if (employees == NULL)
    {
        printf("Memory allocation failed\n");
        exit(1);
    }

    struct Employee employee1 = {"João", "joao", "123"};
    struct Employee employee2 = {"Maria", "maria", "123"};

    employees[0] = employee1;
    employees[1] = employee2;

    return employees;
}

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