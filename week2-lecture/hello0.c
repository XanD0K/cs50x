#include <stdio.h> // The # is a preprocessing the goes to the original file and copy the prototype of the function

int main(void) // That's a prototype
{
    printf("hello, world\n");
}

/*
Instead of using 'make hello', we are using 'clang hello.c'
The default filename for 'clang' is 'a.out'
clang -o hello hello.c --> it says output(-o) 'hello' when you compile hello.c
*/
