#include <cs50.h>
#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char *cipher_text(string text, int k);

int main(int argc, string argv[])
{
    // Error message if more than 2 command lines
    if (argc != 2)
    {
        printf("Error!\n");
        return 1;
    }

    // Error message if second command line is not decimal digits
    for (int i = 0, length = strlen(argv[1]); i < length; i++)
    {
        if (!isdigit(argv[1][i]))
        {
            printf("Usage: ./caesar key\n");
            return 1;
        }
    }

    // Get key and user's input
    int key = atoi(argv[1]) % 26;
    string plaintext = get_string("plaintext:  ");

    string ciphertext = cipher_text(plaintext, key);

    printf("ciphertext: %s", ciphertext);
    printf("\n");
    free(ciphertext);
    return 0;
}

char *cipher_text(string text, int k)
{
    string encrypted_text = malloc(strlen(text) + 1);
    // Encryption process
    for (int i = 0, length = strlen(text); i < length; i++)
    {
        if (isalpha(text[i]) && isupper(text[i]))
        {
            encrypted_text[i] = (text[i] - 'A' + k) % 26 + 'A';
        }
        else if (isalpha(text[i]) && islower(text[i]))
        {
            encrypted_text[i] = (text[i] - 'a' + k) % 26 + 'a';
        }
        else
        {
            encrypted_text[i] = (text[i]);
        }
    }
    encrypted_text[strlen(text)] = '\0';

    return encrypted_text;
}
