#include <cs50.h>
#include <ctype.h>
#include <stdio.h>
#include <stdlib.h> // to use malloc
#include <string.h>

int main(void)
{
    char *s = get_string("s: ");

    //char *t = s; -> This will create a new variable 't' that points to the same address as the variable 's'

    char *t = malloc(strlen(s) + 1); // '+1' for the NUL terminator
    if (t == NULL) // If there is no memory allocated by 'malloc'
    {
        return 1;
    }

    /*
    for (int i = 0, n = strlen(s); i <= n; i++) // setting 'i <= n' will also copy the NUL character
    {
        t[i] = s[i];
    }
    */

    //instead of doing the 'for' loop above, use the 'strcpy' function
    strcpy(t, s);

    if (strlen(t) > 0) // Just do that if the user typed something. Otherwise, it's unnecesary
    {
        t[0] = toupper(t[0]);
    }

    printf("s: %s\n", s);
    printf("t: %s\n", t);

    free(t); // Always 'free' when using 'malloc'
}

// In case of error, 'malloc' returns '0' (NULL)
