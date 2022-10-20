/* lab24functs.h
 * =============================================================
 *    Name:
 * Section:
 * Purpose: Practice using malloc / free
 * =============================================================
 */

#ifndef LAB24FUNCTS_H
#define LAB24FUNCTS_H
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct CadetInfoStruct {
    char name[50];
    char last[50];
    char first[50];
    int age;
    int squad;
    int year;
} CadetInfoStructType;

int getNumRecs(char dataFile[]);

void getDataText(CadetInfoStructType cadetRecords[], int numRecs, char dataFile[]);

#endif  // LAB24FUNCTS_H