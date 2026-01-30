#include <cs50.h>
#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

string get_ciphertext(string text, int key);

int main(int argc, string argv[])
{
    // Check CLI
    if (argc != 2)
    {
        printf("Usage: ./caesar key\n");
        return 1;
    }

    // Check key is number
    for (int i = 0, length = strlen(argv[1]); i < length; i++)
    {
        if (!isdigit(argv[1][i]))
        {
            printf("Usage: ./caesar key\n");
            return 1;
        }
    }

    // Get key
    int key = atoi(argv[1]) % 26;

    string plaintext = get_string("plaintext:  ");
    string ciphertext = get_ciphertext(plaintext, key);

    printf("ciphertext: %s\n", ciphertext);
    return 0;
}

string get_ciphertext(string text, int key)
{
    int plaintext_length = strlen(text);

    for (int i = 0, length = plaintext_length; i < length; i++)
    {
        if (isalpha(text[i]) && islower(text[i]))
        {
            text[i] = (text[i] - 'a' + key) % 26 + 'a';;
        }
        else if (isalpha(text[i]) && isupper(text[i]))
        {
            text[i] = (text[i] - 'A' + key) % 26 + 'A';
        }
        else
        {
            text[i] = text[i];
        }
    }

    return text;
}
