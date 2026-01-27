#include <cs50.h>
#include <stdio.h>

void space(int n);
void block(int m);

int main(void)
{
    int height = get_int("Provide a positive number between 1 and 8: ");
    if (height < 1 || height > 8)
    {
        do
        {
            height = get_int("Please, provide a valid number between 1 and 8: ");
        }
        while (height < 1 || height > 8);
    }

    int counter_space = height - 1;
    int counter_block = 1;

    for (int row = 0; row < height; row++)
    {
        space(counter_space);
        block(counter_block);
        counter_space--;
        counter_block++;
        printf("\n");
    }
}

void space(int n)
{
    for (int i = 0; i < n; i++)
    {
        printf(" ");
    }
}

void block(int m)
{
    for (int i = 0; i < m; i++)
    {
        printf("#");
    }
}
