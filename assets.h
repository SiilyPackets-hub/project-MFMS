#ifndef ASSETS_H
#define ASSETS_H

#define MAX_ASSETS 100


struct Asset {
    int id;
    char name[50];
    char type[50];
    double value;
    char department[50];
    char condition[50];
};
void addAsset(struct Asset assets[], int *count);
void displayAssets(struct Asset assets[], int count);
void searchAsset(struct Asset assets[], int count);

#endif

