#include <stdio.h>
#include <stdlib.h>

int main(void)
{
    int *list = malloc(3 * sizeof(int)); // I coded that in a pset2 problem
    if (list == NULL)
    {
        return 1;
    }

    list[0] = 1;
    list[1] = 2;
    list[2] = 3;

    // Time passes. Now I need more space

    /*
    int *tmp = malloc(4 * sizeof(int));
    */

    // Instead of creating a new array with malloc, we can use 'realloc' to realocate memory to the original array
    int *tmp = realloc(list, 4 * sizeof(int));
    // I could use 'list = realloc(list, 4 * sizeof(int))' directly, But using a temporary array is safer!

    if (tmp == NULL)
    {
        free(list);
        return 1; // Can't just return without cleaning the memory you've asked for the first list
    }

    /*
    With realloc, this for loop isn't needed
    for (int i = 0; i < 3; i++)
    {
        tmp[i] = list[i];
    }
    */

    tmp[3] = 4;

    // free(list); -> Using realloc, I don't need to free the original list

    list = tmp; // Rename the variable 'tmp' as 'list'

    for (int i = 0; i < 4; i++)
    {
        printf("%i\n", list[i]);
    }

    free(list);
    return 0;
}
