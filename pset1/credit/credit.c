/*I've coded this without watching week2 lecture*/

#include <cs50.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void validate_length(string a);
void validate_initial_digits(char i[]);
void initial_and_length_check(char i[], string a);
char *checking_card_company(char j[]);

int main(void)
{
    string card_number = get_string("Insert your credit card number: ");

    char number_typed[17];
    int count;

    for (count = 0; count < strlen(card_number); count++)
    {
        number_typed[count] = card_number[count];
    }
    number_typed[count] = '\0';

    validate_length(card_number);
    validate_initial_digits(number_typed);
    initial_and_length_check(number_typed, card_number);
    checking_card_company(number_typed);

    string card_type = checking_card_company(number_typed);
    int sum_multiplication = 0, sum_remainder = 0;
    bool double_digit = true;

    for (int i = strlen(number_typed) - 1; i >= 0; i--)
    {
        int num_converted = card_number[i] - '0';
        if (double_digit)
        {
            int remainder_numbers = num_converted;
            sum_remainder = sum_remainder + remainder_numbers;
            double_digit = !double_digit;
        }

        else
        {
            int multiplication = num_converted * 2;
            sum_multiplication = sum_multiplication + multiplication / 10 + multiplication % 10;
            double_digit = !double_digit;
        }
    }

    int total_sum = sum_multiplication + sum_remainder;
    if (total_sum % 10 == 0)
    {
        printf("%s\n", card_type);
    }
    else
    {
        printf("INVALID\n");
    }

    free(card_type);
}

void validate_length(string a)
{
    if (strlen(a) < 13 || strlen(a) > 16)
    {
        printf("INVALID\n");
        exit(0);
    }
}

void validate_initial_digits(char i[])
{
    bool validity = false;
    if (i[0] == '4')
    {
        validity = true;
    }
    else if (i[0] == '3' && (i[1] == '4' || i[1] == '7'))
    {
        validity = true;
    }
    else if (i[0] == '5' &&
             ((i[1] == '1') || (i[1] == '2') || (i[1] == '3') || (i[1] == '4') || (i[1] == '5')))
    {
        validity = true;
    }

    if (!validity)
    {
        printf("INVALID\n");
        exit(0);
    }
}

void initial_and_length_check(char i[], string a)
{
    if ((i[0] == '4' && (strlen(a) != 13 && strlen(a) != 16)) ||
        ((i[0] == '3' && i[1] == '4') && strlen(a) != 15) ||
        ((i[0] == '3' && i[1] == '7') && strlen(a) != 15) ||
        ((i[0] == '5' && i[1] == '1') && strlen(a) != 16) ||
        ((i[0] == '5' && i[1] == '2') && strlen(a) != 16) ||
        ((i[0] == '5' && i[1] == '3') && strlen(a) != 16) ||
        ((i[0] == '5' && i[1] == '4') && strlen(a) != 16) ||
        ((i[0] == '5' && i[1] == '5') && strlen(a) != 16))
    {
        printf("INVALID\n");
        exit(0);
    }
}

char *checking_card_company(char j[])
{
    string card_type = malloc(10 * sizeof(char));
    if (j[0] == '4')
    {
        strcpy(card_type, "VISA");
    }
    else if ((j[0] == '3' && j[1] == '4') || (j[0] == '3' && j[1] == '7'))
    {
        strcpy(card_type, "AMEX");
    }
    else if ((j[0] == '5' && j[1] == '1') || (j[0] == '5' && j[1] == '2') ||
             (j[0] == '5' && j[1] == '3') || (j[0] == '5' && j[1] == '4') ||
             (j[0] == '5' && j[1] == '5'))
    {
        strcpy(card_type, "MASTERCARD");
    }

    return card_type;
}
