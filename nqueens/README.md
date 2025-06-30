# N Queens

## Requirements

- Allowed editors: `vi`, `vim`, `emacs`
- All your files will be interpreted/compiled on Ubuntu 14.04 LTS using `python3` (version 3.4.3)
- All your files should end with a new line
- The first line of all your files should be exactly `#!/usr/bin/python3`
- A `README.md` file, at the root of the folder of the project, is mandatory
- Your code should use the `PEP 8` style (version 1.7.*)
- All your files must be executable

## Description

The N queens puzzle is the challenge of placing N non-attacking queens on an N×N chessboard. This program solves the N queens problem using a backtracking algorithm.

### Usage

```bash
./0-nqueens.py N
```

- If the user calls the program with the wrong number of arguments, it prints:

```bash
  Usage: nqueens N
```

and exits with status 1.

- Where `N` must be an integer greater than or equal to 4:
  - If `N` is not an integer, it prints:

    ```bash
    N must be a number
    ```

    and exits with status 1.
  - If `N` is smaller than 4, it prints:

    ```bash
    N must be at least 4
    ```

    and exits with status 1.

### Output

- The program prints every possible solution to the problem.
- One solution per line.
- Format: Each solution is a list of lists, where each inner list represents the row and column of a queen: `[[row, col], [row, col], ...]`
- Solutions do not have to be printed in a specific order.

#### Example

```bash
$ ./0-nqueens.py 4
[[0, 1], [1, 3], [2, 0], [3, 2]]
[[0, 2], [1, 0], [2, 3], [3, 1]]

$ ./0-nqueens.py 6
[[0, 1], [1, 3], [2, 5], [3, 0], [4, 2], [5, 4]]
[[0, 2], [1, 5], [2, 1], [3, 4], [4, 0], [5, 3]]
[[0, 3], [1, 0], [2, 4], [3, 1], [4, 5], [5, 2]]
[[0, 4], [1, 2], [2, 0], [3, 5], [4, 3], [5, 1]]
```

### Additional Notes

- Only the `sys` module is allowed for import.
