/* lab24functs.c
 * =============================================================
 *    Name:
 * Section:
 * Purpose: Practice using malloc / free
 * =============================================================
 */

#include "lab24functs.h"

int getNumRecs(char dataFile[]){
    FILE* fp = fopen(dataFile, "r");
    printf("Opening file %s\n", dataFile);
    if (fp == NULL) {
        printf("Error opening file!\n");
        return -1;
    }

    char buff[10];
    fgets(buff, 10, fp);
    fclose(fp);

    return atoi(buff);
}

void getDataText(CadetInfoStructType cadetRecords[], int numRecs, char dataFile[]){
    FILE* fp = fopen(dataFile, "r");
    char* junk = (char*)malloc(10 * sizeof(char));
    fgets(junk, sizeof(junk), fp);

    for (int i = 0; i < numRecs; i++){
        fscanf(fp, "%s %s %d %d %d\n", cadetRecords[i].last, cadetRecords[i].first, &cadetRecords[i].age, &cadetRecords[i].squad, &cadetRecords[i].year);
        strcpy(cadetRecords[i].name, cadetRecords[i].first);
        strcat(cadetRecords[i].name, " ");
        strcat(cadetRecords[i].name, cadetRecords[i].last);
    }

    fclose(fp);
}

