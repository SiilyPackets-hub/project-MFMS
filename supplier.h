#ifndef SUPPLIERS_H
#define SUPPLIERS_H

#define MAX_SUPPLIERS 100

struct Supplier {
    int id;
    char name[50];
    char email[60];
    char telephone[30];
    char town[50];
};

void addSupplier(struct Supplier suppliers[], int *count);
void displaySuppliers(struct Supplier suppliers[], int count);
void searchSupplier(struct Supplier suppliers[], int count);

#endif
