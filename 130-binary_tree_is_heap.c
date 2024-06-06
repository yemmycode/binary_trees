#include "binary_trees.h"

/**
 * b_height - Calculates the height of a binary tree
 * @tree: Pointer to the root node of the tree to measure
 * Return: Height of the tree
 */
int b_height(const binary_tree_t *tree)
{
	if (tree == NULL)
		return (0);
	return (1 + b_height(tree->left) + b_height(tree->right));
}

/**
 * is_complete - Checks if a binary tree is complete
 * @root: Pointer to the root node of the tree to check
 * @index: Current index in the array representation of the tree
 * @n_nodes: Total number of nodes in the tree
 * Return: 1 if the tree is complete, otherwise 0
 */
int is_complete(const binary_tree_t *root, int index, int n_nodes)
{
	if (root == NULL)
		return (1);
	if (index >= n_nodes)
		return (0);
	return (is_complete(root->left, 2 * index + 1, n_nodes) &&
	        is_complete(root->right, 2 * index + 2, n_nodes));
}

/**
 * is_heap - Checks if a binary tree is a max-heap
 * @node: Pointer to the root node of the tree or subtree to check
 * Return: 1 if the tree is a max-heap, otherwise 0
 */
int is_heap(const binary_tree_t *node)
{
	if (node->left == NULL && node->right == NULL)
		return (1);
	if (node->right == NULL)
		return (node->n >= node->left->n);
	if (node->n >= node->left->n && node->n >= node->right->n)
		return (is_heap(node->left) && is_heap(node->right));
	return (0);
}

/**
 * binary_tree_is_heap - Checks if a binary tree is a valid max binary heap
 * @tree: Pointer to the root node of the tree to check
 * Return: 1 if the tree is a valid max binary heap, otherwise 0
 *         If tree is NULL, return 0
 */
int binary_tree_is_heap(const binary_tree_t *tree)
{
	int height;
	int index = 0;

	if (tree == NULL)
		return (0);

	height = b_height(tree);

	if (is_complete(tree, index, height) && is_heap(tree))
		return (1);
	return (0);
}
