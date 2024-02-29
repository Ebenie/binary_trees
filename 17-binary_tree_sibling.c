#include "binary_trees.h"

/**
 * binary_tree_sibling - Finds the sibling of a node in a binary tree
 * @node: Pointer to the node to find the sibling
 *
 * Return: Pointer of sibling node, or NULL if node is NULL, parent is NULL,
 *         or node has no sibling
 */
binary_tree_t *binary_tree_sibling(binary_tree_t *node)
{
	if (node == NULL || node->parent == NULL)
		return (NULL);


	if (node->parent->left == node)
	{

		if (node->parent->right != NULL)
			return (node->parent->right);
		else
			return (NULL);
	}
	else
	{

		if (node->parent->left != NULL)
			return (node->parent->left);
		else
			return (NULL);
	}
}

