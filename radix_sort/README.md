# Radix Sort

## Description

Implementation of the Radix Sort algorithm using the LSD (Least Significant Digit) approach. This non-comparative sorting algorithm processes integers digit by digit from the rightmost (least significant) to the leftmost (most significant) digit.

## Files

- **0-radix_sort.c** - Radix sort implementation with helper functions
- **sort.h** - Header file containing function prototypes
- **print_array.c** - Helper function to print arrays
- **0-main.c** - Test file

## Compilation

```bash
gcc -Wall -Wextra -Werror -pedantic 0-main.c 0-radix_sort.c print_array.c -o radix
```

## Usage

```bash
./radix
```

## Algorithm Details

The implementation uses counting sort as a subroutine to sort by each digit position. The array is printed after processing each significant digit, showing the progression of the sort.
