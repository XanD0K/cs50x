#include <cs50.h>
#include <stdio.h>

int main(void)
{
    int change;
    do
    {
        change = get_int("Change Owed: ");
    }
    while (change < 0);

    int total_coins = 0;

    int quarter = 25;
    int dime = 10;
    int nickel = 5;
    int penny = 1;

    while (change > 0)
    {
        if (change >= 25)
        {
            total_coins++;
            change -= quarter;
        }

        else if (change >= 10)
        {
            total_coins++;
            change -= dime;
        }

        else if (change >= 5)
        {
            total_coins++;
            change -= nickel;
        }

        else
        {
            total_coins++;
            change -= penny;
        }
    }

    printf("%i\n", total_coins);
    return 0;
}
