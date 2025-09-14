# Find the Loop

Find the starting node of a loop in a singly linked list.

Function to implement:

```c
listint_t *find_listint_loop(listint_t *head);
```

The function returns the address of the node where the loop starts,
or `NULL` if there is no loop.

## Requirements (Holberton)

- Compiled on Ubuntu 14.04 LTS
- Compiler: `gcc 4.8.4` with flags `-Wall -Werror -Wextra -pedantic`
- Betty style: checked with `betty-style.pl` and `betty-doc.pl`
- No global variables
- No use of standard library functions in `0-find_loop.c`
- Do not use `malloc`, `free`, or arrays in `0-find_loop.c`
- Maximum of 2 variables declared inside the function
- All prototypes in `lists.h` (header is include-guarded)

## Files

- `0-find_loop.c` — implementation using Floyd’s cycle detection
- `lists.h` — type definitions and prototypes
- `README.md` — this file
- `0-main.c` — example test (not graded; you can use a local copy)
- `lib.c` — helper functions for local testing (alternative to `libloop.a`)

## Build and Run

You can test with either the provided static library or the provided source
`lib.c`.

Using the provided static library (on Ubuntu):

```sh
gcc -Wall -pedantic -Werror -Wextra 0-main.c 0-find_loop.c -L. -lloop -o main
./main
```

Using the provided source `lib.c` instead of the library:

```sh
gcc -Wall -pedantic -Werror -Wextra 0-main.c 0-find_loop.c lib.c -o main
./main
```

## Example Output

```text
[0x... ] 1024
[0x... ] 402
[0x... ] 98
...
-> [0x... ] 7
Loop starts at [0x... ] 7
```

Note: Addresses will vary per run and environment.

## Algorithm

This solution uses Floyd’s cycle detection (tortoise and hare) with two
pointers:

- `slow_ptr` advances by one node
- `fast_ptr` advances by two nodes

If they meet, a loop exists. Reset `slow_ptr` to `head` and move both pointers
one step at a time; the node where they meet again is the loop’s starting node.

Complexity: O(n) time, O(1) extra space.
