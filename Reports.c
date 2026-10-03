#include <stdio.h>
#include "reports.h"

void displayReportMenu(
    Employee employees[], int empCount,
    DepartmentBudget budgets[], int budgetCount,
    Supplier suppliers[], int supplierCount,
    Asset assets[], int assetCount)
{
    int choice = 0;

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

            int ch;
            while ((ch = getchar()) != '\n' && ch != EOF);

            choice = 0;
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
