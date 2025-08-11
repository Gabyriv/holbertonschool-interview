# Advanced Binary Search

Implements a recursive binary search that returns the first occurrence of a value in a sorted array and prints the current subarray at each step.

## Prototype
```
int advanced_binary(int *array, size_t size, int value);
```

## Build
```
gcc -Wall -Wextra -Werror -pedantic 0-main.c 0-advanced_binary.c -o 0-advanced_binary
```

## Run
```
./0-advanced_binary
```

## Notes
- No globals, only `printf` used.
- One loop only (for printing the current subarray).
- Uses recursion to search for the first occurrence.
