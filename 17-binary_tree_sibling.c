#include "binary_trees.h"

/**
 * binary_tree_sibling - Finds the sibling of a given node in a binary tree.
 * @node: A pointer to the node for which to find the sibling.
 *
 * Return: If the node is NULL or there is no sibling - NULL.
 *         Otherwise - a pointer to the sibling node.
 */
binary_tree_t *binary_tree_sibling(binary_tree_t *node)
{
    if (node == NULL || node->parent == NULL)
        return (NULL);
    if (node->parent->left == node)
        return (node->parent->right);
    return (node->parent->left);
}
