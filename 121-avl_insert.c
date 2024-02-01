#include "binary_trees.h"

/**
 * bst_insert_recursion - a function that recursively traverses a Binary Search
 * Tree to insert a new value
 * @tree: a binary tree node
 * @value: an integer to insert in new node
 * Return: the pointer to new node || NULL on failure
 */

bst_t *bst_insert_recursion(bst_t *tree, int value)
{
	bst_t *new = NULL;

	if (tree->n > value)
	{
		if (tree->left == NULL)
		{
			new = binary_tree_node(tree, value);
			tree->left = new;
			return (new);
		}

		return (bst_insert_recursion(tree->left, value));
	}

	if (tree->n < value)
	{
		if (tree->right == NULL)
		{
			new = binary_tree_node(tree, value);
			tree->right = new;
			return (new);
		}

		return (bst_insert_recursion(tree->right, value));
	}

	return (NULL);
}

/**
 * bst_insert - a function that inserts a value in a Binary Search Tree
 * @tree: a binary tree node passed by reference
 * @value: an integer to insert in new node
 * Return: the pointer to new node || NULL on failure
 */

bst_t *bst_insert(bst_t **tree, int value)
{
	bst_t *new = NULL;

	if (!tree || !(*tree))
	{
		new = binary_tree_node(NULL, value);
		*tree = new;
		return (new);
	}

	return (bst_insert_recursion(*tree, value));
}
