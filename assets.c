#include <stdio.h>
#include <string.h>
#include "assets.h"

void addAsset(struct Asset assets[], int *count)
{
    if (*count >= MAX_ASSETS) {
        printf("Asset list is full.\n");
        return;
    }

    printf("Enter asset ID: ");
    scanf("%d", &assets[*count].id);
    getchar();

    printf("Enter asset name: ");
    fgets(assets[*count].name, 50, stdin);
    assets[*count].name[strlen(assets[*count].name) - 1] = '\0';

    printf("Enter asset type: ");
    fgets(assets[*count].type, 30, stdin);
    assets[*count].type[strlen(assets[*count].type) - 1] = '\0';

    printf("Enter purchase value: ");
    scanf("%f", &assets[*count].value);
    if (assets[*count].value < 0) {
        printf("Value cannot be negative.\n");
        return;
    }
    getchar();

    printf("Enter department: ");
    fgets(assets[*count].department, 50, stdin);
    assets[*count].department[strlen(assets[*count].department) - 1] = '\0';

    printf("Enter condition: ");
    fgets(assets[*count].condition, 30, stdin);
    assets[*count].condition[strlen(assets[*count].condition) - 1] = '\0';

    (*count)++;
    printf("Asset added successfully.\n");
}

void displayAssets(struct Asset assets[], int count)
{
    int i;

    if (count == 0) {
        printf("No assets found.\n");
        return;
    }

    for (i = 0; i < count; i++) {
        printf("\nID: %d\n", assets[i].id);
        printf("Name: %s\n", assets[i].name);
        printf("Type: %s\n", assets[i].type);
        printf("Purchase Value: N$%.2f\n", assets[i].value);
        printf("Department: %s\n", assets[i].department);
        printf("Condition: %s\n", assets[i].condition);
    }
}

void searchAsset(struct Asset assets[], int count)
{
    char name[50];
    int i;
    int found = 0;

    getchar();
    printf("Enter asset name: ");
    fgets(name, 50, stdin);
    name[strlen(name) - 1] = '\0';

    for (i = 0; i < count; i++) {
        if (strcmp(assets[i].name, name) == 0) {
            printf("Asset found: %d - %s - %s\n",
                   assets[i].id, assets[i].name, assets[i].condition);
            found = 1;
        }
    }

    if (found == 0)
        printf("Asset not found.\n");
}
