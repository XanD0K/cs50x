#include <cs50.h>
#include <stdio.h>

void meow(int n);

int main(void)
{
    /*
    while (true)
    {
        int n = get_int("What's n? ");
        if (n < 0)
        {
            continue; → go back to the start of the loop
        }
        else
        {
            break; → break out of the loop
        }
    }
    */


    int n; // Declare the variable outside of the "do" curly braces, and make it exists in the outter most scope of the function
    do // 'do-while' loops ensure the code is executed at least once
    {
        n = get_int("Number: "); // If you declare int = n inside the "do" curly braces, it will only exists inside that block
    }
    while (n < 1);
    meow(n);
}


void meow(int n)
{
    for (int i = 0; i < n; i++) // Also change the number here to 'n'
    {
        printf("meow\n");
    }
}
