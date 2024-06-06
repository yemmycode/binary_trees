#include "binary_trees.h"

/**
 * _height - Computes the height of a binary tree.
 * @tree: Pointer to the root node of the tree.
 *
 * Return: Height of the tree, or -1 if tree is NULL.
 */
int _height(const binary_tree_t *tree)
{
    size_t height_left = 0;
    size_t height_right = 0;

    if (!tree)
        return (-1);

    height_left = _height(tree->left);
    height_right = _height(tree->right);

    if (height_left > height_right)
        return (height_left + 1);
    return (height_right + 1);
}

/**
 * greater_than_parent - Reorders the tree to maintain the heap property.
 * @parent: Double pointer to the parent node.
 * @child: Double pointer to the child node.
 *
 * Return: None.
 */
void greater_than_parent(heap_t **parent, heap_t **child)
{
    heap_t *p, *c, *new_child, *new_left, *new_right, *par;
    int gtp;

    p = *parent;
    c = *child;
    if (c->n > p->n)
    {
        if (c->left)
            c->left->parent = p;
        if (c->right)
            c->right->parent = p;
        if (p->left == c)
            new_child = p->right, gtp = 0;
        else
            new_child = p->left, gtp = 1;
        new_left = c->left, new_right = c->right;
        if (gtp == 0)
        {
            c->right = new_child;
            if (new_child)
                new_child->parent = c;
            c->left = p;
        }
        else
        {
            c->left = new_child;
            if (new_child)
                new_child->parent = c;
            c->right = p;
        }
        if (p->parent)
        {
            if (p->parent->left == p)
                p->parent->left = c;
            else
                p->parent->right = c;
        }
        par = p->parent, c->parent = par;
        p->parent = c, p->left = new_left;
        p->right = new_right, *parent = c;
    }
}

/**
 * is_perfect - Checks if a binary tree is perfect.
 * @root: Pointer to the root node of the tree.
 *
 * Return: 1 if the tree is perfect, 0 otherwise.
 */
int is_perfect(const binary_tree_t *root)
{
    if (root && _height(root->left) == _height(root->right))
    {
        if (_height(root->left) == -1)
            return (1);
        if ((root->left && !(root->left->left) && !(root->left->right)) &&
            (root->right && !(root->right->left) && !(root->right->right)))
            return (1);
        if (root->left && root->right)
            return (is_perfect(root->left) && is_perfect(root->right));
    }
    return (0);
}

/**
 * heap_insert - Inserts a value into a Max Binary Heap.
 * @root: Double pointer to the root node of the Heap.
 * @value: Value to be inserted.
 *
 * Return: Pointer to the inserted node, or NULL on failure.
 */
heap_t *heap_insert(heap_t **root, int value)
{
    heap_t *new_node;

    if (*root == NULL)
    {
        *root = binary_tree_node(NULL, value);
        return (*root);
    }
    if (is_perfect(*root) || !is_perfect((*root)->left))
    {
        if ((*root)->left)
        {
            new_node = heap_insert(&((*root)->left), value);
            greater_than_parent(root, &((*root)->left));
            return (new_node);
        }
        else
        {
            new_node = (*root)->left = binary_tree_node(*root, value);
            greater_than_parent(root, &((*root)->left));
            return (new_node);
        }
    }
    if ((*root)->right)
    {
        new_node = heap_insert(&((*root)->right), value);
        greater_than_parent(root, &((*root)->right));
        return (new_node);
    }
    else
    {
        new_node = (*root)->right = binary_tree_node(*root, value);
        greater_than_parent(root, &((*root)->right));
        return (new_node);
    }
    return (NULL);
}
