#include <stdio.h>
#include "binary_trees.h"

/**
 * array_to_heap - Converts an array into a Max Binary Heap tree
 * @array: Pointer to the array containing the elements to insert into the heap
 * @size: Number of elements in the array
 * Return: Pointer to the root node of the created Max Binary Heap
 */
heap_t *array_to_heap(int *array, size_t size)
{
	heap_t *tree = NULL;
	size_t i;

	if (array == NULL || size == 0)
		return (NULL);

	heap_insert(&tree, array[0]);

	for (i = 1; i < size; i++)
		heap_insert(&tree, array[i]);

	return (tree);
}
