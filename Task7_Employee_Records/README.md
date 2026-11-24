# Task 7 (Extra Practice): Employee Records (Structs & Dynamic Memory)

> **Educational Notice:** This project was created strictly for **educational purposes** as an additional C++ practice exercise alongside Lab 4 (Object-Oriented Programming).

## Description

Demonstrates defining a C++ `struct` (`employee`) and dynamically allocating an array of structs at runtime using `new[]` and freeing it with `delete[]`.

## How the Code Works

- **File:** [`employee_records.cpp`](./employee_records.cpp)
- Defines `struct employee` with fields:
  - `int id`
  - `char name[50]`
  - `float salary`
- Prompts the user for the number of employees (`numEmployees`).
- Allocates `employee *empArray = new employee[numEmployees]`.
- Reads each employee's ID, full name (`cin.getline`), and salary.
- Displays all entered employee records and releases the allocated memory with `delete[] empArray`.

## Platform Note

The file includes `<conio.h>` and `<windows.h>`, so compiling on **Windows** (e.g., MinGW / MSVC) is recommended.

## Compile & Run (Windows / MinGW)

```bash
g++ employee_records.cpp -o employee_records
./employee_records
```
