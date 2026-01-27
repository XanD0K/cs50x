// Implements a dictionary's functionality
/*
Fastest way is a trie, but I don' like wasting memory with unused data
Will try to implement a flexible trie, that only allocate memory when needed (if needed)
It will have less memory usage than trie, without forfeit its speed time
*/

#include <ctype.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "dictionary.h"

// TODO: Choose number of buckets in hash table
// Set it to 27 to include the apostrophe character (')
const unsigned int ALPHABET = 27;

// 'has_letter' can now store 2 variable types
typedef struct
{
    bool exist;
    int letter_position;
} letter_info;

// Represents a node in a hash table
// Adapted to a flexible trie
typedef struct node
{
    bool is_word;                     // Will toggle at the end of a word
    letter_info has_letter[ALPHABET]; // Keep track of which letter exist in that "level".
    struct node **children;           // Dynamic array that will grow as needed.
    int child_count;                  // Used to resize the array (w/ malloc and realloc)
} node;

// Creating the root (starting point)
node *root = NULL;
// Count how many words
unsigned int word_count = 0;

// Prototype
void free_node(node *n);

// Loads dictionary into memory, returning true if successful, else false
bool load(const char *dictionary)
{
    // TODO
    word_count = 0;
    FILE *file = fopen(dictionary, "r");
    if (file == NULL)
    {
        return false;
    }

    // Initializing root
    root = malloc(sizeof(node));
    if (root == NULL)
    {
        unload();
        fclose(file);
        return false;
    }

    // Setting root's initial values
    root->is_word = false;
    for (int i = 0; i < ALPHABET; i++)
    {
        root->has_letter[i].exist = false;
        root->has_letter[i].letter_position = -1;
    }
    root->children = NULL;
    root->child_count = 0;

    char word[LENGTH + 1]; // Word's length. Same as in 'speller.c'
    while (fscanf(file, "%s", word) != EOF)
    {
        node *current = root;                 // Kepp track of actual position
        for (int i = 0; word[i] != '\0'; i++) // 'i < strlen(word)' also works
        {
            int letter_index;
            if (word[i] == '\'') // Dictionary also has the apostrophe character (')
            {
                letter_index = 26;
            }
            else
            {
                letter_index = word[i] - 'a';
            }

            // Guaranteeing that letter_index is inside boundaries
            if (letter_index < 0 || letter_index >= ALPHABET)
            {
                continue;
            }

            // Letter doesn't exist
            if (current->has_letter[letter_index].exist == false)
            {
                node *new_letter = malloc(sizeof(node));
                if (new_letter == NULL)
                {
                    unload();
                    fclose(file);
                    return false;
                }

                // Setting new_letter's initial values
                new_letter->is_word = false;
                for (int j = 0; j < ALPHABET; j++)
                {
                    new_letter->has_letter[j].exist = false;
                    new_letter->has_letter[j].letter_position = -1;
                }
                new_letter->children = NULL;
                new_letter->child_count = 0;

                // Allocating memory and changing pointers
                current->child_count++;
                // Temporary to change pointers, as we did in class
                node **temporary = realloc(current->children, current->child_count * sizeof(node *));
                if (temporary == NULL)
                {
                    unload();
                    fclose(file);
                    return false;
                }
                current->children = temporary;
                current->has_letter[letter_index].letter_position = current->child_count - 1;
                current->children[current->has_letter[letter_index].letter_position] = new_letter;
                current->has_letter[letter_index].exist = true;
                current = new_letter;
            }
            // Letter already exists (need to change pointer position)
            else
            {
                current = current->children[current->has_letter[letter_index].letter_position];
            }
        }
        // After word is finished
        current->is_word = true;
        // Used in 'size' function
        word_count++;
    }
    fclose(file);
    return true;
}

// Returns true if word is in dictionary, else false
bool check(const char *word)
{
    // TODO
    // Kepping track of position
    node *pointer = root;
    // If 'load' fails
    if (pointer == NULL)
    {
        return false;
    }

    // Iterating through words
    for (int i = 0; word[i] != '\0'; i++)
    {
        // Calculating index for each letter from input's text
        int letter_index;
        if (word[i] == '\'')
        {
            letter_index = 26;
        }
        else
        {
            letter_index = tolower(word[i]) - 'a';
        }

        // Another safety check, just like in 'load' function
        if (letter_index < 0 || letter_index >= ALPHABET)
        {
            return false;
        }

        // Comparing index from input's text with stored paths from dictionary.
        if (pointer->has_letter[letter_index].exist)
        {
            // If true, goes to the next character
            pointer = pointer->children[pointer->has_letter[letter_index].letter_position];
        }
        else
        {
            // If false, that is not a valid word
            return false;
        }
    }

    // After all letters, check if it's a word
    if (pointer->is_word)
    {
        return true;
    }
    return false;
}

// Returns number of words in dictionary if loaded, else 0 if not yet loaded
unsigned int size(void)
{
    // TODO
    return word_count;
}

// Unloads dictionary from memory, returning true if successful, else false
bool unload(void)
{
    // TODO
    free_node(root);
    root = NULL;
    return true;
}

void free_node(node *n)
{
    if (n == NULL)
    {
        return;
    }

    // Will free every child node
    for (int i = 0; i < n->child_count; i++)
    {
        free_node(n->children[i]);
    }
    free(n->children);
    free(n);
}

// Hashes word to a number
// Won't needed in a trie code
unsigned int hash(const char *word)
{
    // TODO: Improve this hash function
    return toupper(word[0]) - 'A';
}
