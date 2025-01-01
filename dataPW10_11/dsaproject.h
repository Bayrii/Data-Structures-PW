#ifndef DSAPROJECT_H
#define DSAPROJECT_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define the voter structure
typedef struct elector {
    char name[50];
    long cin_num; // ID number
    int choice;   // Voting choice
    struct elector* next; // Pointer to next voter
} *T_Elector;

// Function prototypes
T_Elector creationelector(void);
void displaylist(T_Elector);
void addelector(T_Elector*, char[], long, int);
int countelector(T_Elector);
int findelector(T_Elector, long);
void deletelector(T_Elector*, long);
void decomposelist(T_Elector, T_Elector*, T_Elector*, T_Elector*);
void sortlist(T_Elector);
T_Elector mergelists(T_Elector, T_Elector);
int countLR(T_Elector);
void freelist(T_Elector);

#endif
