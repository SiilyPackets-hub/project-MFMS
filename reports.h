#ifndef REPORTS_H
#define REPORTS_H

#include "employees.h"
#include "budget.h"
#include "suppliers.h"
#include "assets.h"

void employeeReport(struct Employee employees[], int count);
void budgetReport(struct Budget budgets[], int count);
void supplierReport(struct Supplier suppliers[], int count);
void assetReport(struct Asset assets[], int count);

#endif
