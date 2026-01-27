#include <stdio.h> /*the # is a preprocessing the goes to the original file and copy the prototype of the function*/

int main(void) /*that's a prototype*/
{
    printf("hello, world\n");
}

/*instead of using 'make hello', we are using 'clang hello.c'
clang -o hello hello.c --> it says output(-o) 'hello' when you compile hello.c*/
