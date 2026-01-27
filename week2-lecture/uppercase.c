#include <cs50.h>
#include <ctype.h>
#include <stdio.h>
#include <string.h>

int main(void)
{
    string s = get_string("Before: ");
    printf("After:  ");
    for(int i = 0, n = strlen(s); i < n; i++)
    {
        printf("%c", toupper(s[i]));
        /*
        if (s[i] >= 'a' && s[i] <= 'z')
        {
            //change s[i] to uppercase
            printf("%c", s[i] - 32); --> if you don't remember '32', just do ('a' - 'A')
            printf("%c", toupper(s[i])); --> the if loop is unnecessary, because the toupper function already handles the situations if the character is uppercase or lowercase
        }
        else
        {
            //just print s[i]
            printf("%c", s[i]);
        }
        */
    }
    printf("\n");

}
