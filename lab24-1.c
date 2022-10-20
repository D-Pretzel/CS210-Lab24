/* lab24-1.c
 * =============================================================
 *    Name:
 * Section:
 * Purpose: Practice using malloc / free
 * =============================================================
 */

#include <stdio.h>
#include <stdlib.h>

int main() {
    int numscore = 0;
    // Step 1:  Ask the user how many PFT scores to process
    printf("How many PFT scores: ");
    scanf("%d", &numscore);
    // Step 2:  Create an array with the exact size needed to store the PFT scores
    //          Hint:  Use malloc()
    int *pftScores = (int*)malloc(sizeof(int));

    // Step 3:  Get all the PFT Scores from the User
    //          (Store them in your array)
    for (int i = 0; i < numscore; i++) {
        printf("Enter a PFT score: ");
        scanf("%d", &pftScores[i]);
    }

    // Step 4:  Calculate the Average of the PFT Scores
    //          Hint:  Don't forget that the average can be a double!
    double sum;
    for (int i = 0; i < numscore; i++) {
        sum += pftScores[i];
    }
    double avg = sum / numscore;

    // Step 5:  Print the Average
    printf("The average PFT Score is %.1f\n", avg);

    // Step 6:  Reexamine All PFT Scores, and Count How Many are Lower than the Average
    int lower = 0;
    for (int i = 0; i < numscore; i++) {
        if (pftScores[i] < avg) {
            lower++;
        }
    }

    // Step 7:  Print the # of Cadets Lower than the Average
    printf("%d cadets are below the average\n", lower);

    // Step 8:  Free the Memory you malloc'ed in Step 2
    //          Hint:  Use free()
    free(pftScores);

    return 0;
}