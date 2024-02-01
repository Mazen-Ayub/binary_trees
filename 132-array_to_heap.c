#include "binary_trees.h"

/**
 * array_to_heap - a function that builds a max binary heap tree
 * @array: a apointer to the first element of the array
 * @size: a number of element in the array
 * Return: the pointer to the root node of the "AVL" tree
 */

heap_t *array_to_heap(int *array, size_t size)
{
    heap_t *tree;
    size_t i;

    tree = NULL;

    for (i = 0; i < size; i++)
    {
        heap_insert(&tree, array[i]);
    }

    return (tree);
}
