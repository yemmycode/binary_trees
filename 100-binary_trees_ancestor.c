
#include "binary_trees.h"

/**
 * binary_trees_ancestor - This finds the lowest common ancestor of two nodes.
 * @first: A pointer to the first node.
 * @second: A pointer to the second node.
 *
 * Return: If no common ancestors, return NULL; otherwise, return common ancestor.
 */
binary_tree_t *binary_trees_ancestor(const binary_tree_t *first,
                                     const binary_tree_t *second)
{
    binary_tree_t *mom, *pop;

    if (first == NULL || second == NULL)
        return (NULL);
    if (first == second)
        return ((binary_tree_t *)first);

    mom = first->parent, pop = second->parent;
    if (first == pop || !mom || (!mom->parent && pop))
        return (binary_trees_ancestor(first, pop));
    else if (mom == second || !pop || (!pop->parent && mom))
        return (binary_trees_ancestor(mom, second));
    return (binary_trees_ancestor(mom, pop));
}
