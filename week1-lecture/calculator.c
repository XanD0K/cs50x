#include <cs50.h>
#include <stdio.h>

int main(void)
{
    int x = get_int("x: "); //as we are using integers, there will be no decimals. It's called truncation. You can chance the integer to a float.
    int y = get_int("y: ");

    printf("%i\n", x + y);
    printf("%.5f\n", (float) x / y); //the float inside parenthesys says the program to treat the result x+y as a float.
    // %.5f -> %f will get the vallue and put here as a float. The .5 means that it will show the 5 first decimal digits.
    // floatin-point imprecision. If you say the computer to show the first 50 decimal numbers, it just won't have enough bits to show them precisely.
    // You can use a double to try to prevent it, but there will be a time when it will also happens with doubles.


    long dollars = 1; //int stores up to 32 bits. long stores up to 64 bits, which avoid, or at least postpone overflow.
    while (true)
    {
        char c = get_char("Here's $%li. Double it and give it to the next person?", dollars);
        if (c == 'y')
        {
            dollars *= 2;
        }
        else
        {
            break;
        }
    }
    printf("Here's $%li.\n", dollars);
}
