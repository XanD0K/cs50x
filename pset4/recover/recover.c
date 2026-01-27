#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>

typedef uint8_t BYTE;

int main(int argc, char *argv[])
{
    if (argc != 2)
    {
        printf("usage: ./recover.c card.raw\n");
        return 1;
    }

    FILE *card = fopen("card.raw", "r");

    if (card == NULL)
    {
        printf("Couldn't open the file\n");
        return 1;
    }

    BYTE buffer[512];
    char filename[8]; // It includes all 7 character plus the NUL terminator
    int counter = 0;
    FILE *output_image = NULL; // Set as NULL to prevent the fopen to use garbage values

    while (fread(buffer, 1, 512, card) == 512)
    // My ideia: 'while (fread(buffer, sizeof(buffer), 1, card) == 1)'

    {
        // First 'if' will check until find an .jpg file. It will create a new file
        // '&' works like the 'AND' logical preposition
        if (buffer[0] == 0xff && buffer[1] == 0xd8 && buffer[2] == 0xff &&
            (buffer[3] & 0xf0) == 0xe0)
        {
            if (output_image != NULL)
            {
                fclose(output_image);
            }

            sprintf(filename, "%03i.jpg", counter);
            output_image = fopen(filename, "w");
            if (output_image == NULL) // If I can't open the "forensic image"
            {
                printf("Couldn't open %s\n", filename);
                fclose(card);
                return 1;
            }
            counter++;
        }

        if (output_image != NULL)
        {
            fwrite(buffer, 1, 512, output_image);
        }
    }

    if (output_image != NULL)
    {
        fclose(output_image);
    }
    fclose(card);
}

// TODO: code a program that handles all junks and garbage values
