#include <cs50.h>
#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

string get_ciphertext(string text, string key);

int main(int argc, string argv[])
{
    if (argc != 2)
    {
        printf("Usage: ./substitution key\n");
        return 1;
    }

    if (strlen(argv[1]) != 26)
    {
        printf("key must contain exactly 26 characters\n");
        return 1;
    }

    bool used[26] = {false};

    for (int i = 0, length = strlen(argv[1]); i < length; i++)
    {
        int index = toupper(argv[1][i]) - 'A';

        if (!isalpha(argv[1][i]))
        {
            printf("key must contain only alphabetical characters\n");
            return 1;
        }
        else if (used[index] == true)
        {
            printf("characters must not repeat\n");
            return 1;
        }
        used[index] = true;
    }

    string plaintext = get_string("plaintext:");
    string ciphertext = get_ciphertext(plaintext, argv[1]);

    printf("ciphertext: %s\n", ciphertext);
    free(ciphertext);
    return 0;
}

string get_ciphertext(string text, string key)
{
    string ciphertext = calloc(strlen(text) + 1, sizeof(char));

    for (int i = 0, length = strlen(text); i < length; i++)
    {
        int index = toupper(text[i]) - 'A';

        if (isupper(text[i]))
        {
            ciphertext[i] = toupper(key[index]);
        }
        else if (islower(text[i]))
        {
            ciphertext[i] = tolower(key[index]);
        }
        else
        {
            ciphertext[i] = text[i];
        }
    }

    return ciphertext;
}
