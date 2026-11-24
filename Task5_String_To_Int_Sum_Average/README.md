# Task 5: String-to-Integer Sum and Average

> **Educational Notice:** This project was created strictly for **educational purposes** as part of a C++ Object-Oriented Programming lab assignment (Lab 4).

## Problem Description

Write a program that inputs **six strings** representing integers, converts the strings to integers, and calculates the **sum** and **average** of the six values.

## How the Code Works

- **File:** [`string_to_int_sum_average.cpp`](./string_to_int_sum_average.cpp)
- Reads six integer values as `std::string` variables (`s1` through `s6`).
- Converts each string to an `int` using `std::stoi()`.
- Computes and prints:
  - The total sum of the six integers.
  - The floating-point average (dividing by `6.0`).

## Compile & Run

```bash
g++ string_to_int_sum_average.cpp -o string_to_int_sum_average
./string_to_int_sum_average
```
