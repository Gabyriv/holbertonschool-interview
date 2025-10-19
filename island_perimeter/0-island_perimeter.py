#!/usr/bin/python3
"""Island perimeter calculation module."""


def island_perimeter(grid):
    """Return the perimeter of the island represented by ``grid``.

    Args:
        grid (list[list[int]]): Rectangular matrix where ``1`` marks land and
            ``0`` marks water.

    Returns:
        int: Total perimeter of the island, or 0 if the grid is empty.
    """

    if not grid:
        return 0

    rows = len(grid)
    cols = len(grid[0])
    perimeter = 0

    for row in range(0, rows):
        for col in range(0, cols):

            if grid[row][col] == 1:
                # check up
                if row - 1 < 0 or grid[row - 1][col] == 0:
                    perimeter += 1

                # check down
                if row + 1 >= rows or grid[row + 1][col] == 0:
                    perimeter += 1

                # check left
                if col - 1 < 0 or grid[row][col - 1] == 0:
                    perimeter += 1

                # check right
                if col + 1 >= cols or grid[row][col + 1] == 0:
                    perimeter += 1

    return perimeter
