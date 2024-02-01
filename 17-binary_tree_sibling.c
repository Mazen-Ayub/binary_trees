#include "binary_trees.h"

/**
 * binary_tree_sibling - a function that finds 'sibling' to a node
 * @node: a node to check
 * Return: the pointer to node sharing same parent as node
 */

binary_tree_t *binary_tree_sibling(binary_tree_t *node)
{
	if (!node)
		return (NULL);

	if (node->parent)
	{
		if (node->parent->left == node)
			return (node->parent->right);
		if (node->parent->right == node)
			return (node->parent->left);
	}
	return (NULL);
}
