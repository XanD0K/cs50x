#include <cs50.h>
#include <stdio.h>

int calculate_coins(int i);

int main(void)
{
    int cash = get_int("Change owned: ");
    if (cash < 1)
    {
        do
        {
            cash = get_int("Please, provide a positive number: ");
        }
        while (cash < 1);
    }

    int change = calculate_coins(cash);
    printf("You've got %i coins.\n", change);
}

int calculate_coins(int amount)
{
    const int nickel = 5, dime = 10, quarter = 25;
    int total_coins, result_quarter = 0, result_dime = 0, result_nickel = 0, rest_quarter = 0, rest_dime = 0, rest_nickel = 0;

    if (amount >= 25)
    {
        result_quarter = amount / quarter;
        rest_quarter = amount % quarter;
        if (rest_quarter > 0)
        {
            result_dime = rest_quarter / dime;
            rest_dime = rest_quarter % dime;
            if (rest_dime > 0)
            {
                result_nickel = rest_dime / nickel;
                rest_nickel = rest_dime % nickel;
            }
        }
        total_coins = result_quarter + result_dime + result_nickel + rest_nickel;
    }
    else if (amount < 25 && amount >= 10)
    {
        result_dime = amount / dime;
        rest_dime = amount % dime;
        if (rest_dime > 0)
        {
            result_nickel = rest_dime / nickel;
            rest_nickel = rest_dime % nickel;
        }
        total_coins = result_dime + result_nickel + rest_nickel;
    }
    else if (amount < 10 && amount >= 5)
    {
        result_nickel = amount / nickel;
        rest_nickel = amount % nickel;
        total_coins = result_nickel + rest_nickel;
    }
    else
    {
        total_coins = amount;
    }

    return total_coins;
}
