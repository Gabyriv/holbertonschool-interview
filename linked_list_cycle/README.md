# Linked List Cycle

## Description
This project implements a function in C to check if a singly linked list contains a cycle. It uses Floyd's Tortoise and Hare algorithm for efficient cycle detection. The project is designed for Holberton School interview preparation.

## Requirements
- Allowed editors: `vi`, `vim`, `emacs`
- All files compiled on Ubuntu 14.04 LTS with `gcc 4.8.4` using flags: `-Wall -Werror -Wextra -pedantic`
- No use of global variables
- No more than 5 functions per file
- All header files are include guarded
- Code style: Betty

## Files
- `lists.h`: Header file with struct definition and function prototypes
- `0-check_cycle.c`: Contains the `check_cycle` function to detect cycles in a linked list
- `0-linked_lists.c`: Helper functions to print, add, and free nodes in a linked list
- `0-main.c`: Test file to demonstrate and validate the cycle detection function

## Usage
1. **Compile:**
   ```sh
   gcc -Wall -Werror -Wextra -pedantic 0-main.c 0-check_cycle.c 0-linked_lists.c -o cycle
   ```
2. **Run:**
   ```sh
   ./cycle
   ```

## Example Output
```
1024
402
98
4
3
2
1
0
Linked list has no cycle
Linked list has a cycle
```

## Function Prototype
```
int check_cycle(listint_t *list);
```
- Returns `1` if a cycle is detected, `0` otherwise.

## Author
Carrie Ybay, Software Engineer at Holberton School 
