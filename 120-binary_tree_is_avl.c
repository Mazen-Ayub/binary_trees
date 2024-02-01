#include "binary_trees.h"
#include <limits.h>

#ifndef MAX_INT
#define MAX_INT

/**
 * max_int - a function that finds larger of two int values
 * @a: the first value to compare
 * @b: the second value to compare
 * Return: teh larger int value ||value of both if equal
 */

inline int max_int(int a, int b)
{
	return ((a > b) ? a : b);
}

#endif

/**
 * BST_is_AVL_balanced -a fun that measures the balance factor of a binary tree
 * @tree: the root node from which to measure
 * Return: the height of "tree" left || 0 if "tree" is NULL
 */

avl_data_t BST_is_AVL_balanced(const binary_tree_t *tree)
{
	avl_data_t left, right, node;
	int bal_factor;

	if (!tree)
	{
		node.height = -1;
		node.is_AVL = 1;
		return (node);
	}

	left = BST_is_AVL_balanced(tree->left);
	right = BST_is_AVL_balanced(tree->right);

	node.height = 1 + max_int(left.height, right.height);

	bal_factor = right.height - left.height;
	if (bal_factor < -1 || bal_factor > 1)
		node.is_AVL = 0;
	else
		node.is_AVL = left.is_AVL && right.is_AVL;

	return (node);
}

/**
 * tree_is_BST - a function that recursive helper to binary_tree_is_bst
 * @tree: a tree to check for BST
 * @prev: the pointer to int
 * Return: 1 valid if "tree" is valid BST, or 0 if not or "tree" is NULL
 */

int tree_is_BST(const binary_tree_t *tree, int *prev)
{
	if (tree)
	{
		if (!tree_is_BST(tree->left, prev))
			return (0);

		if (tree->n <= *prev)
			return (0);

		*prev = tree->n;

		return (tree_is_BST(tree->right, prev));
	}
	return (1);
}

/**
 * binary_tree_is_avl - uses recursive helper to test first if binary tree
 * @tree: a tree to check for AVL
 * Return: 1 valid if "tree" is valid AVL, or 0 if not or "tree" is NULL
 */

int binary_tree_is_avl(const binary_tree_t *tree)
{
	int prev = INT_MIN;

	if (!tree)
		return (0);

	if (!tree_is_BST(tree, &prev))
		return (0);

	return (BST_is_AVL_balanced(tree).is_AVL);
}
