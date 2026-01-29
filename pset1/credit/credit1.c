#include <cs50.h>
#include <stdio.h>
#include <string.h>

int main(void)
{
    string cc_number;
    do
    {
        cc_number = get_string("Credit Card number: ");
    }
    while (strlen(cc_number) < 1);

    int cc_length = strlen(cc_number);
    int total_sum = 0;

    // Move backwards, starting from last digit, aplying Luhn's algorithm
    for (int digit = cc_length - 1; digit >= 0; digit--)
    {
        int current_number = cc_number[digit] - '0';

        if ((cc_length - digit) % 2 == 0)
        {
            int doubled = current_number * 2;
            total_sum += (doubled / 10 + doubled % 10);
        }
        else
        {
            total_sum += current_number;
        }
    }

    if (total_sum % 10 != 0)
    {
        printf("INVALID\n");
        return 0;
    }

    int cc_first = cc_number[0] - '0';
    int cc_first_two = (cc_number[0] - '0') * 10 + (cc_number[1] - '0');

    if (cc_length == 15 && (cc_first_two == 34 || cc_first_two == 37))
    {
        printf("AMEX\n");
    }
    else if (cc_length == 16 && (cc_first_two >= 51 && cc_first_two <= 55))
    {
        printf("MASTERCARD\n");
    }
    else if ((cc_length == 13 || cc_length == 16) && cc_first == 4)
    {
        printf("VISA\n");
    }
    else
    {
        printf("INVALID\n");
    }
}
