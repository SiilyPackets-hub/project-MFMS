#include <stdio.h>
#include "employees.h"
#include "budget.h"
#include "suppliers.h"
#include "assets.h"
#include "reports.h"

void displayMenu()
{printf("\n========================================\n");
printf(" MUNICIPAL FINANCIAL MANAGEMENT SYSTEM\n");
printf("========================================\n");
printf("1. Employee Management\n");
printf("2. Budget Management\n");
printf("3. Supplier Management\n");
printf("4. Asset Management\n");
printf("5. Reports\n");
printf("6. Exit\n");
printf("Enter your choice: ");
}

void employeeMenu(struct Employee employees[], int *count)
{
    int choice;
    do {
    printf("\nEMPLOYEE MANAGEMENT\n");
 printf("1. Add Employee\n. Display Employees\n. Search Employee\n. Calculate/Display Salary\n. Back\n");
printf("Enter choice: ");
    scanf("%d", &choice);
        if (choice == 1) addEmployee(employees, count);
else if (choice == 2) displayEmployees(employees, *count);
else if (choice == 3) searchEmployee(employees, *count);
else if (choice == 4) displayEmployees(employees, *count);
else if (choice != 0) printf("Invalid choice.\n");
    } while (choice != 0);
}

void budgetMenu(struct Budget budgets[], int *count)
{
    int choice;
    do {
     printf("\nBUDGET MANAGEMENT\n");
        printf("1. Enter Department Budget\n. Display Budgets\n. Search Budget\n. Back\n");
 printf("Enter choice: ");
 scanf("%d", &choice);
    if (choice == 1) addBudget(budgets, count);
      else if (choice == 2) displayBudgets(budgets, *count);
    else if (choice == 3) searchBudget(budgets, *count);
 else if (choice != 0) printf("Invalid choice.\n");
    } while (choice != 0);
}

void supplierMenu(struct Supplier suppliers[], int *count)
{
    int choice;
    do {
printf("\nSUPPLIER MANAGEMENT\n");
 printf("1. Add Supplier\n. Display Suppliers\n. Search Supplier\n. Back\n");
 printf("Enter choice: ");
scanf("%d", &choice);
    if (choice == 1) addSupplier(suppliers, count);
else if (choice == 2) displaySuppliers(suppliers, *count);
else if (choice == 3) searchSupplier(suppliers, *count);
else if (choice != 0) printf("Invalid choice.\n");
    } while (choice != 0);
}

void assetMenu(struct Asset assets[], int *count)
{
int choice;
    do {
printf("\nASSET MANAGEMENT\n");
printf("1. Add Asset\n. Display Assets\n. Search Asset\n. Back\n");
printf("Enter choice: ");
scanf("%d", &choice);
    if (choice == 1) addAsset(assets, count);
        else if (choice == 2) displayAssets(assets, *count);
        else if (choice == 3) searchAsset(assets, *count);
else if (choice != 0) printf("Invalid choice.\n");
    } while (choice != 0);
}

void reportMenu(struct Employee employees[], int employeeCount,
     struct Budget budgets[], int budgetCount,
struct Supplier suppliers[], int supplierCount,
struct Asset assets[], int assetCount)
{
    int choice;
    do {
printf("\nREPORTS\n");
 printf("1. Employee Report\n. Budget Report\n. Supplier Report\n. Asset Report\n. Back\n");
 printf("Enter choice: ");
 scanf("%d", &choice);
 if (choice == 1) employeeReport(employees, employeeCount);
  else if (choice == 2) budgetReport(budgets, budgetCount);
else if (choice == 3) supplierReport(suppliers, supplierCount);
else if (choice == 4) assetReport(assets, assetCount);
else if (choice != 0) printf("Invalid choice.\n");
    } while (choice != 0);
}

int main()
{
struct Employee employees[100] = {
{101, "John", "Finance", 15000, 2000, 1000},
{102, "Mary", "IT", 18000, 2500, 1200},
{103, "Peter", "HR", 12000, 1800, 900}
    };
int employeeCount = 3;

struct Budget budgets[50] = {
{"Finance", 100000, 75000},
 {"IT", 150000, 90000},
{"HR", 80000, 50000}
    };
int budgetCount = 3;

struct Supplier suppliers[100] = {
 {201, "NamTech Supplies", "info@namtech.com", "0812345678", "Windhoek"},
{202, "City Office Solutions", "city@office.com", "0855555555", "Oshakati"}
};
int supplierCount = 2;

struct Asset assets[100] = {
{301, "Dell Computer", "Computer", 12000, "Finance", "Good"},
{302, "Toyota Hilux", "Vehicle", 350000, "Transport", "Good"}
    };
int assetCount = 2;

int choice;
    do {displayMenu();
scanf("%d", &choice);
        if (choice == 1) employeeMenu(employees, &employeeCount);
else if (choice == 2) budgetMenu(budgets, &budgetCount);
else if (choice == 3) supplierMenu(suppliers, &supplierCount);
else if (choice == 4) assetMenu(assets, &assetCount);
else if (choice == 5) reportMenu(employees, employeeCount, budgets, budgetCount, suppliers, supplierCount, assets, assetCount);
 else if (choice == 6) printf("END.\n");
else printf("Invalid choice, try again.\n");
} while (choice != 6);
return 0;
}
