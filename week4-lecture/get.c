#include <stdio.h>

int main (void)
{
    int n;
    printf("n: ");
    scanf("%i", &n); //can't just put the variable. Need to pass the address of the variable
    printf("n: %i\n", n);

    char *s;
    printf("s: ");
    scanf("%s", s); // Don't need an '&' operator here, because 's' is already a 'char *'
    printf("s: %s\n", s);
}
