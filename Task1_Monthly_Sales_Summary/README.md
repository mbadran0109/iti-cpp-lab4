# Task 1: Monthly Sales Summary (2D Array)

> **Educational Notice:** This project was created strictly for **educational purposes** as part of a C++ Object-Oriented Programming lab assignment (Lab 4).

## Problem Description

A company has **4 salespeople** (1 to 4) who sell **5 different products** (1 to 5). Using a two-dimensional array (`sales[5][4]`):
- Read last month's sales data for each product and salesperson.
- Summarize total sales by salesperson and by product.
- Print the results in a tabular format where each row represents a product and each column represents a salesperson.
- Cross-total each row to display the total sales per product on the right.
- Cross-total each column to display the total sales per salesperson at the bottom, along with the grand total.

## How the Code Works

- **File:** [`monthly_sales_summary.cpp`](./monthly_sales_summary.cpp)
- Stores sales in a `5 x 4` integer array (`sales[5][4]`), validating that each entered value is non-negative.
- Uses nested loops to compute:
  - `pTotals[5]`: row totals (total sales per product)
  - `spTotals[4]`: column totals (total sales per salesperson)
  - `grandTotal`: overall sum of all sales
- Prints a formatted monthly summary table with row totals, column totals, and the grand total.

## Compile & Run

```bash
g++ monthly_sales_summary.cpp -o monthly_sales_summary
./monthly_sales_summary
```
