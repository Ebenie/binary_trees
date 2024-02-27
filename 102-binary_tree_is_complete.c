#include "binary_trees.h"


/**
 * binary_tree_is_complete - Checks if a binary tree is complete
 * @tree: A pointer to the root node of the tree to check
 *
 * Return: 1 if the tree is complete, 0 otherwise
 */
int binary_tree_is_complete(const binary_tree_t *tree)
{
    if (tree == NULL)
        return 0;


    binary_tree_t **queue = malloc(sizeof(binary_tree_t *) * 10000);
    if (queue == NULL)
        return 0;

    int front = 0, rear = 0;
    int flag = 0;

    queue[rear++] = (binary_tree_t *)tree;

    while (front < rear)
    {
        const binary_tree_t *current = queue[front++];


        if (flag && (current->left != NULL || current->right != NULL))
        {
            free(queue);
            return 0;
        }


        if (current->left == NULL)
            flag = 1;

        else if (flag)
        {
            free(queue);
            return 0;
        }

        if (current->left != NULL)
            queue[rear++] = current->left;


        if (current->right == NULL)
            flag = 1;

        else if (flag)
        {
            free(queue);
            return 0;
        }

        if (current->right != NULL)
            queue[rear++] = current->right;
    }

    free(queue);
    return 1;
}

