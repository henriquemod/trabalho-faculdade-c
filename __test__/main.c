#include <check.h>
#include "../structs/driver.h"
#include "../structs/pet.h"
#include "../structs/employee.h"

#define DRIVER_NAME "John"
#define DRIVER_SUBNAME "Doe"
#define DRIVER_CNH "1234567890"
#define DRIVER_PHONENUMBER "555-123-4567"
#define DRIVER_CRIMINALRECORD false
#define DRIVER_CIVILSTATUS SINGLE

#define PET_NAME "Thor"
#define PET_BREED "Golden Retriever"
#define PET_WEIGHT 10
#define PET_SIZE SMALL

#define EMPLOYEE_NAME "João"
#define EMPLOYEE_USERNAME "joao"
#define EMPLOYEE_PASSWORD "123"

struct Driver testDriver;
struct Pet testPet;
struct Employee testEmployee;

void setupDriver(void)
{
    strcpy(testDriver.name, DRIVER_NAME);
    strcpy(testDriver.subName, DRIVER_SUBNAME);
    strcpy(testDriver.cnh, DRIVER_CNH);
    strcpy(testDriver.phoneNumber, DRIVER_PHONENUMBER);
    testDriver.criminalRecord = DRIVER_CRIMINALRECORD;
    testDriver.civilStatus = DRIVER_CIVILSTATUS;
}

void setupPet(void)
{
    strcpy(testPet.name, PET_NAME);
    strcpy(testPet.breed, PET_BREED);
    testPet.weight = PET_WEIGHT;
    testPet.size = PET_SIZE;
}

void setupEmployee(void)
{
    strcpy(testEmployee.name, EMPLOYEE_NAME);
    strcpy(testEmployee.username, EMPLOYEE_USERNAME);
    strcpy(testEmployee.password, EMPLOYEE_PASSWORD);
}

void setup(void)
{
    setupDriver();
    setupPet();
    setupEmployee();
}

// ANCHOR - Driver tests
START_TEST(test_driver_name)
{
    ck_assert_str_eq(testDriver.name, DRIVER_NAME);
}
END_TEST

START_TEST(test_driver_subname)
{
    ck_assert_str_eq(testDriver.subName, DRIVER_SUBNAME);
}
END_TEST

START_TEST(test_driver_cnh)
{
    ck_assert_str_eq(testDriver.cnh, DRIVER_CNH);
}
END_TEST

START_TEST(test_driver_phonenumber)
{
    ck_assert_str_eq(testDriver.phoneNumber, DRIVER_PHONENUMBER);
}
END_TEST

START_TEST(test_driver_criminalrecord)
{
    ck_assert_int_eq(testDriver.criminalRecord, DRIVER_CRIMINALRECORD);
}
END_TEST

START_TEST(test_driver_civilstatus)
{
    ck_assert_int_eq(testDriver.civilStatus, DRIVER_CIVILSTATUS);
}
END_TEST

// ANCHOR - Pet tests
START_TEST(test_pet_name)
{
    ck_assert_str_eq(testPet.name, PET_NAME);
}
END_TEST

START_TEST(test_pet_breed)
{
    ck_assert_str_eq(testPet.breed, PET_BREED);
}
END_TEST

START_TEST(test_pet_weight)
{
    ck_assert_int_eq(testPet.weight, PET_WEIGHT);
}
END_TEST

START_TEST(test_pet_size)
{
    ck_assert_int_eq(testPet.size, PET_SIZE);
}
END_TEST

// ANCHOR - Employee tests
START_TEST(test_employee_name)
{
    ck_assert_str_eq(testEmployee.name, EMPLOYEE_NAME);
}
END_TEST

START_TEST(test_employee_username)
{
    ck_assert_str_eq(testEmployee.username, EMPLOYEE_USERNAME);
}
END_TEST

START_TEST(test_employee_password)
{
    ck_assert_str_eq(testEmployee.password, EMPLOYEE_PASSWORD);
}
END_TEST

// ANCHOR - Create a Driver test suite
Suite *driver_suite(void)
{
    Suite *s;
    TCase *tc_core;

    s = suite_create("Driver");
    tc_core = tcase_create("Core");

    tcase_add_checked_fixture(tc_core, setup, NULL);

    tcase_add_test(tc_core, test_driver_name);
    tcase_add_test(tc_core, test_driver_subname);
    tcase_add_test(tc_core, test_driver_cnh);
    tcase_add_test(tc_core, test_driver_phonenumber);
    tcase_add_test(tc_core, test_driver_criminalrecord);
    tcase_add_test(tc_core, test_driver_civilstatus);

    suite_add_tcase(s, tc_core);

    return s;
}

// ANCHOR - Create a Pet test suite
Suite *pet_suite(void)
{
    Suite *s;
    TCase *tc_core;

    s = suite_create("Pet");
    tc_core = tcase_create("Core");

    tcase_add_checked_fixture(tc_core, setup, NULL);

    tcase_add_test(tc_core, test_pet_name);
    tcase_add_test(tc_core, test_pet_breed);
    tcase_add_test(tc_core, test_pet_weight);
    tcase_add_test(tc_core, test_pet_size);

    suite_add_tcase(s, tc_core);

    return s;
}

// ANCHOR - Create a Employee test suite
Suite *employee_suite(void)
{
    Suite *s;
    TCase *tc_core;

    s = suite_create("Employee");
    tc_core = tcase_create("Core");

    tcase_add_checked_fixture(tc_core, setup, NULL);

    tcase_add_test(tc_core, test_employee_name);
    tcase_add_test(tc_core, test_employee_username);
    tcase_add_test(tc_core, test_employee_password);

    suite_add_tcase(s, tc_core);

    return s;
}

void start_runners(SRunner *runners[], int size)
{
    for (int i = 0; i < size; i++)
    {
        srunner_run_all(runners[i], CK_NORMAL);
    }
}

void free_runners(SRunner *runners[], int size)
{
    for (int i = 0; i < size; i++)
    {
        srunner_free(runners[i]);
    }
}

int main(void)
{
    int number_failed;
    Suite *driverStuite, *petSuite, *employeeSuite;
    SRunner *driverSRunner, *petSRunner, *employeeSRunner;

    driverStuite = driver_suite();
    petSuite = pet_suite();
    employeeSuite = employee_suite();

    driverSRunner = srunner_create(driverStuite);
    petSRunner = srunner_create(petSuite);
    employeeSRunner = srunner_create(employeeSuite);

    start_runners((SRunner *[]){driverSRunner, petSRunner, employeeSRunner}, 3);

    number_failed = srunner_ntests_failed(driverSRunner) 
        + srunner_ntests_failed(petSRunner) 
        + srunner_ntests_failed(employeeSRunner);

    free_runners((SRunner *[]){driverSRunner, petSRunner, employeeSRunner}, 3);

    // ANCHOR - Return the number of failed tests
    return (number_failed == 0) ? 0 : 1;
}