#include <stdio.h>
#include <string.h>
#include "budget.h"

void displayBudgetMenu()
{
    printf("\n=== BUDGET MANAGEMENT ===\n");
    printf("1. Enter Department Budgets\n");
    printf("2. Display Budget Report\n");
}

float calculateRemainingBudget(float allocated, float expenditure)
{
    return allocated - expenditure;
}

void enterBudgets(char deptNames[][50], float allocated[], float expenses[], int count)
{
    for (int i = 0; i < count; i++)
    {
        printf("\n--- Entry for Department %d ---\n", i + 1);
        printf("Enter Department Name: ");
        scanf(" %49[^\n]", deptNames[i]);

        do
        {
            printf("Enter Allocated Budget for %s: N$", deptNames[i]);
            scanf("%f", &allocated[i]);
            if (allocated[i] < 0)
            {
                printf("Error: Negative budget should not be accepted. Please try again.\n");
            }
        } while (allocated[i] < 0);

        do
        {
            printf("Enter Expenditure for %s: N$", deptNames[i]);
            scanf("%f", &expenses[i]);
            if (expenses[i] < 0)
            {
                printf("Error: Negative expenditure should not be accepted. Please try again.\n");
            }
        } while (expenses[i] < 0);
    }
}

void displayBudgets(char deptNames[][50], float allocated[], float expenses[], int count)
{
    printf("\n=== MUNICIPAL BUDGET OVERVIEW ===\n");

    for (int i = 0; i < count; i++)
    {
        float remaining = calculateRemainingBudget(allocated[i], expenses[i]);

        printf("\nDepartment: %s\n", deptNames[i]);
        printf("Allocated Budget: N$%.2f\n", allocated[i]);
        printf("Expenditure: N$%.2f\n", expenses[i]);
        printf("Remaining Budget: N$%.2f\n", remaining);

        if (remaining < 0)
        {
            printf("Status: EXCEEDED BUDGET\n");
        }
        else
        {
            printf("Status: WITHIN BUDGET\n");
        }
    }
}