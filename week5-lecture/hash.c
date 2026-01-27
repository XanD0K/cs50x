/*
Hash function takes an infitine (big) domain/input, to a smaller well-defined finite range of values.
Ex: sorting 52 cards will take longer than sorting 4 piles of 13 cards.

Hash table -> An offspring of an array and a linked list together
It's a way to implement a dictionary (or a phone book)

typedef struct node
{
    char *name;
    char *number;
    struct node *next; // pointer to someone else whose name starts with the same letter
} node;

node *table[26];


#include <ctype.h>
unsigned int hash(const char *word)
{
    return toupper(word[0]) - 'A';
}

'unsigned' because there will be only positive numbers
'const' indicates that the function will not modify the string word. It’s a way to ensure that the function treats the input string as read-only, which can
help prevent accidental changes to the data. This is especially useful when you want to make sure that the function doesn’t alter the input it receives.
*/
