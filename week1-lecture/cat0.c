#include <cs50.h>
#include <stdio.h>

void meow(void); // Copy paste the prototype of the function (the first line of the function) you created so that it can be used in your main code

int main(void)
{
    /*
    int i = 3;
    while (i > 0)
    {
        printf("meow\n");
        i--;
    }
    */


    /*
    int i = 0;
    while (i < 3)
    {
        printf("meow\n");
        i++;
    }
    */


    /*
    while (true) → it will stay meowing forever. use ctrl+c to cancel the terminal
    {
        printf("meow\n");
    }
    */


    /*
    for (int i = 0; i < 3; i++)
    {
        prinf("meow\n");
    }
    */


    for (int i = 0; i < 3; i++)
    {
        meow();
    }
}

void meow(void) // void-void = no input, no output
{
    printf("meow\n");
}

// ctrl+j -> hide/show the terminal
