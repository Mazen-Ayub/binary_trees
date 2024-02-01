#include "binary_trees.h"
#include <stdlib.h>

/**
 * binary_tree_insert_left - a function that insert node as left-child
 * of another node
 * @parent: a pointer of a node into which left-child is inserted
 * @value: an integer that stored in a new node
 * Return: a pointer to a new node, or NULL
 */

binary_tree_t *binary_tree_insert_left(binary_tree_t *parent, int value)
{
	binary_tree_t *new_node;

	if (!parent)
		return (NULL);

	new_node = malloc(sizeof(binary_tree_t));
	if (!new_node)
		return (NULL);

	new_node->n = value;
	new_node->parent = parent;
	if (parent->left)
	{
		new_node->left = parent->left;
		parent->left->parent = new_node;
	}
	else
		new_node->left = NULL;
	new_node->right = NULL;
	parent->left = new_node;

	return (new_node);
}
