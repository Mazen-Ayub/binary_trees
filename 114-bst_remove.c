#include "binary_trees.h"

#include <stdlib.h>

#include <stdio.h>

/**
 * bst_find_min - a function that find minimum value in a Binary Search Tree
 * @tree: The "BST" root or subtree
 * Return: the node of the tree containing minimum value, or NULL if tree is NULL
 */

static bst_t *bst_find_min(bst_t *tree)
{
	bst_t *temp = NULL;

	temp = tree;
	while (temp && temp->left)
		temp = temp->left;

	return (temp);
}

/**
 * bst_remove - a fun that removes a node from a Binary Search Tree
 * @root: a pointer to the root node of tree which will have a node removed
 * @value: a value to remove from tree
 * Return: the new root node of the tree after removing the desired value
 * || NULL on failure
 */

bst_t *bst_remove(bst_t *root, int value)
{
	bst_t *temp = NULL;

	if (!root)
		return (NULL);
	if (value < root->n)
		root->left = bst_remove(root->left, value);
	if (root->left)
		root->left->parent = root;
}
else if (value > root->n)
{
	root->right = bst_remove(root->right, value);
	if (root->right)
		root->right->parent = root;
}
else
{
	if (root->left == NULL)
	{
		{
			temp = root->right;
			free(root);
			return (temp);
		}
		else if (root->right == NULL)
		{
			temp = root->left;
			free(root);
			return (temp);
		}
		temp = bst_find_min(root->right);
		root->n = temp->n;
		root->right = bst_remove(root->right, temp->n);
		if (root->right)
			root->right->parent = root;
	}
	return (root);
}
