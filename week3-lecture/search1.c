// Implements linear search for strings

#include <cs50.h>
#include <stdio.h>
#include <string.h>

int main(void)
{
    // An array of strings
    string strings[] = {"battleship", "boot", "cannon", "iron", "thimble", "top hat"};

    // Search for string
    string s = get_string("String: ");
    for (int i = 0; i < 6; i++)
    {
        if (strcmp(strings[i], s) == 0)
        {
            printf("Found\n");
            return 0;
        }
    }
    printf("Not found\n");
    return 1;
}

/*
Can't use double equals signs to compare strings (strings[i] == s)
Must use the 'strcmp' function
This Function compares the ASCII values of the string
It outputs:
- 0 if both strings are equal
- Positive and Negative numbers to determine which one comes first based on their ASCII values
*/
