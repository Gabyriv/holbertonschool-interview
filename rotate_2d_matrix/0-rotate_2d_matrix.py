#!/usr/bin/python3
"""
Rotate 2D Matrix module.
"""


def rotate_2d_matrix(matrix):
    """
    Rotate an n x n 2D matrix 90 degrees clockwise in-place.

    Args:
        matrix (list of lists): Square matrix to rotate. The matrix is
        modified in-place.

    Returns:
        None
    """
    # Transpose the matrix
    n = len(matrix)
    for i in range(n):
        for j in range(i + 1, n):
            matrix[i][j], matrix[j][i] = matrix[j][i], matrix[i][j]

    # Reverse each row (in-place)
    for i in range(n):
        start = 0
        end = n - 1
        while start < end:
            matrix[i][start], matrix[i][end] = matrix[i][end], matrix[i][start]
            start += 1
            end -= 1
