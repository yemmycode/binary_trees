#include "binary_trees.h"
#include <stdlib.h>

/**
 * tree_height - Measures the height of a binary tree.
 * @tree: Pointer to the root node of the tree to measure.
 *
 * Return: The height of the tree or 0 if the tree is NULL.
 */
size_t tree_height(const heap_t *tree)
{
    size_t height_l = 0;
    size_t height_r = 0;

    if (!tree)
        return (0);

    if (tree->left)
        height_l = 1 + tree_height(tree->left);

    if (tree->right)
        height_r = 1 + tree_height(tree->right);

    return (height_l > height_r) ? height_l : height_r;
}

/**
 * tree_size_h - Computes the sum of heights of a binary tree.
 * @tree: Pointer to the root node of the tree to measure.
 *
 * Return: The sum of heights or 0 if the tree is NULL.
 */
size_t tree_size_h(const binary_tree_t *tree)
{
    size_t height_l = 0;
    size_t height_r = 0;

    if (!tree)
        return (0);

    if (tree->left)
        height_l = 1 + tree_size_h(tree->left);

    if (tree->right)
        height_r = 1 + tree_size_h(tree->right);

    return (height_l + height_r);
}

/**
 * _preorder - Traverses a binary tree using pre-order traversal.
 * @tree: Pointer to the root node of the tree to traverse.
 * @node: Pointer to store the last node visited.
 * @height: The height of the tree.
 *
 * Return: No return value.
 */
void _preorder(heap_t *tree, heap_t **node, size_t height)
{
    if (!tree)
        return;

    if (height == 0)
        *node = tree;
    height--;

    _preorder(tree->left, node, height);
    _preorder(tree->right, node, height);
}

/**
 * heapify - Ensures the binary tree adheres to max-heap properties.
 * @root: Pointer to the root node of the binary heap.
 *
 * Return: No return value.
 */
void heapify(heap_t *root)
{
    int value;
    heap_t *current, *largest_child;

    if (!root)
        return;

    current = root;

    while (1)
    {
        if (!current->left)
            break;
        if (!current->right)
            largest_child = current->left;
        else
            largest_child = (current->left->n > current->right->n) ? current->left : current->right;

        if (current->n > largest_child->n)
            break;

        value = current->n;
        current->n = largest_child->n;
        largest_child->n = value;

        current = largest_child;
    }
}

/**
 * heap_extract - Extracts the root node from a Max Binary Heap.
 * @root: Double pointer to the root node of the heap.
 *
 * Return: The value of the extracted node.
 */
int heap_extract(heap_t **root)
{
    int value;
    heap_t *heap_r, *node;

    if (!root || !*root)
        return (0);

    heap_r = *root;
    value = heap_r->n;

    if (!heap_r->left && !heap_r->right)
    {
        *root = NULL;
        free(heap_r);
        return (value);
    }

    _preorder(heap_r, &node, tree_height(heap_r));

    heap_r->n = node->n;
    if (node->parent->right)
        node->parent->right = NULL;
    else
        node->parent->left = NULL;
    free(node);

    heapify(heap_r);
    *root = heap_r;

    return (value);
}
