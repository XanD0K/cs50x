// Prints string char by char, using strlen

#include <cs50.h>
#include <stdio.h>
#include <string.h>

int main(void)
{
    string s = get_string("Input:  ");
    printf("Output: ");
    for (int i = 0; i < strlen(s); i++) // It wrongfully checks the length in every iteration
    {
        printf("%c", s[i]);
    }
    printf("\n");
}
