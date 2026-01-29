// Multiple strings

#include <cs50.h>
#include <stdio.h>

int main(void)
{
    string s = "HI!";
    string t = "BYE!";

    printf("%s\n", s);
    printf("%c%c%c\n", s[0], s[1], s[2]);

    printf("%s\n", t);
    printf("%c%c%c\n", t[0], t[1], t[2], t[3]);
}
