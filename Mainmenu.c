
#include <stdio.h>

int main() {
    int choice;

    do {
        printf("\n========================================\n");
        printf("  MUNICIPAL FINANCIAL MANAGEMENT SYSTEM\n");
        printf("========================================\n");
        printf("1. Employee Management\n");
        printf("2. Budget Management\n");
        printf("3. Supplier Management\n");
        printf("4. Asset Management\n");
        printf("5. Reports\n");
        printf("6. Exit\n");
        printf("========================================\n");
        printf("Enter your choice: ");

        scanf("%d", &choice);

        if (choice == 1) {
            printf("Employee Management selected.\n");
        }
        else if (choice == 2) {
            printf("Budget Management selected.\n");
        }
        else if (choice == 3) {
            printf("Supplier Management selected.\n");
        }
        else if (choice == 4) {
            printf("Asset Management selected.\n");
        }
        else if (choice == 5) {
            printf("Reports selected.\n");
        }
        else if (choice == 6) {
            printf("Exiting system...\n");
        }
        else {
            printf("Invalid choice. Please try again.\n");
        }

    } while (choice != 6);

    return 0;
}

