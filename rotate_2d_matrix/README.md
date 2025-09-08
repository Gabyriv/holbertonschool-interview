# Rotate 2D Matrix

Rotate an `n x n` 2D matrix by 90 degrees clockwise in-place.

## Requirements

- Python 3.4.3
- Ubuntu 14.04 LTS
- PEP 8 (1.7.x)
- No external imports
- All files executable
- Shebang: `#!/usr/bin/python3`
- Module and function docstrings

## Usage

Example test in [main_0.py](cci:7://file:///Users/gabrielrivera/Holberton/holbertonschool-interview/rotate_2d_matrix/main_0.py:0:0-0:0):

```python
#!/usr/bin/python3
"""
Test - Rotate 2D Matrix
"""
rotate_2d_matrix = __import__('0-rotate_2d_matrix').rotate_2d_matrix

if __name__ == "__main__":
    matrix = [[1, 2, 3],
              [4, 5, 6],
              [7, 8, 9]]

    rotate_2d_matrix(matrix)
    print(matrix)
```
