#include "binary_trees.h"

/**
 * binary_tree_is_leaf - a function that checks if binary tree node is leaf
 *  meaning it has no children
 * @node: a node to evaluate
 * Return: 1 if is leaf, 0 if not
 */

int binary_tree_is_leaf(const binary_tree_t *node)
{
	if (!node)
		return (0);
	if (node->left || node->right)
		return (0);
	else
		return (1);
}
