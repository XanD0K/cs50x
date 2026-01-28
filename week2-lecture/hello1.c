#include <cs50.h>
#include <stdio.h>

int main(void)
{
    string name = get_string("What's your name? ");
    printf("hello, %s\n", name);
}

/*
By using clang in here, it will trigger an erro:
"linker command failed with exit code 1 (use -v to see invocation)"
It happens because clang don't know where to find the cs50 version of 'get_string'
We have to use this command: clang hello2.c -lcs50
lcs50 → tells the compiler to link in the cs50 library so that it knows

clang -o hello hello.c
-o hello → says to output(-o) 'hello' when you compile hello.c
*/
