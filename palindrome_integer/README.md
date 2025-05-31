# Palindrome Integer

## Description

This project provides a function to check whether a given unsigned integer is a palindrome.  
A palindrome is a number that reads the same forwards and backwards (e.g., 121, 12321).

## Requirements

- **Language:** C
- **Compilation:**  
  ```
  gcc -Wall -Wextra -Werror -pedantic -g3 -o palindrome 0-main.c 0-is_palindrome.c
  ```
- **Coding Style:** Betty style
- **No global variables**
- **No dynamic memory allocation**
- **No more than 5 functions per file**
- **All prototypes in `palindrome.h` (include guarded)**

## Usage

1. **Compile:**
   ```sh
   gcc -Wall -Wextra -Werror -pedantic -g3 -o palindrome 0-main.c 0-is_palindrome.c
   ```
2. **Run:**
   ```sh
   ./palindrome <number>
   ```
   Example:
   ```
   ./palindrome 12321
   12321 is a palindrome.
   ```

## Function

```c
int is_palindrome(unsigned long n);
```
- Returns `1` if `n` is a palindrome, `0` otherwise.

## Example

```sh
$ ./palindrome 1
1 is a palindrome.
$ ./palindrome 112
112 is not a palindrome.
$ ./palindrome 123456789987654321
123456789987654321 is a palindrome.
```

## File Structure

- `0-is_palindrome.c` — Implementation of the palindrome check.
- `palindrome.h` — Function prototype and include guard.
- `0-main.c` — Example main for testing (not required for submission).
