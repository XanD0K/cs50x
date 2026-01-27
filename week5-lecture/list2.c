#include <cs50.h>
#include <stdio.h>
#include <stdlib.h>

/*
It can't be done this way, because in C, code is read top to bottom. There is no 'node' until the end of typedef.
typedef struct
{
    int number;
    node *next;
} node;
*/

//That's the solution
typedef struct node
{
    int number;
    struct node *next;
} node;

int main(void)
{
    node *list = NULL; // Pointer that will point to the beggining of the list. 'NULL' because there is no list yet.

    for (int i = 0; i < 3; i++)
    {
        node *n = malloc(sizeof(node)); // 'malloc' returns the address of a hunck of memory
        if (n == NULL)
        {
            /*
            What if the first memory succeed, the second succeed, but the third one fails?
            TODO: free any memory already malloc'd
            */
            return 1;
        }
        (*n).number = get_int("Number: "); // (*n) is the same as 'n->', ehich is more used

        /*
        It makes the lsit backwards, which has upsides because it has O(n) for search and O(1) for inserting
        n->next = list; // The next 'node.next' will points to whatever list is pointing to.
        list = n; // List was pointing to the first number. With that line, it will points to the next one. Problem: it's backwards!
        */

        // Now it is in direct order. It has O(n) for search and O(n) for inserting. You can create a variable that keeps track of the tail to solve that problem
        n->next = NULL;
        // If list is empty.
        if (list == NULL)
        {
            list = n;
        }
        // If list has numbers already
        else
        {
            for (node *ptr = list; ptr != NULL; ptr = ptr->next)
            {
                // If at end of list
                if (ptr->next == NULL)
                {
                    ptr->next = n;
                    break;
                }
            }
        }
    }

    //Time passes

    /*
    A way to print that with a while loop
    node *ptr = list; // Points to the same address that 'list' is poiting to
    while (ptr != NULL)
    {
        printf("%i\n", ptr->number);
        ptr = ptr->next;
    }
    */

    // Another way to print, bu with a for loop
    for (node *ptr = list; ptr != NULL; ptr = ptr->next)
    {
        printf("%i\n", ptr->number);
    }

    // Time passes

    node *ptr = list;
    while (ptr != NULL) // To free the elements of the list
    {
        /*
        free(ptr);
        ptr = ptr->next; // I can't use an element that has just been freed. That's why I created another poinnter (*next)
        */

        node *next = ptr->next;
        free(ptr);
        ptr = next;
    }

    return 0;
}
