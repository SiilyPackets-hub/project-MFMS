#include <stdio.h>
#include <string.h>
#include "budget.h"

void addBudget(struct Budget budgets[], int *count)
{
    if (*count >= MAX_BUDGETS) {
        printf("Budget list is full.\n");
        return;
    }

    getchar();
    printf("Enter department: ");
    fgets(budgets[*count].department, 50, stdin);
    budgets[*count].department[strlen(budgets[*count].department) - 1] = '\0';

    printf("Enter allocated budget: ");
    scanf("%f", &budgets[*count].allocated);
    if (budgets[*count].allocated < 0) {
        printf("Budget cannot be negative.\n");
        return;
    }

    printf("Enter expenditure: ");
    scanf("%f", &budgets[*count].expenditure);
    if (budgets[*count].expenditure < 0) {
        printf("Expenditure cannot be negative.\n");
        return;
    }

    (*count)++;
    printf("Budget added successfully.\n");
}

void displayBudgets(struct Budget budgets[], int count)
{
    int i;

    if (count == 0) {
        printf("No budgets found.\n");
        return;
    }

    for (i = 0; i < count; i++) {
        printf("\nDepartment: %s\n", budgets[i].department);
        printf("Allocated Budget: N$%.2f\n", budgets[i].allocated);
        printf("Expenditure: N$%.2f\n", budgets[i].expenditure);
        printf("Remaining Budget: N$%.2f\n", calculateRemaining(budgets[i]));

        if (budgets[i].expenditure <= budgets[i].allocated)
            printf("Status: WITHIN BUDGET\n");
        else
            printf("Status: EXCEEDED BUDGET\n");
    }
}

float calculateRemaining(struct Budget budget)
{
    return budget.allocated - budget.expenditure;
}

void searchBudget(struct Budget budgets[], int count)
{
    char department[50];
    int i;
    int found = 0;

    getchar();
    printf("Enter department: ");
    fgets(department, 50, stdin);
    department[strlen(department) - 1] = '\0';

    for (i = 0; i < count; i++) {
        if (strcmp(budgets[i].department, department) == 0) {
            printf("Department found: %s\n", budgets[i].department);
            printf("Remaining: N$%.2f\n", calculateRemaining(budgets[i]));
            found = 1;
        }
    }

    if (found == 0)
        printf("Department budget not found.\n");
}
