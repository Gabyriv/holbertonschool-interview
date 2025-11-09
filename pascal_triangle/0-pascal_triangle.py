#!/usr/bin/python3
"""
0-pascal_triangle
Function to generate Pascal's triangle up to n rows.
"""


def pascal_triangle(n):
    """
    Return a list of lists of integers representing Pascal’s triangle of n.
    - If n <= 0, return an empty list.
    - n is assumed to be an integer.
    """
    if n <= 0:
        return []

    triangle = [[1]]  # first row

    for i in range(1, n):
        prev = triangle[-1]
        # Each row starts and ends with 1
        row = [1]
        # Internal elements are sum of two above
        for j in range(1, i):
            row.append(prev[j - 1] + prev[j])
        row.append(1)
        triangle.append(row)

    return triangle
