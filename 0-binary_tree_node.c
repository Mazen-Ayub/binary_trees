#include "binary_trees.h"
#include <stdlib.h>

/**
 * binary_tree_node - a function that creates a binary tree node of the struct
 * @parent: a pointer to a parent of a node created
 * @value: an integer that stored in the new node
 * Return: a pointer to new node
 */

binary_tree_t *binary_tree_node(binary_tree_t *parent, int value)
{
	binary_tree_t *new_node;

	new_node = malloc(sizeof(binary_tree_t));
	if (!new_node)
		return (NULL);

	new_node->n = value;
	new_node->parent = parent;
	new_node->left = NULL;
	new_node->right = NULL;

	return (new_node);
}
