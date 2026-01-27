#include <cs50.h>
#include <stdio.h>
#include <string.h>

/*int string_length(string s);*/

int main(void)
{
    string name = get_string("Name: ");

    /*
    int n = 0;
    while (name[n] != '\0')
    {
        n++;
    }
    printf("%i\n", n);
    */

    int length = strlen(name);
    printf("%i\n", length);
}

/*
int string_length(string s)
{
    int n = 0;
    while (s[n] != '\0')
    {
        n++;
    }
    return n;
}
*/
