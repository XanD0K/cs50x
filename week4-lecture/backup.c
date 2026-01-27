#include <cs50.h> // Allows to use the 'string' type variable
#include <stdio.h>

int main(void)
{
    /*
    int n = 50;
    int *p = &n; // 'p' is declared as a pointer. * means the p is a pointer that points to an integer. '&n' means get the address of 'n'
    printf("%i\n", n);
    printf("%p\n", p);
    */

    /*
    int n = 50;
    printf("%p\n", &n); // another sintaxe
    printf("%p\n", n); // another sintaxe

    int m = 50;
    int *p = &m;
    printf("%i\n", *p); // Will print the value of 'n'
    */

    // string s = "HI!"; // string s means that 's' points to the first character of the "string" ('H"). 's' is a pointer! 's' is a char * variable

    char *s = "HI!"; // 'char *s' is the same as 'string s'. Using 'char *', the cs50.h is not needed to declare a string variable
    printf("%s\n", s); // even when using 'char *', you use '%s' to print it. '%s' is supported in C language
    printf("%p\n", s); // will print the address of the first character of te 'char *', just like '&s[0]' would
    printf("%p\n", &s[0]);
    printf("%p\n", &s[1]);
    printf("%p\n", &s[2]);
    printf("%p\n", &s[3]);

    printf("%c\n", s[0]);
    printf("%c\n", s[1]);
    printf("%c\n", s[2]);

    printf("%c\n", *s);
    printf("%c\n", *(s+1));
    printf("%c\n", *(s+2));

    printf("%s\n", s + 1); // 's + 1' means start at 's + 1' (the second character)
    printf("%s\n", s + 2); // 's + 2' means start at 's + 2' (the third character)


}

/*
& -> address of operator
* -> dereference operator (how to get to something)
%p -> print pointers (addresses)
*/
