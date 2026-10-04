#ifndef ASSETS_H
#define ASSETS_H

#define MAX 5


struct Asset {
    int id;
    char name[50];
    char type[50];
    double value;
    char department[50];
    char condition[50];
};

#endif
