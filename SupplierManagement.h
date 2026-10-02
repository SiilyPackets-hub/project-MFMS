#ifndef SUPPLIERS_H
#define SUPPLIERS_H

// Share the global variables with any file that includes this header
extern char supplierNames[5][100];
extern char supplierEmails[5][100];
extern char supplierPhones[5][30];
extern char supplierTowns[5][50];
extern int supplierCount;

// Function Prototypes for main.c to read
void displaySupplierMenu();
void addSupplier();
void displaySuppliers();
void searchSupplier();
void showNameLength();

#endif
