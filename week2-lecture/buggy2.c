#include <cs50.h>
#include <stdio.h>

void print_column(int height);

int main(void)
{
    int h = get_int("Height: ");
    print_column(h);
}

void print_column(int height)
{
    for (int i = 0; i <= height; i++)
    {
        printf("#\n");
    }
}

/*
debug50 let you go inside whats going on in the computer to understand better any error that you might have
Select a breakpoint and execute the command 'debug50 ./buggy3'
*/
