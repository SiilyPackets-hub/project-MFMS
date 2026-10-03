#include <stdio.h>
#include <string.h>

int id[100];
char name[100][50];
char department[100][30];
float basic[100];
float housing[100];
float transport[100];

int count = 0;

void addEmployee(){
    printf("Enter Employee ID: ");
    scanf("%d", &id[count]);
    printf("Enter Employee Name: ");
    scanf(" %s[^\n]", name[count]);
    printf("Enter Employee Department: ");
    scanf(" %s[^\n]", department[count]);
    printf("Enter Basic Salary: ");
    scanf("%f", &basic[count]);
    printf("Enter Housing Allowence: ");
     scanf("%f", &housing[count]);
     printf("Enter Tranposrt Allowence: ");
     scanf("%f", &transport[count]);
     count++;
}

void displayEmployee(int index){
    printf("Employee ID: %d\n", id[index]);
    printf("Employee Name: %s\n", name[index]);
    printf("Employee Department: %s\n", department[index]);
    printf("Basic Salary: %f\n", basic[index]);
    printf("Housing Allowence: %f\n", housing[index]);
    printf("Transport Allowence: %f\n", transport[index]);
}

void searchEmployee(){
    int searchId;
    printf("Enter Employee ID to search: ");
    scanf("%d", &searchId);
    for(int i = 0; i < count; i++){
        if(id[i] == searchId){
            displayEmployee(i);
            return;
        }
    }
    printf("Employee not found.\n");
}

void calculateSalary() {
    int searchId;
    int i;
    int found = 0;
    float totalSalary;
    float tax;
    float netSalary;

    printf("Enter Employee ID to calculate salary: ");
    scanf("%d", &searchId);
    for(int i = 0; i < count; i++){
        if(id[i] == searchId){
            found = 1;
            totalSalary = basic[i] + housing[i] + transport[i];
            tax = totalSalary * 0.15;
            netSalary = totalSalary - tax; 
            printf("Total Salary is: %f", totalSalary);
            printf("Tax is: %f", tax);
            printf("Net Salary is: %f", netSalary);
        }
    }
    if(!found){
        printf("Employee not found.\n");
    }
}

void employeeMenu() {
    int choice;
    do {
        printf("\nEmployee Management System\n");
        printf("1. Add Employee\n");
        printf("2. Search Employee\n");
        printf("3. Calculate Salary\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        switch(choice) {
            case 1:
                addEmployee();
                break;
                case 2:
                searchEmployee();
                break;
                case 3:
                calculateSalary();
                break;
                case 4:
                printf("Exiting...\n");
                break;
                default:
                printf("Invalid choice. Please try again.\n");
        }
    }
    while(choice != 4);
}

int main() {
    employeeMenu();
    return 0;
}

