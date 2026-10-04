#include <stdio.h>
#include "reports.h"

void employeeReport(struct Employee employees[], int count)
{
    int i;
    float total = 0;
    float highest = 0;
    float lowest = 0;

    if (count == 0) {
        printf("No employees available.\n");
        return;
    }

    for (i = 0; i < count; i++) {
        float salary = calculateSalary(employees[i]);
        total = total + salary;

        if (i == 0 || salary > highest)
            highest = salary;

        if (i == 0 || salary < lowest)
            lowest = salary;
    }

    printf("\nEMPLOYEE REPORT\n");
    printf("Total Employees: %d\n", count);
    printf("Average Salary: N$%.2f\n", total / count);
    printf("Highest Salary: N$%.2f\n", highest);
    printf("Lowest Salary: N$%.2f\n", lowest);
}

void budgetReport(struct Budget budgets[], int count)
{
    int i;
    float allocated = 0;
    float expenditure = 0;
    int exceeded = 0;

    for (i = 0; i < count; i++) {
        allocated = allocated + budgets[i].allocated;
        expenditure = expenditure + budgets[i].expenditure;
    }

    printf("\nBUDGET REPORT\n");
    printf("Total Allocated Budget: N$%.2f\n", allocated);
    printf("Total Expenditure: N$%.2f\n", expenditure);
    printf("Remaining Budget: N$%.2f\n", allocated - expenditure);

    printf("Departments exceeding budget:\n");

    for (i = 0; i < count; i++) {
        if (budgets[i].expenditure > budgets[i].allocated) {
            printf("- %s\n", budgets[i].department);
            exceeded = 1;
        }
    }

    if (exceeded == 0)
        printf("None\n");
}

void supplierReport(struct Supplier suppliers[], int count)
{
    printf("\nSUPPLIER REPORT\n");
    displaySuppliers(suppliers, count);
}

void assetReport(struct Asset assets[], int count)
{
    printf("\nASSET REPORT\n");
    displayAssets(assets, count);
}
