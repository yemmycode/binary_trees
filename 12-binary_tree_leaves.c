#include "binary_trees.h"

/**
 * @brief Counts the leaves in a binary tree.
 * @param tree A pointer to the root node of the tree to count the leaves of.
 * @return The number of leaves in the tree.
 */
size_t binary_tree_leaves(const binary_tree_t *tree)
{
    size_t leaves = 0;

    if (tree != NULL)
    {
        leaves += (!tree->left && !tree->right) ? 1 : 0;
        leaves += binary_tree_leaves(tree->left);
        leaves += binary_tree_leaves(tree->right);
    }
    return (leaves);
}
