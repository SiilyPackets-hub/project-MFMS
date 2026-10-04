#ifndef BUDGET_H
#define BUDGET_H

#define MAX_BUDGETS 50

struct Budget {
    char department[50];
    float allocated;
    float expenditure;
};

void addBudget(struct Budget budgets[], int *count);
void displayBudgets(struct Budget budgets[], int count);
float calculateRemaining(struct Budget budget);
void searchBudget(struct Budget budgets[], int count);

#endif
