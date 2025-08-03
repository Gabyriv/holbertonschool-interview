# Heap Sort

This project implements the heap sort algorithm in C, following the Betty coding style and strict compilation requirements.

## Files

- `sort.h` - Header file containing function prototypes and include guards
- `0-heap_sort.c` - Implementation of the heap sort algorithm using sift-down method
- `0-O` - Big O notation for heap sort time complexity (best, average, worst case)
- `print_array.c` - Utility function to print arrays (provided)

## Algorithm

Heap sort is a comparison-based sorting algorithm that uses a binary heap data structure. It works by:

1. Building a max heap from the input array
2. Repeatedly extracting the maximum element and placing it at the end
3. Using sift-down operation to maintain heap property

## Time Complexity

- Best case: O(n log n)
- Average case: O(n log n)
- Worst case: O(n log n)

## Compilation

```bash
gcc -Wall -Wextra -Werror -pedantic 0-main.c 0-heap_sort.c print_array.c -o 0-heap
```

## Usage

The `heap_sort` function sorts an array of integers in ascending order and prints the array after each swap operation.

```c
void heap_sort(int *array, size_t size);
```

## Requirements

- Ubuntu 14.04 LTS
- gcc 4.8.4 with flags: -Wall -Werror -Wextra -pedantic
- Betty coding style
- No global variables
- Maximum 5 functions per file
- No standard library functions except the provided print_array
