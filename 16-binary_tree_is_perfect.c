#include "binary_trees.h"

/**
 * binary_tree_is_perfect - a function that checks if a binary tree is perfect
 * meaning all nodes except for that have two children
 * @tree: a root node below which to check
 * Return: 1 if `tree` and all nodes below it each have 2 children
 */

int binary_tree_is_perfect(const binary_tree_t *tree)
{
	if (!tree)
		return (0);

	if (tree->right && tree->left)
	{
		if ((!tree->left->left && !tree->left->right) &&
			(!tree->right->left && !tree->right->right))
			return (1);

		return (binary_tree_is_perfect(tree->left) &&
				binary_tree_is_perfect(tree->right));
	}
	else if (!(tree->parent))
		return (1);

	return (0);
}
