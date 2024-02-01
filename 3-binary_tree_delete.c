#include "binary_trees.h"
#include <stdlib.h>

/**
 * binary_tree_delete - a function that recursively traverses binary tree to
 * delete all nodes
 * @tree: a pointer to root a node of tree or subtree
 */

void binary_tree_delete(binary_tree_t *tree)
{
	if (!tree)
		return;

	binary_tree_delete(tree->left);
	binary_tree_delete(tree->right);

	free(tree);
}
