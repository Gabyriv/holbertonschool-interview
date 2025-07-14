# Linear Skip List Search

This project implements a linear search algorithm optimized for a sorted skip list of integers. A skip list is a singly linked list with an additional express lane to speed up search operations.

## Project Structure
- `0-linear_skip.c`: Contains the implementation of the `linear_skip` function.
- `search.h`: Header file with the skip list structure and function prototypes.
- `skiplist/`: Directory containing helper functions for creating, printing, and freeing skip lists (provided by Holberton).
- `0-main.c`: Example main file to test the implementation (provided for local testing).

## How It Works
The `linear_skip` function searches for a value in a sorted skip list:
1. It uses the express lane to quickly narrow down the search range.
2. Once the range is found, it performs a linear search within that segment.
3. Every value checked during the search is printed, as required by the project.

## Compilation
To compile the project with the provided helper files, use:

```
gcc -Wall -Wextra -Werror -pedantic -I. 0-main.c 0-linear_skip.c skiplist/*.c -lm -o 0-linear_skip
```

## Usage
Run the compiled program:

```
./0-linear_skip
```

This will print the skip list, the express lane, and the search process for sample values.

## Requirements
- No global variables
- Betty style and documentation
- All prototypes in `search.h`
- Works with the provided Holberton helper files
