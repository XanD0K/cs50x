#include <cs50.h>
#include <stdio.h>

int main(int argc, string argv[])
{
    // It will prints whatever is typed in the command line, each word in a different line
    for (int i = 0; i < argc; i++)
    {
        printf("%s\n", argv[i]);
    }
}

/*
ASCII art / cowsay
cowsat moo
cowsay -f duck quack
cowsay -f dragon RAWR
*/
