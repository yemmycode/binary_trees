#include "binary_trees.h"

/**
 * binary_tree_is_leaf - Determines if a node is a leaf in a binary tree.
 * @node: Pointer to the node to check.
 *
 * Return: 1 if the node is a leaf, otherwise 0.
 */
int binary_tree_is_leaf(const binary_tree_t *node)
{
	if (!node || node->left || node->right)
		return (0);

	return (1);
}
