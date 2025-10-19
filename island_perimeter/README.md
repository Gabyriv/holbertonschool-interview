# Island Perimeter

## Description
This project provides a Python implementation of `island_perimeter(grid)`, a function that computes the perimeter of an island represented as a grid of water and land cells.

## Requirements
- **Language**: Python 3.4.3
- **Environment**: Ubuntu 14.04 LTS
- **Editors**: `vi`, `vim`, `emacs`
- **Style**: PEP 8 (version 1.7)
- **Imports**: No additional modules allowed
- **File constraints**:
  - All files must end with a new line
  - The first line of each script must be `#!/usr/bin/python3`
  - All files must be executable
- **Documentation**: Every module and function must include a docstring

## Task
- **Function**: `def island_perimeter(grid)`
- **Input**: `grid` is a rectangular list of lists of integers where:
  - `0` represents water
  - `1` represents land
  - Cells are connected horizontally or vertically (not diagonally)
- **Constraints**:
  - Width and height of `grid` do not exceed 100
  - The grid is completely surrounded by water
  - At most one island exists (or none)
  - The island has no internal lakes

## Usage Example
```bash
./0-main.py
```
Outputs:
```text
12
```
