#include "binary_trees.h"

/**
 * min_value_node - Finds the node with the minimum value in a BST
 * @node: A pointer to the root node of the subtree
 *
 * Return: A pointer to the node with the minimum value
 */
bst_t *min_value_node(bst_t *node)
{
    bst_t *current = node;


    while (current && current->left != NULL)
        current = current->left;

    return current;
}

/**
 * bst_remove - Removes a node from a Binary Search Tree
 * @root: A pointer to the root node of the tree
 * @value: The value to remove from the tree
 *
 * Return: A pointer to the new root node of the tree after removal
 */
bst_t *bst_remove(bst_t *root, int value)
{
    if (root == NULL)
        return NULL;


    if (value < root->n)
        root->left = bst_remove(root->left, value);


    else if (value > root->n)
        root->right = bst_remove(root->right, value);


    else
    {

        if (root->left == NULL)
        {
            bst_t *temp = root->right;
            free(root);
            return temp;
        }
        else if (root->right == NULL)
        {
            bst_t *temp = root->left;
            free(root);
            return temp;
        }


        bst_t *temp = min_value_node(root->right);


        root->n = temp->n;


        root->right = bst_remove(root->right, temp->n);
    }

    return root;
}


