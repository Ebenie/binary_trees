#include "binary_trees.h"

/**
 * max - Returns the maximum of two integers
 * @a: First integer
 * @b: Second integer
 *
 * Return: The maximum of a and b
 */
int max(int a, int b)
{
    return (a > b ? a : b);
}

/**
 * height - Calculates the height of a binary tree
 * @tree: A pointer to the root node of the tree
 *
 * Return: The height of the tree
 */
int height(const binary_tree_t *tree)
{
    if (tree == NULL)
        return -1;

    return 1 + max(height(tree->left), height(tree->right));
}

/**
 * binary_tree_is_bst - Checks if a binary tree is a valid Binary Search Tree
 * @tree: A pointer to the root node of the tree to check
 * @min: The minimum allowed value for nodes in the subtree
 * @max: The maximum allowed value for nodes in the subtree
 *
 * Return: 1 if tree is a valid BST, 0 otherwise
 */
int binary_tree_is_bst(const binary_tree_t *tree, int min, int max)
{
    if (tree == NULL)
        return 1;

    if (tree->n <= min || tree->n >= max)
        return 0;

    return binary_tree_is_bst(tree->left, min, tree->n) &&
           binary_tree_is_bst(tree->right, tree->n, max);
}

/**
 * binary_tree_is_avl - Checks if a binary tree is a valid AVL Tree
 * @tree: A pointer to the root node of the tree to check
 *
 * Return: 1 if tree is a valid AVL Tree, 0 otherwise
 */
int binary_tree_is_avl(const binary_tree_t *tree)
{
    if (tree == NULL)
        return 0;

    int left_height = height(tree->left);
    int right_height = height(tree->right);

    if (abs(left_height - right_height) > 1)
        return 0;

    if (!binary_tree_is_bst(tree, INT_MIN, INT_MAX))
        return 0;

    if (!binary_tree_is_avl(tree->left) || !binary_tree_is_avl(tree->right))
        return 0;

    return 1;
}

