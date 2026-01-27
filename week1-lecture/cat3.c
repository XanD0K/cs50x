#include <cs50.h>
#include <stdio.h>

void meow(int n);

int main(void)
{
    int n; //declare the variable outside of the "do" curly braces, and make it exists in the outter most scope of the function.
    do //do...while is a kind of loop usefull to get inputs from user that keep typing the wrong thing
    {
        n = get_int("Number: "); //If you declare int = n insede the "do" curly braces, it will only exists here. Do it outside of it so you can you it again .
    }
    while (n < 1);
    meow(n);
}


void meow(int n)
{
    for (int i = 0; i < n; i++) //also change the number here to 'n'
    {
        printf("meow\n");
    }
}
