#include <stdio.h>

int main(void)
{
    int scores[1024];
    for (int i = 0; i < 1024; i++)
    {
        printf("%i\n", scores[i]);
    }

    /*
    int *x;
    int *y;
    x = malloc(sizeof(int));
    *x = 42;
    y = x; // 'y' now also poits to the the same memory allocated to 'x'
    y* = 13 //'x' and 'y' points to '13' now
    */
}

// Garbage values are remnantes of something else that has been in that location in memory before
// if you know there's gonna be lots of outputs, use './garbage | less' and 'q' to exit when done
