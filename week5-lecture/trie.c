/*
trie (short for retrieval)
It's a data structure for retriveing data
It's a tree of arrays
You use arrays for each of the letters in the input string
It has contant time O(1)

typedef struct node
{
    struct node *children[26];
    char *number;
} node;

TODO: lazy hash table, with hash map that adapts to user's input
*/
