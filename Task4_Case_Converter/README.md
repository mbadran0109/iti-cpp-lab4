# Task 4: Character Array Case Converter

> **Educational Notice:** This project was created strictly for **educational purposes** as part of a C++ Object-Oriented Programming lab assignment (Lab 4).

## Problem Description

Write a program that inputs a line of text into a character array `char s[100]` and outputs the text with uppercase and lowercase letters converted.

## How the Code Works

- **File:** [`case_converter.cpp`](./case_converter.cpp)
- Reads a line of input into `char s[100]` using `cin.getline(s, 100)`.
- Iterates through each character until the null terminator (`'\0'`):
  - Validates alphabetic characters with `isalpha()`.
  - Converts lowercase letters (`'a'`–`'z'`) to uppercase by subtracting `32` from their ASCII value.
  - Converts uppercase letters (`'A'`–`'Z'`) to lowercase by adding `32` to their ASCII value.
  - Prints an error message if a non-letter character is encountered.
- Displays the converted character array.

## Compile & Run

```bash
g++ case_converter.cpp -o case_converter
./case_converter
```
