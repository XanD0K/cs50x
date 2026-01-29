// Prints string

#include <cs50.h>
#include <stdio.h>

int main(void)
{
    string s = "HI!";

    printf("%s\n", s);
    printf("%c%c%c\n", s[0], s[1], s[2]);

    printf("%i %i %i %i\n", s[0], s[1], s[2], s[3]);
}

/*
The computer knows when the string stops because it actually ends with an 0 (a byte full of zeros), represented by '\0'. It's called NUL, and is the 0 on ASCII chart
So the string "HI!" actual sizer is 4!
The double quotes " says to the computer that it's a string, and the computer automatically puts an NUL at the end of it
*/
