#include "binary_trees.h"

/**
 * binary_tree_uncle - a function that finds 'uncle' to a node
 * @node: a node to check
 * Return: the pointer to sibling node of parent to node
 */

binary_tree_t *binary_tree_uncle(binary_tree_t *node)
{
	if (!node)
		return (NULL);

	if (node->parent && node->parent->parent)
	{
		if (node->parent->parent->left == node->parent)
			return (node->parent->parent->right);
		if (node->parent->parent->right == node->parent)
			return (node->parent->parent->left);
	}
	return (NULL);
}
