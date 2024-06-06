#include "limits.h"
#include "binary_trees.h"

/**
 * is_bst_helper - Determines if a binary tree is a valid binary search tree.
 * @tree: pointer to the root node of the tree to assess.
 * @lo: value of the smallest visited node.
 * @hi: value of the largest visited node.
 *
 * Return: 1 if the tree is a valid BST, 0 otherwise.
 */
int is_bst_helper(const binary_tree_t *tree, int lo, int hi)
{
	if (tree)
	{
		if (tree->n < lo || tree->n > hi)
			return 0;
		return is_bst_helper(tree->left, lo, tree->n - 1) &&
		       is_bst_helper(tree->right, tree->n + 1, hi);
	}
	return (1);
}

/**
 * binary_tree_is_bst - Checks if a binary tree is a valid binary search tree.
 * @tree: A pointer to the root node of the tree to check.
 *
 * Return: 1 if the tree is a valid BST, 0 otherwise.
 */
int binary_tree_is_bst(const binary_tree_t *tree)
{
	if (!tree)
		return 0;
	return (is_bst_helper(tree, INT_MIN, INT_MAX));
}
