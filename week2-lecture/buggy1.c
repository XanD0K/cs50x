#include <cs50.h>
#include <stdio.h>

void print_column(int height);

int main(void)
{
    for (int i = 0; i <= 3; i++) // I want 3 blocks, but it prints 4
    {
        printf("i is %i\n", i); // Printing the values is also a form of debbuging
        printf("#\n");
    }
}
