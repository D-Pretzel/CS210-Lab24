/* lab24-2.c
 * =============================================================
 *    Name:
 * Section:
 * Purpose: Practice using malloc / free
 * =============================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "lab24functs.h"

int main() {

    // FOLLOW THE LAB INSTRUCTIONS BEFORE WRITING CODE!
    // Call getNumRecs() with the appropriate parameters
    // Store the result in a variable
    char* filename = (char*)malloc(10 * sizeof(char));
    printf("Enter the name of the file: \n");
    scanf("%s", filename);

    int numRecs = getNumRecs(filename);

    // Print the Number of Records in the File (according to getNumRecs)
    printf("%d records in the data file.\n", numRecs);

    // Using the value obtained above, dynamically allocate an array of CadetInfoStructType that is exactly the right size
    // to hold the number of records in the data file
    CadetInfoStructType* cadetRecords = (CadetInfoStructType*)malloc(numRecs * sizeof(CadetInfoStructType));

    // Call getDataText() to read the file data into the dynamically allocated array
    getDataText(cadetRecords, numRecs, filename);

    // Print the First Cadet
    printf("The first cadet is:\nCadet name = %s\nCadet age = %d\nCadet squad = %d\nCadet year = %d\n", cadetRecords[0].name, cadetRecords[0].age, cadetRecords[0].squad, cadetRecords[0].year);

    // Print the Last Cadet
    printf("The last cadet is:\nCadet name = %s\nCadet age = %d\nCadet squad = %d\nCadet year = %d\n", cadetRecords[numRecs - 1].name, cadetRecords[numRecs - 1].age, cadetRecords[numRecs - 1].squad, cadetRecords[numRecs - 1].year);

    // Free the array
    free(cadetRecords);

    return 0;
}