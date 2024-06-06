#include "binary_trees.h"

/**
 * binary_tree_uncle - Finds the uncle node of a given node in a binary tree.
 * @node: A pointer to the node for which to find the uncle.
 *
 * Return: If the node is NULL or has no uncle, returns NULL.
 *         Otherwise, returns a pointer to the uncle node.
 */
binary_tree_t *binary_tree_uncle(binary_tree_t *node)
{
    if (node == NULL || node->parent == NULL || node->parent->parent == NULL)
        return (NULL);
    if (node->parent->parent->left == node->parent)
        return (node->parent->parent->right);
    return (node->parent->parent->left);
}
