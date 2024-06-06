#include "binary_trees.h"

/**
 * binary_tree_balance - Determines the balance factor of a binary tree.
 * @tree: A pointer pointing to the root node of the tree to determine the balance factor.
 *
 * Returns: If the tree is NULL, returns 0. Otherwise, returns the balance factor.
 */
int binary_tree_balance(const binary_tree_t *tree)
{
	if (tree != NULL)
		return (binary_tree_height(tree->left) - binary_tree_height(tree->right));

	return (0);
}

/**
 * binary_tree_height - Calculates the height of a binary tree.
 * @tree: A pointer pointing to the root node of the tree to calculate the height.
 *
 * Returns: If the tree is NULL, returns 0. Otherwise, returns the height.
 */
size_t binary_tree_height(const binary_tree_t *tree)
{
	if (tree != NULL)
	{
		size_t left_height = 0, right_height = 0;

		left_height = tree->left ? 1 + binary_tree_height(tree->left) : 1;
		right_height = tree->right ? 1 + binary_tree_height(tree->right) : 1;
		return ((left_height > right_height) ? left_height : right_height);
	}
	return (0);
}
