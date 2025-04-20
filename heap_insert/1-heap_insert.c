#include "binary_trees.h"

/**
 * heap_insert - Inserts a value into a Max Binary Heap
 *
 * @root: Double pointer to the root node of the Heap
 * @value: Value to store in the node to be inserted
 *
 * Return: Pointer to the inserted node, or NULL on failure
 */
/**
 * binary_tree_size - Count the nodes in a binary tree
 * @tree: pointer to the root of the tree
 *
 * Return: number of nodes in the tree
 */
size_t binary_tree_size(const heap_t *tree)
{
    if (!tree)
        return 0;
    return 1 + binary_tree_size(tree->left) + binary_tree_size(tree->right);
}

/**
 * heapify_up - Restore max-heap property by moving a node up
 * @node: pointer to the node to heapify
 */
void heapify_up(heap_t *node)
{
    while (node->parent && node->n > node->parent->n)
    {
        int tmp = node->n;
        node->n = node->parent->n;
        node->parent->n = tmp;
        node = node->parent;
    }
}

heap_t *heap_insert(heap_t **root, int value)
{
    size_t size, mask;
    heap_t *parent, *new_node;

    /* Invalid root double pointer */
    if (!root)
        return NULL;
    /* Heap is empty: new node becomes root */
    if (!*root)
        return (*root = binary_tree_node(NULL, value));
    /* Compute tree size after insertion and find msb mask */
    size = binary_tree_size(*root) + 1;
    mask = 1UL;
    while (mask <= size)
        mask <<= 1;
    mask >>= 1;
    /* Navigate to parent node for insertion using size bits */
    parent = *root;
    for (mask >>= 1; mask > 1; mask >>= 1)
    {
        /* Go right if bit is set, else left */
        if (size & mask)
            parent = parent->right;
        else
            parent = parent->left;
    }
    /* Create and attach new node */
    new_node = binary_tree_node(parent, value);
    if (!new_node)
        return NULL;
    if (size & 1)
        parent->right = new_node;
    else
        parent->left = new_node;
    /* Restore max-heap order by bubbling up */
    heapify_up(new_node);
    return new_node;
}
