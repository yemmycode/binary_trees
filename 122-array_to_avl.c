#include "binary_trees.h"

/**
 * array_to_avl - Converts an array into an AVL tree.
 *
 * @array: A pointer to the first element of the array to convert.
 * @size: The number of elements in the array.
 *
 * Return: A pointer to the root node of the created AVL tree, or NULL on failure.
 */
avl_t *array_to_avl(int *array, size_t size)
{
    avl_t *tree = NULL;
    size_t i;

    if (array == NULL)
        return NULL;

    for (i = 0; i < size; i++)
    {
        if (avl_insert(&tree, array[i]) == NULL)
            return NULL;
    }

    return tree;
}
