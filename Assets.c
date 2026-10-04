#include <stdio.h>
#include <string.h>
#include "assets.h" 

int main() {
    struct Asset assets[MAX];
    int count = 0;
    int choice;

    do {
        printf("\n=== MUNICIPAL ASSET MANAGEMENT ===\n");
        printf("1. Add Asset\n");
        printf("2. Display All Assets\n");
        printf("3. Search Asset by Name\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        
        scanf("%d", &choice);
        while(getchar() != '\n'); 

        switch(choice) {
            case 1:
                if (count < MAX) {
                    assets[count].id = count + 1;

                    printf("Enter Asset Name: ");
                    fgets(assets[count].name, 50, stdin);
                    assets[count].name[strcspn(assets[count].name, "\n")] = '\0';

                    printf("Enter Asset Type (e.g., Vehicle, Computer, Building): ");
                    fgets(assets[count].type, 50, stdin);
                    assets[count].type[strcspn(assets[count].type, "\n")] = '\0';

                    printf("Enter Purchase Value (N$): ");
                    scanf("%lf", &assets[count].value);
                    while(getchar() != '\n');

                    printf("Enter Department: ");
                    fgets(assets[count].department, 50, stdin);
                    assets[count].department[strcspn(assets[count].department, "\n")] = '\0';

                    printf("Enter Condition (e.g., Good, Fair, Poor): ");
                    fgets(assets[count].condition, 50, stdin);
                    assets[count].condition[strcspn(assets[count].condition, "\n")] = '\0';

                    count++;
                    printf("Asset added successfully! ID: %d\n", assets[count - 1].id);
                } else {
                    printf("Asset register is full!\n");
                }
                break;

            case 2:
                if (count == 0) {
                    printf("\nNo assets registered yet.\n");
                } else {
                    printf("\n--- MUNICIPAL ASSET REGISTER ---\n");
                    for (int i = 0; i < count; i++) {
                        printf("[%d] Name: %s | Type: %s | Value: N$%.2lf | Dept: %s | Condition: %s\n",
                               assets[i].id, assets[i].name, assets[i].type, 
                               assets[i].value, assets[i].department, assets[i].condition);
                    }
                }
                break;

            case 3:
                if (count == 0) {
                    printf("\nNo assets available to search.\n");
                } else {
                    char searchName[50];
                    printf("Enter Asset Name to search: ");
                    fgets(searchName, 50, stdin);
                    searchName[strcspn(searchName, "\n")] = '\0';

                    int found = 0;
                    for (int i = 0; i < count; i++) {
                        if (strcmp(assets[i].name, searchName) == 0) {
                            printf("\nAsset Found!\n");
                            printf("ID: %d\nName: %s\nType: %s\nValue: N$%.2lf\nDepartment: %s\nCondition: %s\n",
                                   assets[i].id, assets[i].name, assets[i].type, 
                                   assets[i].value, assets[i].department, assets[i].condition);
                            found = 1;
                            break;
                        }
                    }
                    if (!found) {
                        printf("Asset '%s' not found.\n", searchName);
                    }
                }
                break;

            case 4:
                printf("Exiting Asset Management. Goodbye!\n");
                break;

            default:
                printf("Invalid choice! Please select between 1 and 4.\n");
        }

    } while (choice != 4);

    return 0;
}
