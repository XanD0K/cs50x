#include <cs50.h>
#include <stdio.h>

void blocks(int n);
void spaces(int m);

int main(void)
{
    int height;
    do
    {
        height = get_int("Provide a number between 1 and 8: ");
    }
    while (height < 1 || height > 8);

    int space_counter = height - 1;
    int block_counter = 1;

    for (int rows = 0; rows < height; rows++)
    {
        spaces(space_counter);
        blocks(block_counter);
        space_counter--;
        block_counter++;
        printf("\n");
    }
}

void blocks(int n)
{
    for (int i = 0; i < n; i++)
    {
        printf("#");
    }
}

void spaces(int m)
{
    for (int i = 0; i < m; i++)
    {
        printf(" ");
    }
}