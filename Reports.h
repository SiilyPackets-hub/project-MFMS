#include <stdio.h>
#include <string.h>
#include "reports.h"

void displayReportMenu(
    Employee employees[], int empCount,
    DepartmentBudget budgets[], int budgetCount,
    Supplier suppliers[], int supplierCount,
    Asset assets[], int assetCount)
{
    int choice;

    do {
        printf("\n=========================================\n");
        printf("         MUNICIPAL REPORTS MENU          \n");
        printf("=========================================\n");
        printf("1. Employee Salary Summary Report\n");
        printf("2. Departmental Budget Summary Report\n");
        printf("3. Registered Suppliers Report\n");
        printf("4. Municipal Assets Register Report\n");
        printf("5. Generate All Reports\n");
        printf("6. Return to Main Menu\n");
        printf("-----------------------------------------\n");
        printf("Enter your choice (1-6): ");

        if (scanf("%d", &choice) != 1) {
            printf("Invalid input. Please enter a number.\n");
            while (getchar() != '\n');
            continue;
        }

        switch (choice) {
            case 1:
                generateEmployeeReport(employees, empCount);
                break;
            case 2:
                generateBudgetReport(budgets, budgetCount);
                break;
            case 3:
                generateSupplierReport(suppliers, supplierCount);
                break;
            case 4:
                generateAssetReport(assets, assetCount);
                break;
            case 5:
                generateEmployeeReport(employees, empCount);
                generateBudgetReport(budgets, budgetCount);
                generateSupplierReport(suppliers, supplierCount);
                generateAssetReport(assets, assetCount);
                break;
            case 6:
                printf("Returning to Main Menu...\n");
                break;
            default:
                printf("Invalid option. Enter a choice between 1 and 6.\n");
        }
    } while (choice != 6);
}

void generateEmployeeReport(const Employee employees[], int count) {
    printf("\n=========================================\n");
    printf("         EMPLOYEE MANAGEMENT REPORT      \n");
    printf("=========================================\n");

    if (count <= 0) {
        printf("No employee records found in the system.\n");
        return;
    }

    double totalSalarySum = 0.0;
    double highestSalary = employees[0].netSalary;
    double lowestSalary = employees[0].netSalary;

    for (int i = 0; i < count; i++) {
        double currentSalary = employees[i].netSalary;
        totalSalarySum += currentSalary;

        if (currentSalary > highestSalary) highestSalary = currentSalary;
        if (currentSalary < lowestSalary) lowestSalary = currentSalary;
    }

    double averageSalary = totalSalarySum / count;

    printf("Total Employees : %d\n", count);
    printf("Average Salary  : N$%.2f\n", averageSalary);
    printf("Highest Salary  : N$%.2f\n", highestSalary);
    printf("Lowest Salary   : N$%.2f\n", lowestSalary);
    printf("-----------------------------------------\n");
}

void generateBudgetReport(const DepartmentBudget budgets[], int count) {
    printf("\n=========================================\n");
    printf("         BUDGET MANAGEMENT REPORT        \n");
    printf("=========================================\n");

    if (count <= 0) {
        printf("No budget records found in the system.\n");
        return;
    }

    double totalAllocated = 0.0;
    double totalExpenditure = 0.0;
    int exceededCount = 0;

    for (int i = 0; i < count; i++) {
        totalAllocated += budgets[i].allocatedBudget;
        totalExpenditure += budgets[i].expenditure;
    }

    double totalRemaining = totalAllocated - totalExpenditure;

    printf("Total Allocated Budget : N$%.2f\n", totalAllocated);
    printf("Total Expenditure      : N$%.2f\n", totalExpenditure);
    printf("Total Remaining Budget : N$%.2f\n", totalRemaining);
    printf("-----------------------------------------\n");
    printf("DEPARTMENTS EXCEEDING ALLOCATED BUDGET:\n");

    for (int i = 0; i < count; i++) {
        if (budgets[i].expenditure > budgets[i].allocatedBudget) {
            double deficit = budgets[i].expenditure - budgets[i].allocatedBudget;
            printf(" - Department: %-15s | Deficit: N$%.2f\n", budgets[i].deptName, deficit);
            exceededCount++;
        }
    }

    if (exceededCount == 0) {
        printf(" None. All departments are within budget.\n");
    }
    printf("-----------------------------------------\n");
}

void generateSupplierReport(const Supplier suppliers[], int count) {
    printf("\n=========================================================================\n");
    printf("                       SUPPLIER MANAGEMENT REPORT                       \n");
    printf("=========================================================================\n");

    if (count <= 0) {
        printf("No supplier records found in the system.\n");
        return;
    }

    printf("%-10s %-20s %-20s %-15s\n", "ID", "Name", "Email", "Town/Location");
    printf("-------------------------------------------------------------------------\n");

    for (int i = 0; i < count; i++) {
        printf("%-10s %-20s %-20s %-15s\n", 
               suppliers[i].supplierID, 
               suppliers[i].name, 
               suppliers[i].email, 
               suppliers[i].location);
    }
    printf("-------------------------------------------------------------------------\n");
    printf("Total Registered Suppliers: %d\n", count);
}

void generateAssetReport(const Asset assets[], int count) {
    printf("\n====================================================================================\n");
    printf("                             MUNICIPAL ASSET REGISTER                               \n");
    printf("====================================================================================\n");

    if (count <= 0) {
        printf("No asset records found in the system.\n");
        return;
    }

    printf("%-10s %-20s %-15s %-15s %-12s\n", "Asset ID", "Name", "Type", "Department", "Value (N$)");
    printf("------------------------------------------------------------------------------------\n");

    double totalValue = 0.0;
    for (int i = 0; i < count; i++) {
        printf("%-10s %-20s %-15s %-15s N$%-10.2f\n", 
               assets[i].assetID, 
               assets[i].name, 
               assets[i].type, 
               assets[i].department, 
               assets[i].purchaseValue);
        totalValue += assets[i].purchaseValue;
    }
    printf("------------------------------------------------------------------------------------\n");
    printf("Total Assets Registered: %d | Total Portfolio Value: N$%.2f\n", count, totalValue);
}
