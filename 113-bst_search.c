#include "binary_trees.h"

/**
 * bst_search - a fun that recursively searches for a value in a Binary Tree
 * @tree: a pointer to the root node of the BST to search
 * @value: an integer to search for
 * Return: the node containing value ||  NULL if not found
 */

bst_t *bst_search(const bst_t *tree, int value)
{
	if (!tree)
		return (NULL);

	if (value == tree->n)
		return ((bst_t *)tree);

	/* value not matching and no children left: value not in ordered tree */
	if (tree->left == NULL && tree->right == NULL)
		return (NULL);

	if (value < tree->n)
		return (bst_search(tree->left, value));

	return (bst_search(tree->right, value));
}
