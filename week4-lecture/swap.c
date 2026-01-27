#include <stdio.h>

void swap(int *a, int *b);

int main(void)
{
    int x = 1;
    int y = 2;

    printf("x is %i, y is %i\n", x, y);
    swap(&x, &y);
    printf("x is %i, y is %i\n", x, y);
}

/*
void swap (int a, int b) // It does swap 'a' and 'b', but it doesn't affect the values of 'x' and 'y'
{
    int temp = a;
    a = b;
    b = temp;
}
*/

void swap (int *a, int *b) // Now, 'a' and 'b' are the adresses of another int ('x' and 'y' respectively)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}
