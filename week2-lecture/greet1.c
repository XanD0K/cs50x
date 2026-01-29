// Prints a command-line argument

#include <cs50.h>
#include <stdio.h>

int main(int argc, string argv[]) // Argument counter and argument vector
{
    if (argc == 2)
    {
        printf("hello, %s\n", argv[1]); //argv[0] will get the name of the program
    }
    else
    {
        printf("hello, world\n");
    }
}

/*
Now it requires to add the name in the command line (terminal)
Instead of saying './greet', now I need to say './greet (name)'
E.g. → ./greet Alexandre
*/
