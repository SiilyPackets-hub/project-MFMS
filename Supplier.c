#include <stdio.h>
#include <string.h>

// Global variables so functions can access them easily
char supplierNames[5][100];
char supplierEmails[5][100];
char supplierPhones[5][30];
char supplierTowns[5][50];
int supplierCount = 0; 

// Function Prototypes
void displayMenu();
void addSupplier();
void displaySuppliers();
void searchSupplier();
void showNameLength();

int main() {
    int choice;

    do {
        displayMenu();
        scanf("%d", &choice);

        switch(choice) {
            case 1:
                addSupplier();
                break;
            case 2:
                displaySuppliers();
                break;
            case 3:
                searchSupplier();
                break;
            case 4:
                showNameLength();
                break;
            case 5:
                printf("Goodbye.\n");
                break;
            default:
                printf("Invalid choice. Try again.\n");
        }
    } while(choice != 5);

    return 0;
}

void displayMenu() {
    printf("\n================================\n");
    printf(" MUNICIPAL FINANCIAL MANAGEMENT\n");
    printf("================================\n");
    printf("1. Add Supplier\n");
    printf("2. Display Supplier\n");
    printf("3. Search Supplier\n");
    printf("4. Show Name Length\n");
    printf("5. Exit\n");
    printf("Enter choice: ");
}

void addSupplier() {
    if (supplierCount >= 10) {
        printf("Database full! Cannot add more than 5 suppliers.\n");
        return;
    }

    printf("======================================");
    printf("\n---Entering Details for Supplier---\n", supplierCount + 1);
    printf("======================================\n");
    
    printf("=======[ Kindly avoid spaces keys ]=====\n ");
    printf("Enter supplier name : ");
    scanf("%99s", supplierNames[supplierCount]);

    printf("Enter email: ");
    scanf("%99s", supplierEmails[supplierCount]);

    printf("Enter phone: ");
    scanf("%29s", supplierPhones[supplierCount]);

    printf("Enter town: ");
    scanf("%49s", supplierTowns[supplierCount]);

    printf("Supplier added successfully!\n");
    supplierCount = supplierCount + 1; 
}

void displaySuppliers() {
    if (supplierCount == 0) {
        printf("No suppliers registered yet.\n");
        return;
    }

    printf("\n--- ALL REGISTERED SUPPLIERS ---\n");
    for (int i = 0; i < supplierCount; i++) {
        printf("Supplier %d:\n", i + 1);
        printf("  Name : %s\n", supplierNames[i]);
        printf("  Email: %s\n", supplierEmails[i]);
        printf("  Phone: %s\n", supplierPhones[i]);
        printf("  Town : %s\n", supplierTowns[i]);
        printf("------------------------\n");
    }
}


void searchSupplier() {
    char searchName[100];
    int found = 0;

    if (supplierCount == 0) {
        printf("No suppliers to search.\n");
        return;
    }

    printf("Enter supplier name to search: ");
    scanf("%99s", searchName);

    for (int i = 0; i < supplierCount; i++) {
        
        if (strcmp(supplierNames[i], searchName) == 0) {
            printf("Supplier found.\n");
            printf("Email: %s | Town: %s\n", supplierEmails[i], supplierTowns[i]);

            
            char description[200];
            strcpy(description, supplierNames[i]);
            strcat(description, " operates in ");
            strcat(description, supplierTowns[i]);
            printf("Description: %s.\n", description);

            found = 1; 
            break; 
        }
    }

    if (found == 0) {
        printf("Supplier not found.\n");
    }
}


void showNameLength() {
    if (supplierCount == 0) {
        printf("No suppliers registered.\n");
        return;
    }

    printf("\n--- SUPPLIER NAME LENGTHS ---\n");
    for (int i = 0; i < supplierCount; i++) {
        printf("Name: %s | Length: %zu\n", supplierNames[i], strlen(supplierNames[i]));
    }
}
