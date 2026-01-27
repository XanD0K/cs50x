#include <cs50.h>
#include <stdio.h>
#include <string.h>

int main(void)
{
    /*
    Linear Search
    int numbers[] = {20, 500, 10, 5, 100, 1, 50};
    int n = get_int("Number: ");
    for (int i = 0; i < 7; i++)
    {
        if (numbers[i] == n)
        {
            printf("Found!\n");
            return 0; // This will prevent code to print "Not found!" after the 'for' loop.
        }
    }
    printf("Not found!\n");
    return 1;
    */

    string strings[] = {"battleship", "boot", "cannon", "iron", "thimble", "top hat"};
    string s = get_string("String: ");
    for (int i = 0; i < 6; i++)
    {
        /*Can't use double equals signs to compare strings (strings[i] == s). Must use the strcmp 'function'.
        This Function compares the ASCII values of the string, and output numbers based on which one comes before/after the other, of if they are the same*/
        if (strcmp(strings[i], s) == 0)
        {
            printf("Found!\n");
            return 0;
        }
    }
    printf("Not found!\n");
    return 1;
}
