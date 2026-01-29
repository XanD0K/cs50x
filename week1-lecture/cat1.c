#include <cs50.h>
#include <stdio.h>

void meow(int n);

int main(void)
{ 
    int n = get_int("What's n? ");
    if (n < 0) // It will run just once
    {
        n = get_int("What's n? ");
    }
    meow(n);
}


void meow(int n)
{
    for (int i = 0; i < n; i++) // Also change the number here to 'n'
    {
        printf("meow\n");
    }
}

// There are different 'n's in the code. The variables only exist inside their curly braces
