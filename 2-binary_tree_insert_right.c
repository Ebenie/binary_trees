#include "binary_trees.h"



binary_tree_t *binary_tree_insert_right(binary_tree_t *parent, int value)
{
    if (parent == NULL) {
        return NULL;
    }

    binary_tree_t *new_node = malloc(sizeof(binary_tree_t));
    if (new_node == NULL) {
        return NULL;
    }

    new_node->n = value;
    new_node->parent = parent;
    new_node->left = NULL;

    if (parent->right == NULL) {

        parent->right = new_node;
    } else {

        new_node->right = parent->right;
        parent->right = new_node;
        new_node->right->parent = new_node;
    }

    return new_node;
}

