#include "binary_trees.h"

/**
 * binary_tree_insert_left - This inserts a node as the left-child of
 *                           another node in a binary tree.
 * @parent: This is a pointer to the node to insert the left-child in.
 * @value: The value to store in the new node.
 *
 * Return: If parent is NULL or an error occurs - NULL.
 *         Otherwise - pointer to the new node.
 *
 * Description:  If the parent already has a left child, the new node
 *               will take its place, and the previous left child
                 will become the left child of the new node.
 */

binary_tree_t *binary_tree_insert_left(binary_tree_t *parent, int value)
{
	binary_tree_t *new_node;

	if (parent == NULL)
		return (NULL);

	new_node = binary_tree_node(parent, value);
	if (new_node == NULL)
		return (NULL);

	if (parent->left != NULL)
	{
		new_node->left = parent->left;
		parent->left->parent = new_node;
	}
	parent->left = new_node;

	return (new_node);
}
