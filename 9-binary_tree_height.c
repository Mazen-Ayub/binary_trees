#include "binary_trees.h"

/**
 * max_size_t - a function that finds larger of two size_t values
 * @a: a first value to compare
 * @b: a second value to compare
 * Return: the larger size_t value, or value of both if ==
 */

size_t max_size_t(size_t a, size_t b)
{
	return ((a > b) ? a : b);
}

/**
 * binary_tree_height - a function that measures the height of a binary tree
 * @tree: a root node from which to measure
 * Return: a levels from root, or 0 if `tree` is NULL
 */

size_t binary_tree_height(const binary_tree_t *tree)
{
	if (!tree)
		return (0);

	if (!tree->left && !tree->right)
		return (0);

	return (1 + max_size_t(binary_tree_height(tree->left),
						   binary_tree_height(tree->right)));
}
