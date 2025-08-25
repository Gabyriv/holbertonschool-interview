#include <stdlib.h>
#include "binary_trees.h"

/**
 * tree_size - Computes the number of nodes in a binary tree
 * @tree: Pointer to root
 *
 * Return: number of nodes
 */
static size_t tree_size(const binary_tree_t *tree)
{
	if (!tree)
		return (0);
	return (1 + tree_size(tree->left) + tree_size(tree->right));
}

/**
 * get_node_by_index - Gets the node at a given 1-based index in a heap
 * using the binary representation path (level-order indexing).
 * @root: Pointer to heap root
 * @index: 1-based index (root is 1)
 *
 * Return: Node pointer at index, or NULL if not found
 */
static heap_t *get_node_by_index(heap_t *root, size_t index)
{
	size_t mask;
	heap_t *node;

	if (!root || index == 0)
		return (NULL);

	/* Find highest set bit */
	mask = (size_t)1 << (sizeof(size_t) * 8 - 1);
	while ((mask & index) == 0)
		mask >>= 1;

	/* Skip MSB (root) and walk path: 0->left, 1->right */
	mask >>= 1;
	node = root;
	while (node && mask)
	{
		if (index & mask)
			node = node->right;
		else
			node = node->left;
		mask >>= 1;
	}
	return (node);
}

/**
 * sift_down - Restores max-heap property starting from a node by sifting down
 * @node: Node to sift down from
 */
static void sift_down(heap_t *node)
{
	heap_t *largest, *left, *right;
	int tmp;

	if (!node)
		return;

	while (1)
	{
		left = node->left;
		right = node->right;
		largest = node;

		if (left && left->n > largest->n)
			largest = left;
		if (right && right->n > largest->n)
			largest = right;

		if (largest == node)
			break;

		/* Swap values with largest child */
		tmp = node->n;
		node->n = largest->n;
		largest->n = tmp;

		node = largest;
	}
}

/**
 * heap_extract - Extracts the root value of a Max Binary Heap
 * @root: Address of pointer to heap root
 *
 * Return: Extracted root value, or 0 on failure
 */
int heap_extract(heap_t **root)
{
	size_t n;
	int value;
	heap_t *parent, *last;

	if (!root || !*root)
		return (0);

	value = (*root)->n;
	n = tree_size(*root);
	if (n == 1)
	{
		free(*root);
		*root = NULL;
		return (value);
	}

	/* Find parent of last node (index n/2), then pick child by parity of n */
	parent = get_node_by_index(*root, n / 2);
	if (!parent)
		return (0);

	if (n & 1)
		last = parent->right;
	else
		last = parent->left;

	if (!last)
		return (0);

	/* Move last node's value to root, detach last, free it, then fix heap */
	(*root)->n = last->n;
	if (parent->right == last)
		parent->right = NULL;
	else
		parent->left = NULL;
	free(last);

	sift_down(*root);
	return (value);
}
