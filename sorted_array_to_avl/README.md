# Sorted Array to AVL Tree

This project implements a function to build a balanced AVL tree from a sorted array. The implementation uses a divide-and-conquer approach to ensure the resulting tree is naturally balanced without requiring rotations.

## Description

The main function `sorted_array_to_avl` takes a sorted array of integers and constructs an AVL tree where:

- Each element from the array becomes a node in the tree
- The tree is balanced (no rotations needed)
- The middle element of any subarray becomes the root of that subtree
- Left and right subtrees are built recursively from the left and right halves of the array

## Files

- `0-sorted_array_to_avl.c` - Main implementation file containing the AVL tree building function
- `binary_trees.h` - Header file with data structure definitions and function prototypes
- `binary_tree_print.c` - Utility function for printing binary trees (provided)
- `0-main.c` - Example main function demonstrating usage

## Data Structures

```c
/**
 * struct binary_tree_s - Binary tree node
 *
 * @n: Integer stored in the node
 * @parent: Pointer to the parent node
 * @left: Pointer to the left child node
 * @right: Pointer to the right child node
 */
typedef struct binary_tree_s
{
    int n;
    struct binary_tree_s *parent;
    struct binary_tree_s *left;
    struct binary_tree_s *right;
} binary_tree_t;

typedef struct binary_tree_s avl_t;
```

## Functions

### `avl_t *sorted_array_to_avl(int *array, size_t size)`

Builds an AVL tree from a sorted array.

**Parameters:**

- `array`: Pointer to the first element of the sorted array
- `size`: Number of elements in the array

**Returns:**

- Pointer to the root node of the created AVL tree
- `NULL` if array is NULL or size is 0

**Algorithm:**

1. If array is NULL or size is 0, return NULL
2. Use divide-and-conquer approach:
   - Find the middle element of the current subarray
   - Create a node with the middle element as root
   - Recursively build left subtree from left half
   - Recursively build right subtree from right half

## Compilation

```bash
gcc -Wall -Wextra -Werror -pedantic binary_tree_print.c 0-main.c 0-sorted_array_to_avl.c -o 0-sorted_array_to_avl
```

## Usage

```bash
./0-sorted_array_to_avl
```

**Example Output:**

```bash
(001)(002)(020)(021)(022)(032)(034)(047)(062)(068)(079)(084)(087)(091)(095)(098)
                 .-----------------(047)-----------------.
       .-------(021)-------.                   .-------(084)-------.
  .--(002)--.         .--(032)--.         .--(068)--.         .--(091)--.
(001)     (020)     (022)     (034)     (062)     (079)     (087)     (095)--.
                                                                           (098)
```

## Requirements

- C compiler (gcc 4.8.4 or later)
- Ubuntu 14.04 LTS or compatible system
- Betty style compliance (checked with betty-style.pl and betty-doc.pl)
