//COMMAND LINES
#include <cs50.h>
#include <stdio.h>

int main(int argc, string argv[]) //argument counter and argument vector //I will need to add the name in the command lne (terminal). instead of saying './greet', now I need to say './greet (name)' like ./greet Alexandre
{
    /*
    if (argc == 2)
    {
        printf("hello, %s\n", argv[1]); //argv[0] will get the name of the program
    }
    else
    {
        printf("hello, world\n");
    }
    */


    //It will prints whatever is typed in the command line, each word in a different line.
    for (int i = 0; i < argc; i++)
    {
        printf("%s\n", argv[i]);
    }
}

/*
ASCII art / cowsay
cowsat moo
cowsay -f duck quack
cowsat -f dragon RAWR
*/
