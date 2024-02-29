#include "binary_trees.h"

/**
 * binary_trees_ancestor - Finds the lowest common ancestor of two nodes
 *
 * @first: A pointer to the first node
 * @second: A pointer to the second node
 *
 * Return: A pointer to the lowest common ancestor node, or NULL if not found
 */
binary_tree_t *binary_trees_ancestor(const binary_tree_t *first, const binary_tree_t *second)
{
	const binary_tree_t *ptr1 = first, *ptr2 = second;
	size_t depth1 = 0, depth2 = 0;

	if (first == NULL || second == NULL)
		return NULL;

	while (ptr1->parent != NULL)
	{
		ptr1 = ptr1->parent;
		depth1++;
	}

	while (ptr2->parent != NULL)
	{
		ptr2 = ptr2->parent;
		depth2++;
	}

	ptr1 = first;
	ptr2 = second;

	while (depth1 > depth2)
	{
		ptr1 = ptr1->parent;
		depth1--;
	}

	while (depth2 > depth1)
	{
		ptr2 = ptr2->parent;
		depth2--;
	}

	while (ptr1 != ptr2)
	{
		ptr1 = ptr1->parent;
		ptr2 = ptr2->parent;
	}

	return (binary_tree_t *)ptr1;
}

