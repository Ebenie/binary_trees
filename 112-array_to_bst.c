#include "binary_trees.h"
/**
 * bst_insert - Inserts a value in a Binary Search Tree
 * @tree: A double pointer to the root node of the BST to insert the value
 * @value: The value to store in the node to be inserted
 *
 * Return: A pointer to the created node, or NULL on failure
 */
bst_t *bst_insert(bst_t **tree, int value)
{
    if (tree == NULL)
        return NULL;

    if (*tree == NULL)
    {
        *tree = binary_tree_node(NULL, value);
        return *tree;
    }

    if (value < (*tree)->n)
    {
        if ((*tree)->left == NULL)
        {
            (*tree)->left = binary_tree_node(*tree, value);
            return (*tree)->left;
        }
        else
        {
            return bst_insert(&((*tree)->left), value);
        }
    }
    else if (value > (*tree)->n)
    {
        if ((*tree)->right == NULL)
        {
            (*tree)->right = binary_tree_node(*tree, value);
            return (*tree)->right;
        }
        else
        {
            return bst_insert(&((*tree)->right), value);
        }
    }

    return NULL;
}

/**
 * array_to_bst - Builds a Binary Search Tree from an array
 * @array: A pointer to the first element of the array to be converted
 * @size: The number of elements in the array
 *
 * Return: A pointer to the root node of the created BST, or NULL on failure
 */
bst_t *array_to_bst(int *array, size_t size)
{
    if (array == NULL || size == 0)
        return NULL;

    bst_t *root = NULL;


    size_t mid = size / 2;
    bst_insert(&root, array[mid]);


    if (mid > 0)
        array_to_bst(array, mid);


    if (mid < size - 1)
        array_to_bst(array + mid + 1, size - mid - 1);

    return root;
}

