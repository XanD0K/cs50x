#include <stdio.h>
#include <stdint.h>

typedef uint8_t BYTE; // gives a byte of 8 bits

int main(int argc, char *argv[])
{
    FILE *src = fopen(argv[1], "rb"); // read in binary
    FILE *dst = fopen(argv[2], "wb"); // write in binary

    if (src == NULL || dst == NULL) // Improving the code
    {
        return 1;
    }

    BYTE b;

    while (fread(&b, sizeof(b), 1, src) != 0) // Will iterate over all the byters in the file, one at a time, and write them in de destination file
    {
        fwrite(&b, sizeof(b), 1, dst);
    }

    fclose(dst);
    fclose(src);
}
