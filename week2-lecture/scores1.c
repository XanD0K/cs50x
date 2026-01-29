// Averages three (hardcoded) numbers using an array

#include <cs50.h>
#include <stdio.h>

int main(void)
{
    // Scores
    int scores[3];
    scores[0] = 72;
    scores[1] = 73;
    scores[2] = 33;

    // Print average
    printf("Average: %f\n", (scores[0] + scores[1] + scores[2]) / 3.0);


    // Get scores
    int new_scores[3];
    new_scores[0] = get_int("Score: ");
    new_scores[1] = get_int("Score: ");
    new_scores[2] = get_int("Score: ");

    // Print average
    printf("Average: %f\n", (new_scores[0] + new_scores[1] + new_scores[2]) / 3.0);


}
