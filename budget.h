#ifndef BUDGET_H
#define BUDGET_H

#define MAX_DEPTS 5
void displayBudgetMenu();

void enterBudgets(char deptNames[][50], float allocated[], float expenses[], int count);
void displayBudgets(char deptNames[][50], float allocated[], float expenses[], int count);
float calculateRemainingBudget(float allocated, float expenditure);

#endif