#include "binary_trees.h"

#ifndef MAX_INT
#define MAX_INT

/**
 * max_int - a function that finds larger of two int values
 * @a: a first value to compare
 * @b: a second value to compare
 * Return: the larger int value, or value of both if equal
 */

inline int max_int(int a, int b)
{
	return ((a > b) ? a : b);
}

#endif

/**
 * binary_tree_balance_height - a function that measures the height of a binary tree
 * @tree: a root node from which to measure
 * Return: the count of root and levels below, or 0 if `tree` is NULL
 */

int binary_tree_balance_height(const binary_tree_t *tree)
{
	if (!tree)
		return (0);

	if (!tree->left && !tree->right)
		return (1);

	return (1 + max_int(binary_tree_balance_height(tree->left),
						binary_tree_balance_height(tree->right)));
}

/**
 * binary_tree_balance - a function that measures the balance factor of a tree
 * @tree: a root node from which to measure
 * Return: the height of `tree` left , or 0 if `tree` is NULL
 */

int binary_tree_balance(const binary_tree_t *tree)
{
	int left_h, right_h;

	if (!tree)
		return (0);

	left_h = binary_tree_balance_height(tree->left);
	right_h = binary_tree_balance_height(tree->right);

	return (left_h - right_h);
}
