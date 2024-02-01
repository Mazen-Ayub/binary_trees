#include "binary_trees.h"

/**
 * binary_tree_postorder - a function that recursively proceeds through a binary
 * binary tree using post-order traversal
 * @tree: a root node of a tree to traverse
 * @func: a pointer to function to call for each node
 */

void binary_tree_postorder(const binary_tree_t *tree, void (*func)(int))
{
	if (!tree || !func)
		return;

	binary_tree_postorder(tree->left, func);
	binary_tree_postorder(tree->right, func);
	func(tree->n);
}
