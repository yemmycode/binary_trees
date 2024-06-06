#include "binary_trees.h"
#include "limits.h"

/**
 * height - Calculates the height of a binary tree.
 * @tree: A pointer to the root node of the tree.
 *
 * Return: The height of the tree. If the tree is NULL, returns 0.
 */
size_t height(const binary_tree_t *tree)
{
	if (tree)
	{
		size_t left_height = 0, right_height = 0;

		left_height = tree->left ? 1 + height(tree->left) : 1;
		right_height = tree->right ? 1 + height(tree->right) : 1;
		return ((left_height > right_height) ? left_height : right_height);
	}
	return (0);
}

/**
 * is_avl_helper - Checks if a binary tree is a valid AVL tree recursively.
 * @tree: A pointer to the root node of the tree.
 * @min: The minimum value encountered so far.
 * @max: The maximum value encountered so far.
 *
 * Return: 1 if the tree is a valid AVL tree, 0 otherwise.
 */
int is_avl_helper(const binary_tree_t *tree, int min, int max)
{
	size_t left_height, right_height, height_diff;

	if (tree != NULL)
	{
		if (tree->n < min || tree->n > max)
			return (0);
		left_height = height(tree->left);
		right_height = height(tree->right);
		height_diff = left_height > right_height ? left_height - right_height : right_height - left_height;
		if (height_diff > 1)
			return (0);
		return (is_avl_helper(tree->left, min, tree->n - 1) &&
			is_avl_helper(tree->right, tree->n + 1, max));
	}
	return (1);
}

/**
 * binary_tree_is_avl - Checks if a binary tree is a valid AVL tree.
 * @tree: A pointer to the root node of the tree.
 *
 * Return: 1 if the tree is a valid AVL tree, 0 otherwise.
 */
int binary_tree_is_avl(const binary_tree_t *tree)
{
	if (tree == NULL)
		return (0);
	return (is_avl_helper(tree, INT_MIN, INT_MAX));
}
