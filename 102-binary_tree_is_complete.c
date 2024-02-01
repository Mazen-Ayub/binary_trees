#include "binary_trees.h"

/**
 * binary_tree_size - a function that measures the size of a binary tree
 * @tree: a root node from which to measure
 * Return: the total of "tree" and all nodes below it || 0 if "tree" is NULL
 */

size_t binary_tree_size(const binary_tree_t *tree)
{
	if (!tree)
		return (0);

	if (!tree->left && !tree->right)
		return (1);

	return (1 + binary_tree_size(tree->left) +
			binary_tree_size(tree->right));
}

/**
 * check_bt_complete - a function that recursively checks if binary tree
 * is complete at each level except 2nd from last all have 2 children
 * @tree: a root node from which to measure
 * @i: an iterator to mimic an array index while traversing tree
 * @size: a total number of nodes in tree
 * Return: 1 if `tree` is complete, 0 if not or `tree` is NULL
 */

int check_bt_complete(const binary_tree_t *tree, size_t i, size_t size)
{
	if (!tree)
		return (1);

	if ((tree->left && (2 * i) + 1 >= size) ||
		!check_bt_complete(tree->left, (2 * i) + 1, size))
		return (0);

	if ((tree->right && (2 * i) + 2 >= size) ||
		!check_bt_complete(tree->right, (2 * i) + 2, size))
		return (0);

	return (1);
}

/**
 * binary_tree_is_complete - a function that calls recursive helper to see
 * if binary tree is complete
 * @tree: a root of tree or subtree
 * Return: 1 if `tree` is complete, 0 if not or `tree` is NULL
 */

int binary_tree_is_complete(const binary_tree_t *tree)
{
	if (!tree)
		return (0);

	return (check_bt_complete(tree, 0, binary_tree_size(tree)));
}
