#include <cs50.h>
#include <ctype.h>
#include <math.h>
#include <stdio.h>
#include <string.h>

int count_letters(string text);
int count_words(string text);
int count_sentences(string text);
float calculate_cli(int letters, int words, int sentences);

int main(void)
{
    string text = get_string("Text: ");

    int count_letters = 0;
    int count_words = 0;
    int count_sentences = 0;
    bool is_word = false;

    for (int i = 0, length = strlen(text); i < length; i++)
    {
        if (isalpha(text[i]))
        {
            count_letters++;
            if (!is_word)
            {
                count_words++;
                is_word = true;
            }
        }
        else if (text[i] == '\'' || text[i] == '-')
        {
            is_word = true;
        }
        else if (text[i] == '.' || text[i] == '!' || text[i] == '?')
        {
            count_sentences++;
            is_word = false;
        }
        else
        {
            is_word = false;
        }
    }

    int cli = round(calculate_cli(count_letters, count_words, count_sentences));

    if (cli < 1)
    {
        printf("Before Grade 1\n");
    }
    else if (cli > 16)
    {
        printf("Grade 16+\n");
    }
    else
    {
        printf("Grade %i\n", cli);
    }
}

float calculate_cli(int letters, int words, int sentences)
{
    float L = ((float) letters / words) * 100;
    float S = ((float) sentences / words) * 100;
    float cli = 0.0588 * L - 0.296 * S - 15.8;
    return cli;
}
