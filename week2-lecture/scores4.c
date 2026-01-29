#include <cs50.h>
#include <stdio.h>

// CONSTANT
const int N = 3; // For constans, it's usual to use CAPITAL LETTERS, and to declare them in the top of the code

// PROTOTYPE
float average(int length, int array[]);

int main(void)
{
    //Get scores
    int scores[N];

    for (int i = 0; i < N; i++)
    {
        scores[i] = get_int("Score: ");
    }

    //Print average
    printf("Average: %f\n", average(N, scores));
}

// Calculate average
float average(int length, int array[]) /* WHEN A FUNCTION TAKES AS INPUT SOMEONE ELSE'S ARRAY, OU DON'T HAVE TO KNOW IN ADVANCE IT'S SIZE
                                          BUT YOU NEED TO MAKE THE SURE THE CALLER ALSO TAKES A SECOND ARGUMENT THAT SAYS HOW BIG IT IS */
{
    int sum = 0;
    for (int i = 0; i < length; i++)
    {
        sum += array[i];
    }

    return sum / (float) length;
}

