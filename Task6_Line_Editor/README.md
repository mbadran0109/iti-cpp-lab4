# Task 6: Console Line Editor (Fixed & Dynamic Versions)

> **Educational Notice:** This project was created strictly for **educational purposes** as part of a C++ Object-Oriented Programming lab assignment (Lab 4).

## Problem Description

Implement an interactive single-line console **Line Editor** supporting cursor navigation and live editing using keyboard controls.

## Included Implementations

This folder contains **two versions** of the Line Editor:

1. **[`line_editor_fixed.cpp`](./line_editor_fixed.cpp)** *(Fixed-Size Buffer)*
   - Uses a fixed character array `char s[11]` allowing up to **10** alphanumeric characters (`isalnum`).
2. **[`line_editor_dynamic.cpp`](./line_editor_dynamic.cpp)** *(Dynamic-Size Buffer with `struct Line`)*
   - Prompts the user for the maximum character count (`nc`) and dynamically allocates `new char[nc + 1]` inside a `Line` struct (`str`, `len`, `size`).

## Supported Keyboard Controls

| Key | Action |
| :--- | :--- |
| **Letters & Numbers** | Insert character at the current cursor position (shifts trailing characters right) |
| **Left Arrow** | Move cursor one position left |
| **Right Arrow** | Move cursor one position right |
| **Home** | Move cursor to the start of the line |
| **End** | Move cursor to the end of the line |
| **Backspace** | Delete the character before the cursor |
| **Delete** | Delete the character at the cursor |
| **Enter** | Finish editing and display the typed string |
| **Escape** | Exit the editor immediately |

## Platform Note

Both programs use Windows-specific headers (`<conio.h>` for `_getch()` and `<windows.h>` for `SetConsoleCursorPosition`) and should be compiled and run on **Windows**.

## Compile & Run (Windows / MinGW)

```bash
# Fixed-length version
g++ line_editor_fixed.cpp -o line_editor_fixed
./line_editor_fixed

# Dynamic-length version
g++ line_editor_dynamic.cpp -o line_editor_dynamic
./line_editor_dynamic
```
