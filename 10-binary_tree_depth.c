#include "binary_trees.h"

/**
 * @brief Measures the depth of a node in a binary tree.
 * @param tree A pointer to the node to measure the depth.
 * @return If tree is NULL, the function returns 0, else it returns the depth.
 */
size_t binary_tree_depth(const binary_tree_t *tree)
{
    if (tree != NULL && tree->parent != NULL)
        return 1 + binary_tree_depth(tree->parent);
    else
        return 0;
}
