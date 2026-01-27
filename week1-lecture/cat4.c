#include <cs50.h>
#include <stdio.h>

int get_positive_int(void); //has output, but no input
void meow(int n); //has input, but no output

int main(void)
{
    int times = get_positive_int();
    meow(times);
}

int get_positive_int(void)
{
    int n;
    do
    {
        n = get_int("Number: ");
    }
    while (n < 1);
    return n; //it needs to return the value so that you can use it on other functions. otherwise
}

void meow(int n)
{
    for (int i = 0; i < n; i++)
    {
        printf("meow\n");
    }
}
