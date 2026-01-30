#include <cs50.h>
#include <ctype.h>
#include <math.h>
#include <stdio.h>
#include <string.h>

int main(void)
{
    string text = get_string("Text: ");
    int letters_counter = 0, words_counter = 1, sentences_counter = 0;

    for (int i = 0, length = strlen(text); i < length; i++)
    {
        if (isalpha(text[i]))
        {
            letters_counter++;
        }

        else if (text[i] == ' ')
        {
            words_counter++;
        }

        else if (text[i] == '.' || text[i] == '!' || text[i] == '?')
        {
            sentences_counter++;
        }
    }

    const int hundred = 100;
    float letters_per_words, sentences_per_words;
    float const1 = 0.0588, const2 = 0.296, const3 = 15.8;

    letters_per_words = ((float) letters_counter / (float) words_counter) * hundred;
    sentences_per_words = ((float) sentences_counter / (float) words_counter) * hundred;

    float formula = (const1 * letters_per_words) - (const2 * sentences_per_words) - const3;
    int grade = round(formula);

    if (grade < 1)
    {
        printf("Before Grade 1\n");
    }
    else if (grade > 16)
    {
        printf("Grade 16+\n");
    }
    else
    {
        printf("Grade %i\n", grade);
    }
}
