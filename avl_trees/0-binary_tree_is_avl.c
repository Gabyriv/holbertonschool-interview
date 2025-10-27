#include "binary_trees.h"
#include <limits.h>

/**
 * height - Measures the height of a binary tree
 * @tree: Pointer to the root node of the tree to measure the height
 *
 * Return: Height of the tree, or 0 if tree is NULL
 */
int height(const binary_tree_t *tree)
{
	int left_height, right_height;

	if (tree == NULL)
		return (0);

	left_height = height(tree->left);
	right_height = height(tree->right);

	return (1 + (left_height > right_height ? left_height : right_height));
}

/**
 * is_avl_helper - Checks if a binary tree is a valid AVL tree
 * @tree: Pointer to the root node of the tree to check
 * @min: Minimum value allowed in the tree
 * @max: Maximum value allowed in the tree
 *
 * Return: 1 if tree is a valid AVL tree, 0 otherwise
 */
int is_avl_helper(const binary_tree_t *tree, int min, int max)
{
	int left_height, right_height, balance;

	if (tree == NULL)
		return (1);

	/* Check BST property: node value must be within min and max bounds */
	if (tree->n <= min || tree->n >= max)
		return (0);

	/* Calculate heights of left and right subtrees */
	left_height = height(tree->left);
	right_height = height(tree->right);

	/* Calculate balance factor */
	balance = left_height - right_height;

	/* Check if balance factor is within AVL limits (-1, 0, 1) */
	if (balance > 1 || balance < -1)
		return (0);

	/* Recursively check left and right subtrees */
	/* Left subtree: all values must be less than current node */
	/* Right subtree: all values must be greater than current node */
	return (is_avl_helper(tree->left, min, tree->n) &&
		is_avl_helper(tree->right, tree->n, max));
}

/**
 * binary_tree_is_avl - Checks if a binary tree is a valid AVL tree
 * @tree: Pointer to the root node of the tree to check
 *
 * Return: 1 if tree is a valid AVL tree, 0 otherwise
 */
int binary_tree_is_avl(const binary_tree_t *tree)
{
	if (tree == NULL)
		return (0);

	return (is_avl_helper(tree, INT_MIN, INT_MAX));
}
