#include "binary_trees.h"

/**
 * binary_tree_depth - a function that measures the depth of a node in a tree
 * @tree: a node from which to measure backwards
 * Return: the levels from root || 0 if `tree` == NULL
 */

size_t binary_tree_depth(const binary_tree_t *tree)
{
	size_t depth;

	if (!tree)
		return (0);

	for (depth = 0; tree->parent; depth++)
		tree = tree->parent;

	return (depth);
}
