#include <cs50.h>
#include <stdio.h>

void print_column(int height);

int main(void)
{
    /*
    for (int i = 0; i <= 3; i++) //I want 3 blocks, but it prints 4
    {
        printf("i is %i\n", i); //It's a form of debbugin! To see whats going on
        printf("#\n");
    }
    */

    int h = get_int("Height: ");
    print_column(h);
}

void print_column(int height)
{
    for (int i = 0; i <= height; i++)
    {
        printf("#\n");
    }
}co

/*debug50 let you go inside whats going on in the computer to understand better any error that you might have*/
