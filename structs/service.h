#include <stdio.h>
#include <stdlib.h>
#include "driver.h"

#ifdef _WIN32
#define CLEAR_SCREEN "cls"
#else
#define CLEAR_SCREEN "clear"
#endif

#define BANHO_VALUE 80.0f;
#define TOSA_VALUE 100.0f;
#define BANHO_TOSA_VALUE 150.0f;


struct Service
{
    char name[20];
    float price;
};

struct Payment
{
    char name[32];
    float percentage;
};

struct Order
{
    struct Service service;
    struct Payment payment;
    float price;
};

struct Payment *getPayments()
{
    struct Payment *payments = NULL;
    payments = (struct Payment *)malloc(sizeof(struct Payment) * 2);
    if (payments == NULL)
    {
        printf("Memory allocation failed\n");
        exit(1);
    }

    struct Payment card = {"Cartão de Crédito", 1.3};
    struct Payment cash = {"Dinheiro/Pix", 0.9};

    payments[0] = card;
    payments[1] = cash;

    return payments;
}

struct Service *getServices()
{
    const float BANHO = BANHO_VALUE;
    const float TOSA = TOSA_VALUE;
    const float BANHO_TOSA = BANHO_TOSA_VALUE;
    struct Service *services = NULL;
    services = (struct Service *)malloc(sizeof(struct Service) * 3);
    if (services == NULL)
    {
        printf("Memory allocation failed\n");
        exit(1);
    }

    struct Service banho = {"Banho", BANHO};
    struct Service tosa = {"Tosa", TOSA};
    struct Service banho_tosa = {"Banho e Tosa", BANHO_TOSA};

    services[0] = banho;
    services[1] = tosa;
    services[2] = banho_tosa;

    return services;
}

char* generateRandom4DigitNumberWithPET() {
    static char result[8]; // Allocate space for the number and "PET"
    int randomNum = rand() % 9000 + 1000; // Generate a random 4-digit number
    snprintf(result, sizeof(result), "%04dPET", randomNum); // Format the result
    return result;
}

void chooseService(struct Service *services, struct Driver *drivers, int size)
{
    struct Payment *paymentMethods = getPayments();

    int option;
    int paymentOption;
    int day;
    int month;
    int year;
    int useDriver;
    int driverOption;
    char* randomStr = generateRandom4DigitNumberWithPET();

    printf("Escolha um serviço:\n");
    for (int i = 0; i < 3; i++)
    {
        printf("%d - %s - R$ %.2f\n", i + 1, services[i].name, services[i].price);
    }
    printf("Opção: ");
    scanf("%d", &option);
    getchar();

    system(CLEAR_SCREEN);
    printf("Escolha uma forma de pagamento:\n");
    for (int i = 0; i < 2; i++)
    {
        printf("%d - %s - %.2f%%\n", i + 1, paymentMethods[i].name, paymentMethods[i].percentage);
    }
    printf("Opção: ");
    scanf("%d", &paymentOption);
    getchar();

    system(CLEAR_SCREEN);
    printf("Digite a data do serviço (dd/mm/aaaa): ");
    scanf("%d/%d/%d", &day, &month, &year);
    getchar();

    char date[32];
    sprintf(date, "%d/%d/%d", day, month, year);

    printf("Uber PET? (0 - Não, 1 - Sim): ");
    scanf("%d", &useDriver);
    getchar();

    if (useDriver == 1)
    {
        system(CLEAR_SCREEN);
        printf("Escolha um motorista:\n");
        for (int i = 0; i < size; i++)
        {
            printf("%d - %s %s\n", i + 1, drivers[i].name, drivers[i].subName);
        }
        printf("Opção: ");
        scanf("%d", &driverOption);
        getchar();
    }

    struct Order order = {services[option - 1], paymentMethods[paymentOption - 1], services[option - 1].price * paymentMethods[paymentOption - 1].percentage};

    system(CLEAR_SCREEN);

    printf("Serviço: %s\n", order.service.name);
    printf("Forma de pagamento: %s\n", order.payment.name);
    printf("Preço: R$ %.2f\n", order.price);
    printf("Data: %s\n", date);
    if (useDriver == true) 
    {
        printf("Motorista: %s %s\n", drivers[driverOption - 1].name, drivers[driverOption - 1].subName);
        printf("Telefone: %s\n", drivers[driverOption - 1].phoneNumber);
    }
    printf("Código PET: %s\n", randomStr);

    printf("\n\n\nPressione ENTER para retornar ao continuar...");
    getchar();
    system(CLEAR_SCREEN);
}