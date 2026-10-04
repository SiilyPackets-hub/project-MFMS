#include <stdio.h>
#include <string.h>
#include "employees.h"

void addEmployee(struct Employee employees[], int *count)
{
    if (*count >= MAX_EMPLOYEES) {
        printf("Employee list is full.\n");
        return;
    }

    printf("Enter employee ID: ");
    scanf("%d", &employees[*count].id);
    getchar();

    printf("Enter employee name: ");
    fgets(employees[*count].name, 50, stdin);
    employees[*count].name[strlen(employees[*count].name) - 1] = '\0';

    if (strlen(employees[*count].name) == 0) {
        printf("Name cannot be empty.\n");
        return;
    }

    printf("Enter department: ");
    fgets(employees[*count].department, 50, stdin);
    employees[*count].department[strlen(employees[*count].department) - 1] = '\0';

    printf("Enter basic salary: ");
    scanf("%f", &employees[*count].basicSalary);
    if (employees[*count].basicSalary < 0) {
        printf("Salary cannot be negative.\n");
        return;
    }

    printf("Enter housing allowance: ");
    scanf("%f", &employees[*count].housingAllowance);
    if (employees[*count].housingAllowance < 0) {
        printf("Allowance cannot be negative.\n");
        return;
    }

    printf("Enter transport allowance: ");
    scanf("%f", &employees[*count].transportAllowance);
    if (employees[*count].transportAllowance < 0) {
        printf("Allowance cannot be negative.\n");
        return;
    }

    (*count)++;
    printf("Employee added successfully.\n");
}

void displayEmployees(struct Employee employees[], int count)
{
    int i;

    if (count == 0) {
        printf("No employees found.\n");
        return;
    }

    for (i = 0; i < count; i++) {
        printf("\nID: %d\n", employees[i].id);
        printf("Name: %s\n", employees[i].name);
        printf("Department: %s\n", employees[i].department);
        printf("Basic Salary: N$%.2f\n", employees[i].basicSalary);
        printf("Housing Allowance: N$%.2f\n", employees[i].housingAllowance);
        printf("Transport Allowance: N$%.2f\n", employees[i].transportAllowance);
        printf("Total Salary: N$%.2f\n", calculateSalary(employees[i]));
    }
}

void searchEmployee(struct Employee employees[], int count)
{
    char name[50];
    int i;
    int found = 0;

    getchar();
    printf("Enter employee name: ");
    fgets(name, 50, stdin);
    name[strlen(name) - 1] = '\0';

    for (i = 0; i < count; i++) {
        if (strcmp(employees[i].name, name) == 0) {
            printf("Employee found: %d - %s - %s\n",
                   employees[i].id, employees[i].name, employees[i].department);
            found = 1;
        }
    }

    if (found == 0)
        printf("Employee not found.\n");
}

float calculateSalary(struct Employee employee)
{
    return employee.basicSalary +
           employee.housingAllowance +
           employee.transportAllowance;
}
