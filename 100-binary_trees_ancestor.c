/* task 19. Lowest common ancestor */
#include "binary_trees.h"

/**
 * bt_find_lca - a function that recurses downstream into a binary tree
 * to find lowest common ancestor "LCA"
 * @root: a node to recursively check below
 * @first: the first of two descendants
 * @second: the second descendant
 * Return: "LCA" if found, NULL if not
 */

binary_tree_t *bt_find_lca(binary_tree_t *root, const binary_tree_t *first,
						   const binary_tree_t *second)
{
	binary_tree_t *left_search, *right_search;

	if (!root)
		return (NULL);

	if (root == first || root == second)
		return (root);

	left_search = bt_find_lca(root->left, first, second);
	right_search = bt_find_lca(root->right, first, second);

	if (left_search && right_search)
		return (root);

	if (left_search != NULL)
		return (left_search);
	else
		return (right_search);
}

/**
 * binary_trees_ancestor - a function that finds the lowest common
 * ancestor of two nodes
 * @first: the first of two descendants
 * @second: the second descendant
 * Return: a pointer to node that is lowest common ancestor
 */

binary_tree_t *binary_trees_ancestor(const binary_tree_t *first,
									 const binary_tree_t *second)
{
	binary_tree_t *root = (binary_tree_t *)first;
	binary_tree_t *root2 = (binary_tree_t *)second;

	if (!first || !second)
		return (NULL);

	while (root->parent)
		root = root->parent;

	while (root2->parent)
		root2 = root2->parent;
	if (root != root2)
		return (NULL);

	return (bt_find_lca(root, first, second));
}
