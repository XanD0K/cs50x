#include <cs50.h>
#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char *cipher_text(string text, string k);

int main(int argc, string argv[])
{
    // Check if there is only 2 command lines, and if the second command line has 26 length
    if ((argc != 2) || (strlen(argv[1]) != 26))
    {
        printf("Error!\n");
        return 1;
    }

    // Check if second command line has any non-alphabetical character
    for (int i = 0, length = strlen(argv[1]); i < length; i++)
    {
        if (!isalpha(argv[1][i]))
        {
            printf("Error!\n");
            return 1;
        }
    }

    // Check if second command line has duplicate characters
    for (int i = 0, length = strlen(argv[1]); i < length; i++)
    {
        for (int j = 0; j < length; j++)
        {
            if ((toupper(argv[1][i]) == toupper(argv[1][j])) && (i != j))
            {
                printf("Error!\n");
                return 1;
            }
        }
    }

    /* ANOTHER APPROACH TO CHECK DUPLICATE CHARACTERS
    "By using a boolean array, you can keep track of which letters you’ve already seen, and quickly
    determine if a letter is a duplicate. This approach is both time-efficient and space-efficient".

    bool alphabet[26];
    for (int i = 0, length = strlen(alphabet); i < length; i++)
    {
        alphabet[i] = false;
    }

    for (int i = 0, length = 26; i < length, i++)
    {
        if (isupper(argv[1][i]))
        {
            if (alphabet[argv[1][i] - 'A'] == true)
            {
                printf("Error!\n");
                return 1;
            }
            alphabet[argv[1][i] - 'A'] = true;
        }

        else if (islower(argv[1][i]))
        {
            if (alphabet[argv[1][i] - 'a'] == true)
            {
                printf("Error!\n");
                return 1;
            }
            alphabet[argv[1][i] - 'a'] = true;
        }
    }
    */

    string key = argv[1];
    string plaintext = get_string("plaintext:");

    string ciphertext = cipher_text(plaintext, key);

    printf("ciphertext: %s", ciphertext);
    printf("\n");
    free(ciphertext);
    return 0;
}

char *cipher_text(string text, string k)
{
    string encrypted_text = malloc(strlen(text) + 1);

    for (int i = 0, length = strlen(text); i < length; i++)
    {
        if (isalpha(text[i]) && isupper(text[i]))
        {
            encrypted_text[i] = toupper(k[text[i] - 'A']);
        }
        else if (isalpha(text[i]) && islower(text[i]))
        {
            encrypted_text[i] = tolower(k[text[i] - 'a']);
        }
        else
        {
            encrypted_text[i] = text[i];
        }
    }
    encrypted_text[strlen(text)] = '\0';

    return encrypted_text;
}
