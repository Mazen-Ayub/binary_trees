#include "binary_trees.h"

/**
 * binary_tree_is_full - a function that checks if a binary tree is full
 * meaning all nodes have either 0 or 2 children
 * @tree: a root node below which to check
 * Return: 1 if `tree` and all nodes below it each have 0 or 2 children
 */

int binary_tree_is_full(const binary_tree_t *tree)
{
	if (!tree)
		return (0);

	if (tree->right && tree->left)
		return (binary_tree_is_full(tree->left) &&
				binary_tree_is_full(tree->right));
	else if (tree->right || tree->left)
		return (0);
	else
		return (1);
}
