#include <cs50.h>
#include <stdio.h>

int get_coins(int change, int coin);
int get_remainder(int change, int coin);

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

    if (change >= 25)
    {
        total_coins += get_coins(change, quarter);
        change = get_remainder(change, quarter);
        if (change == 0)
        {
            printf("%i\n", total_coins);
            return 0;
        }
    }

    if (change >= 10)
    {
        total_coins += get_coins(change, dime);
        change = get_remainder(change, dime);
        if (change == 0)
        {
            printf("%i\n", total_coins);
            return 0;
        }
    }

    if (change >= 5)
    {
        total_coins += get_coins(change, nickel);
        change = get_remainder(change, nickel);
        if (change == 0)
        {
            printf("%i\n", total_coins);
            return 0;
        }
    }

    total_coins += change;
    printf("%i\n", total_coins);
    return 0;
}

int get_coins(int change, int coin)
{
    return change / coin;
}

int get_remainder(int change, int coin)
{
    return change % coin;
}
