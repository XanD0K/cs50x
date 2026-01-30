#include <cs50.h>
#include <ctype.h>
#include <stdio.h>
#include <string.h>

int scores[26] = {1, 3, 3, 2, 1, 4, 2, 4, 1, 8, 5, 1, 3, 1, 1, 3, 10, 1, 1, 1, 1, 4, 4, 8, 4, 10};

void convert_to_upper(string a);
int calculate_score(string b);

int main(void)
{
    string words[2];
    words[0] = get_string("Player1: ");
    words[1] = get_string("Player2: ");

    convert_to_upper(words[0]);
    convert_to_upper(words[1]);

    int score1 = calculate_score(words[0]);
    int score2 = calculate_score(words[1]);

    if (score1 > score2)
    {
        printf("Player 1 wins!\n");
    }
    else if (score1 < score2)
    {
        printf("Player 2 wins!\n");
    }
    else
    {
        printf("Tie!\n");
    }
}

void convert_to_upper(string a)
{
    for (int i = 0, length = strlen(a); i < length; i++)
    {
        a[i] = toupper(a[i]);
    }
}

int calculate_score(string b)
{
    int asc2 = 65;
    int position = 0, sum = 0;
    for (int i = 0, length = strlen(b); i < length; i++)
    {
        if isalpha (b[i])
        {
            position = (b[i] - asc2);
            sum = sum + scores[position];
        }
    }
    return sum;
}
