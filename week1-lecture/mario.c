#include <stdio.h>

void print_row(int n);

int main(void)
{
    /*
    for (int i = 0; i < 4; i++)
    {
        printf("?");
    }
    printf("\n");

    for (int i = 0; i < 3; i++)
    {
        printf("#\n");
    }
    */

    /*
    for (int row = 0; row < 5; row++)
    {
        for (int column = 0; column < 7; column++)
        {
            printf("#");
        }
        printf("\n");
    }
    */


    const int n = 3; // 'const' make the variable constant and unchangeable
    for (int i = 0; i < n; i++)
    {
        print_row(n);
    }

}

void print_row(int n)
{
    for (int i = 0; i < n; i++)
    {
        printf("#");
    }
    printf("\n");
}
