#include "binary_trees.h"
#include <stdlib.h>

/**
 * binary_tree_insert_right - a funtion that insert` node as the right-child
 * of another node
 * @parent: a pointer of a node into which right-child is inserted
 * @value: an integer that stored in new a node
 * Return: a pointer to new node, or NULL
 */

binary_tree_t *binary_tree_insert_right(binary_tree_t *parent, int value)
{
	binary_tree_t *new_node;

	if (!parent)
		return (NULL);

	new_node = malloc(sizeof(binary_tree_t));
	if (!new_node)
		return (NULL);

	new_node->n = value;
	new_node->parent = parent;
	if (parent->right)
	{
		new_node->right = parent->right;
		parent->right->parent = new_node;
	}
	else
		new_node->right = NULL;
	new_node->left = NULL;
	parent->right = new_node;

	return (new_node);
}
