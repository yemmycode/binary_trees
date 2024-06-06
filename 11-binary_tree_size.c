#include "binary_trees.h"

/**
 * @brief Measures the size of a binary tree.
 * @param tree A pointer to the root node of the tree to measure the size of.
 * @return The size of the tree.
 */
size_t binary_tree_size(const binary_tree_t *tree)
{
    size_t size = 0;

    if (tree != NULL)
    {
        size += 1;
        size += binary_tree_size(tree->left);
        size += binary_tree_size(tree->right);
    }
    return (size);
}
