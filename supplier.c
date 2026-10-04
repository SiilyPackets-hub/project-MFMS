#include <stdio.h>
#include <string.h>
#include "suppliers.h"

void addSupplier(struct Supplier suppliers[], int *count)
{
    if (*count >= MAX_SUPPLIERS) {
        printf("Supplier list is full.\n");
        return;
    }

    printf("Enter supplier ID: ");
    scanf("%d", &suppliers[*count].id);
    getchar();

    printf("Enter supplier name: ");
    fgets(suppliers[*count].name, 50, stdin);
    suppliers[*count].name[strlen(suppliers[*count].name) - 1] = '\0';

    printf("Enter email: ");
    fgets(suppliers[*count].email, 60, stdin);
    suppliers[*count].email[strlen(suppliers[*count].email) - 1] = '\0';

    printf("Enter telephone: ");
    fgets(suppliers[*count].telephone, 30, stdin);
    suppliers[*count].telephone[strlen(suppliers[*count].telephone) - 1] = '\0';

    printf("Enter town/location: ");
    fgets(suppliers[*count].town, 50, stdin);
    suppliers[*count].town[strlen(suppliers[*count].town) - 1] = '\0';

    (*count)++;
    printf("Supplier added successfully.\n");
}

void displaySuppliers(struct Supplier suppliers[], int count)
{
    int i;

    if (count == 0) {
        printf("No suppliers found.\n");
        return;
    }

    for (i = 0; i < count; i++) {
        printf("\nID: %d\n", suppliers[i].id);
        printf("Name: %s\n", suppliers[i].name);
        printf("Email: %s\n", suppliers[i].email);
        printf("Telephone: %s\n", suppliers[i].telephone);
        printf("Town: %s\n", suppliers[i].town);
    }
}

void searchSupplier(struct Supplier suppliers[], int count)
{
    char name[50];
    int i;
    int found = 0;

    getchar();
    printf("Enter supplier name: ");
    fgets(name, 50, stdin);
    name[strlen(name) - 1] = '\0';

    for (i = 0; i < count; i++) {
        if (strcmp(suppliers[i].name, name) == 0) {
            printf("Supplier found: %d - %s - %s\n",
                   suppliers[i].id, suppliers[i].name, suppliers[i].town);
            found = 1;
        }
    }

    if (found == 0)
        printf("Supplier not found.\n");
}
