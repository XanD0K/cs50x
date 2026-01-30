// Recursion is a function that calls itself

#include <cs50.h>
#include <stdio.h>

void draw(int n);

int main(void)
{
    int height = get_int("Height: ");
    draw(height);
}

void draw(int n)
{
    // Base case
    if (n <= 0)
    {
        return; // Don't return a value (void)
    }

    // Print a pyramid of height n-1
    draw(n - 1);

    // Print one more row
    for (int i = 0; i < n; i++)
    {
        printf("#");
    }
    printf("\n");
}
