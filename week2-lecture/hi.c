#include <cs50.h>
#include <stdio.h>

int main(void)
{
    /*
    char c1 = 'H';
    char c2 = 'I';
    char c3 = '!';

    printf("%c%c%c\n", c1, c2, c3);
    printf("%i %i %i\n", c1, c2, c3);
    */

    /*
    string s = "HI!";
    printf("%s\n", s);
    printf("%c%c%c\n", s[0], s[1], s[2]);
    printf("%i %i %i %i\n", s[0], s[1], s[2], s[3]);
    */

    /*
    string s = "HI!";
    string t = "BYE!";

    printf("%s\n", s);
    printf("%s\n", t);
    */

    string words[2];
    words[0] = "HI!";
    words[1] = "BYE!";
    printf("%s\n", words[0]);
    printf("%c%c%c\n", words[0][0], words[0][1], words[0][2]);
    printf("%s\n", words[1]);
    printf("%c%c%c%c\n", words[1][0], words[1][1], words[1][2], words[1][3]);


}

/*
The computer knows when the string stops because it actually ends with an 0 (a byte full of zeros), represented by '\0'. It's called NUL, and is the 0 on ASCII chart.
So the string "HI!" actual sizer is 4!
The double quotes " says to the computer that it's a string, and the computer automatically puts an NUL at the end of it.
*/
