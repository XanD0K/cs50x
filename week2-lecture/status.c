#include <cs50.h>
#include <stdio.h>

int main(int argc, string argv[])
{
    if (argc != 2)
    {
        printf("Missing command-line argument\n");
        return 1;
    }
    printf("hello, %s\n", argv[1]);
    return 0;
}

/*
The value that 'main' returns is called 'exit status', ehich indicates success of failure
0 means success
positive numbers (and sometimes negative numbers) mean failure

echo $? -> shows the number in 'return'. useful to know what's the error/output of the program
*/
