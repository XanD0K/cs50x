#include <cs50.h>
#include <stdio.h>

void coin25(int i, int *result_1, int *rest_quarter);
void coin10(int j, int *result_2, int *rest_dime);
void coin5(int k, int *result_3, int *rest_nickel);

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

    int change, result_1 = 0, result_2 = 0, result_3 = 0, rest_quarter = 0, rest_dime = 0, rest_nickel = 0;

    if (cash >= 25 )
    {
        coin25(cash, &result_1, &rest_quarter);
        if (rest_quarter > 0)
        {
            coin10(rest_quarter, &result_2, &rest_dime);
            if (rest_dime > 0)
            {
                coin5(rest_dime, &result_3, &rest_nickel);
            }
        }
        change = result_1 + result_2 + result_3 + rest_nickel;
        printf("You've got %i coins.\n", change);
    }
    else if (cash < 25 && cash >= 10)
    {
        coin10(cash, &result_2, &rest_dime);
            if (rest_dime > 0)
            {
                coin5(rest_dime, &result_3, &rest_nickel);
            }
        change = result_2 + result_3 + rest_nickel;
        printf("You've got %i coins.\n", change);
    }
    else if (cash < 10 && cash >= 5)
    {
        coin5(cash, &result_3, &rest_nickel);
        change = result_3 + rest_nickel;
        printf("You've got %i coins.\n", change);
    }
    else
    {
        printf("You've got %i coins.\n", cash);
    }
}

void coin25(int i, int *result_1, int *rest_quarter)
{
    *result_1 = i / 25;
    *rest_quarter = i % 25;
}

void coin10(int j, int *result_2, int *rest_dime)
{
    *result_2 = j / 10;
    *rest_dime = j % 10;
}

void coin5(int k, int *result_3, int *rest_nickel)
{
    *result_3 = k / 5;
    *rest_nickel = k % 5;
}
