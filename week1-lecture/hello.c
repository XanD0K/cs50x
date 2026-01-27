#include <cs50.h> // another head file that will allow me to access functions like "get_string"
#include <stdio.h> // .h -> header file. It will grant you access to libraries. Libraries are codes that someone else wrote. You access it by including a header file in the beginning of the code

int main(void)
{
    printf("hello, world\n");

    string answer = get_string("What's your name? ");
    printf("hello, %s\n", answer); // %s -> equals to "put another string here". The variable "answer" will get the place of the %s.
}

/* code hello.c -> start coding the language "c"
make hello -> will make a program named "hello" that will assume that there is somewhere in the folder a file named "hello.c". It'll trigger the compilation of the code.
./hello -> run the machine code.
./ -> refers specifically to the actual folder where the program is beaing built
don't use ./ for the comands "code" or "make" because those are installed in the system.
ls -> list the files in the "explorer" tab on the left
hello* -> the "*" symbol means that the program is executable
ctrl = l -> clear the terminal window
clear -> clear the terminal window
\n -> new line
\" -> actually print a quotation mark. If I want to print "hello, 'world'", I shall write prinf("hello, \"world\"\n");
Terminal commands: ls(list) / cd(change directory) / cp(copy) / mkdir(make directory) / mv(move - it can also be used to rename a file) / rm(remove) / rmdir(remove directory)
hello/ the slash on the right of "hello" means that it is a directory
.. -> parent directory
format codes -> %s(string) / %c(character) / %f( float) / %i(integer) / %li(long int) / %d(integer on base 10)
unsigned int -> you get rid of the negative values, but now you can store up to 4 bilions (2³²-1)
the modulus operator (%) gives you the remainder of a division
logical operators -> && (AND) / || (OR) / ! (NOT)
*/
