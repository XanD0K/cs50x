#include <cs50.h>
#include <stdio.h>
#include <string.h>

int main(void)
{
    string s = get_string("Input:  "); //2 spaces so Input and Output get lined up.
    printf("Output: ");
    /*int length = strlen(s); I can declare it outside
    for(int i = 0; i < length//strlen(s); i++) //the length of the functions won't change, so it is inapropriateto call the strlen function in every iteration of the for loop.*/
    for(int i = 0, n = strlen(s); i < n; i++)
    {
        printf("%c", s[i]);
    }
    printf("\n");
}
