#include "binary_trees.h"


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

