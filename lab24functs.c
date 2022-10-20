/* lab24functs.c
 * =============================================================
 *    Name:
 * Section:
 * Purpose: Practice using malloc / free
 * =============================================================
 */


#include "lab24functs.h"

int getNumRecs(char dataFile[]){
    char buff[10];

    FILE* fp = fopen(dataFile, "r");
    fgets(buff, 10, fp);
    fclose(fp);

    return atoi(buff);
}

void getDataText(CadetInfoStructType cadetRecords[], int numRecs, char dataFile[]){
    FILE* fp = fopen(dataFile, "r");
    char junk[100];
    fgets(junk, 100, fp);

    for (int i = 0; i < numRecs; i++){
        fscanf(fp, "%s %s %d %d %d\n", cadetRecords[i].last, cadetRecords[i].first, &cadetRecords[i].age, &cadetRecords[i].squad, &cadetRecords[i].year);
        strcpy(cadetRecords[i].name, cadetRecords[i].first);
        strcat(cadetRecords[i].name, " ");
        strcat(cadetRecords[i].name, cadetRecords[i].last);
    }

    fclose(fp);
}

