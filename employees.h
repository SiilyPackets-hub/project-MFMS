#ifndef EMPLOYEES_H
#define EMPLOYEES_H

#define MAX_EMPLOYEES 100

struct Employee {
    int id;
    char name[50];
    char department[50];
    float basicSalary;
    float housingAllowance;
    float transportAllowance;
};

void addEmployee(struct Employee employees[], int *count);
void displayEmployees(struct Employee employees[], int count);
void searchEmployee(struct Employee employees[], int count);
float calculateSalary(struct Employee employee);

#endif
