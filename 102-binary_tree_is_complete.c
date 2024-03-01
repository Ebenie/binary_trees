#include "binary_trees.h"

int is_complete(const binary_tree_t *tree, int index, int nodes);
int binary_tree_is_complete(const binary_tree_t *tree);
size_t binary_tree_size(const binary_tree_t *tree);
/**
 * binary_tree_is_complete - Checks if a binary tree is complete
 * @tree: A pointer to the root node of the tree to check
 *
 * Return: 1 if the tree is complete, 0 otherwise
 */
int binary_tree_is_complete(const binary_tree_t *tree)
{
    int nodes = 0, index = 0;

    if (tree == NULL)
        return (0);


    nodes = binary_tree_size(tree);

    return (is_complete(tree, index, nodes));
}

/**
 * binary_tree_size - Measures the size of a binary tree
 * @tree: A pointer to the root node of the tree to measure
 *
 * Return: The size of the tree
 */
size_t binary_tree_size(const binary_tree_t *tree)
{
    if (tree == NULL)
        return (0);

    return (1 + binary_tree_size(tree->left) + binary_tree_size(tree->right));
}

/**
 * is_complete - Recursive helper function to check if a binary tree is complete
 * @tree: A pointer to the current node in the tree
 * @index: The index of the current node
 * @nodes: The total number of nodes in the tree
 *
 * Return: 1 if the tree is complete, 0 otherwise
 */
int is_complete(const binary_tree_t *tree, int index, int nodes)
{

    if (tree == NULL)
        return (1);


    if (index >= nodes)
        return (0);


    return (is_complete(tree->left, 2 * index + 1, nodes) &&
            is_complete(tree->right, 2 * index + 2, nodes));
}

