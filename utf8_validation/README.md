# UTF-8 Validation

This project implements a function to validate UTF-8 encoding in Python. The solution checks if a given data set represents a valid UTF-8 encoding according to the UTF-8 encoding rules.

## Requirements

- Python 3.4.3
- Ubuntu 14.04 LTS

## Files

- `0-validate_utf8.py`: Contains the main validation function
- `0-main.py`: Test file with example cases

## Usage

The main function can be used as follows:

```python
validUTF8 = __import__('0-validate_utf8').validUTF8

# Example usage
data = [65]  # Single byte character
print(validUTF8(data))  # True

data = [80, 121, 116, 104, 111, 110, 32, 105, 115, 32, 99, 111, 111, 108, 33]  # ASCII string
print(validUTF8(data))  # True

data = [229, 65, 127, 256]  # Invalid UTF-8 sequence
print(validUTF8(data))  # False
```

## UTF-8 Encoding Rules

- A character in UTF-8 can be 1 to 4 bytes long
- Single byte characters start with 0 (ASCII)
- Multi-byte characters start with 1s followed by a 0
- The number of leading 1s indicates the total number of bytes
- Continuation bytes must start with 10

## Author

Gabriel Rivera
