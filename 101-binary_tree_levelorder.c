/* 20. Level-order traversal  */
#include "binary_trees.h"

/**
 * max_size_t - a function that finds larger of two size_t values
 * @a: the first value to compare
 * @b: the second value to compare
 * Return: a larger size_t value
 */

size_t max_size_t(size_t a, size_t b)
{
	return ((a > b) ? a : b);
}

/**
 * binary_tree_height - a function that measures the height of a binary tree
 * @tree: a root node from which to measure, starting at 0
 * Return: the levels from root || 0 if `tree` is NULL
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

/**
 * operate_on_level - a function that recurses to a given level of
 * a binary tree to apply `func`
 * @tree: a root of tree or subtree
 * @lvl: a depth in tree to recurse to
 * @func: the pointer to function to apply to all nodes at level "lvl"
 */

void operate_on_level(const binary_tree_t *tree, size_t lvl, void (*func)(int))
{
	if (!tree || !func)
		return;

	if (lvl == 0)
		func(tree->n);
	else
	{
		operate_on_level(tree->left, lvl - 1, func);
		operate_on_level(tree->right, lvl - 1, func);
	}
}

/**
 * binary_tree_levelorder - a function that applies function to each node
 * in a binary tree using level-order, making iterative calls to a helper
 * @tree: a root of tree or subtree
 * @func: the pointer to function to be applied
 */
void binary_tree_levelorder(const binary_tree_t *tree, void (*func)(int))
{
	size_t tree_h, i;

	if (!tree || !func)
		return;

	tree_h = binary_tree_height(tree);

	for (i = 0; i <= tree_h; i++)
		operate_on_level(tree, i, func);
}
