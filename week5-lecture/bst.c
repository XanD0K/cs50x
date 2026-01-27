// Tree is already built. Here's how to search that three

bool search(node *tree, int number)
{
    // Number is not in the tree
    if (tree == NULL)
    {
        return false;
    }
    else if (number < tree->number)
    {
        return search(tree->left, number);
    }
    else if (number > tree->number)
    {
        return search(tree->right, number);
    }
    else // = else if (number == tree->number)
    return true;
}

/*
If the users input 1, then 2, then 3, then 4, and so on, it becomes a liked list.
TODO: Optimize the code so that it stays balances and has a O(n) searching/insertion/deletion time.
*/

