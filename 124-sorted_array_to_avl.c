#include "binary_trees.h"

/**
 * sortedArrToAVL - a function that recursive helper to sorted_array_to_avl
 * @array: a sorted array of integers
 * @lo_idx: a leftmost index accessed in array
 * @hi_idx: a rightmost index accessed in array
 * @parent: a parent node from previous frame of recursion, or NULL for root
 * Return: the pointer to new subtree's root node || NULL on failure
 */

avl_t *sortedArrToAVL(int *array, int lo_idx, int hi_idx, avl_t *parent)
{
	avl_t *root = NULL;
	int mid_idx;

	if (!array)
		return (NULL);

	if (lo_idx > hi_idx)
		return (NULL);

	mid_idx = (lo_idx + hi_idx) / 2;
	root = binary_tree_node(parent, array[mid_idx]);
	if (!root)
		return (NULL);

	root->left = sortedArrToAVL(array, lo_idx, mid_idx - 1, root);

	root->right = sortedArrToAVL(array, mid_idx + 1, hi_idx, root);

	return (root);
}

/**
 * sorted_array_to_avl - a function that creates an AVL tree from an array
 * of integers sorted in ascending order
 * @array: the sorted array of integers
 * @size: the amount of members in array
 * Return: the pointer to new tree's root node || NULL on failure or empty array
 */
avl_t *sorted_array_to_avl(int *array, size_t size)
{
	if (!array || size == 0)
		return (NULL);

	return (sortedArrToAVL(array, 0, (int)size - 1, NULL));
}
