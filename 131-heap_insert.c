#include "binary_trees.h"

/**
 * max_size_t - a function that finds larger of two size_t values
 * @a: the  first value to compare
 * @b: the  second value to compare
 * Return: the larger size_t value || value of both if equal
 */

size_t max_size_t(size_t a, size_t b)
{
	return ((a > b) ? a : b);
}

/**
 * binary_tree_height - a function that measures the height of a binary tree
 * @tree: a root node from which to measure, starting at 0
 * Return: the levels from root || 0 if "tree" is NULL
 */

size_t binary_tree_height(const binary_tree_t *tree)
{
	if (!tree)
		return (0);

	return (1 + max_size_t(binary_tree_height(tree->left),
						   binary_tree_height(tree->right)));
}

/**
 * binary_tree_nodes - a function that counts the total nodes in a binary tree
 * @tree: a root node from which to measure
 * Return: the total non-leaf nodes at or below "tree", or 0 if "tree" is NULL
 */

size_t binary_tree_nodes(const binary_tree_t *tree)
{
	if (!tree)
		return (0);

	return (1 + binary_tree_nodes(tree->left) +
			binary_tree_nodes(tree->right));
}

/**
 * binary_tree_is_perfect - a function that checks if a binary tree is perfect
 * meaning all nodes except for leaves have two children
 * @tree: a root node below which to check
 * Return: 1 if "tree"2 children, 0 if noty
 */

int binary_tree_is_perfect(const binary_tree_t *tree)
{
	int height, i, pow2 = 1;
	size_t total_nodes;

	if (!tree)
		return (0);

	height = binary_tree_height(tree);
	total_nodes = binary_tree_nodes(tree);

	for (i = 0; i < height; i++)
		pow2 *= 2;

	return (pow2 - 1 == (int)total_nodes);
}

/**
 * binary_tree_complete_insert - a function that recursively proceeds through
 * a `heap_t` binary tree to add a new leaf in level order
 * @tree: a root node of tree to traverse
 * @value: a value to store in the new node
 * Return: the pointer to the new node || NULL on failure
 */
heap_t *binary_tree_complete_insert(heap_t *tree, int value)
{
	heap_t *new = NULL;

	if (tree->left && tree->right)
	{
		if (!binary_tree_is_perfect(tree) &&
			binary_tree_is_perfect(tree->left))
			new = binary_tree_complete_insert(tree->right, value);
		else
			new = binary_tree_complete_insert(tree->left, value);
	}
	else
	{
		new = binary_tree_node(tree, value);
		if (!new)
			return (NULL);

		if (!(tree->left))
			tree->left = new;
		else
			tree->right = new;
	}

	return (new);
}

/**
 * heap_insert - a function that inserts a value into a max binary heap
 * @root: a double pointer to the root node of the Heap
 * @value: a value to store in the node to be inserted
 * Return: the pointer to the inserted node || NULL on failure
 */
heap_t *heap_insert(heap_t **root, int value)
{
	heap_t *new = NULL, *temp = NULL;
	int swap;

	if (!(*root))
	{
		new = binary_tree_node(NULL, value);
		if (!new)
			return (NULL);
		*root = new;
		return (new);
	}

	new = binary_tree_complete_insert(*root, value);
	if (!new)
		return (NULL);

	temp = new;
	while (temp && temp->parent && temp->n > temp->parent->n)
	{
		swap = temp->n;
		temp->n = temp->parent->n;
		temp->parent->n = swap;
		temp = temp->parent;
	}

	return (temp);
}
