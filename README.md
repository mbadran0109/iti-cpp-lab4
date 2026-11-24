# C++ OOP Lab 4 — Arrays, Strings, Line Editor & Structs

> **Educational Notice:** This repository contains C++ lab exercises created strictly for **educational purposes** as part of an Object-Oriented Programming (C++) course (Lab 4).

## Repository Structure

| Task | Folder | Source File(s) | Description |
| :--- | :--- | :--- | :--- |
| **Task 1** | [`Task1_Monthly_Sales_Summary`](./Task1_Monthly_Sales_Summary) | [`monthly_sales_summary.cpp`](./Task1_Monthly_Sales_Summary/monthly_sales_summary.cpp) | 2D array monthly sales table (5 products x 4 salespeople) with row, column, and grand totals |
| **Task 2** | [`Task2_Turtle_Graphics`](./Task2_Turtle_Graphics) | [`turtle_graphics.cpp`](./Task2_Turtle_Graphics/turtle_graphics.cpp) | 50x50 2D array turtle graphics sketchpad supporting pen, turn, move, and print commands |
| **Task 3** | [`Task3_Student_Scores_Summary`](./Task3_Student_Scores_Summary) | [`student_scores_summary.cpp`](./Task3_Student_Scores_Summary/student_scores_summary.cpp) | 3 students x 4 subjects score table, per-student totals, and per-subject averages |
| **Task 4** | [`Task4_Case_Converter`](./Task4_Case_Converter) | [`case_converter.cpp`](./Task4_Case_Converter/case_converter.cpp) | Character array (`char s[100]`) alphabetic case converter using ASCII offsets |
| **Task 5** | [`Task5_String_To_Int_Sum_Average`](./Task5_String_To_Int_Sum_Average) | [`string_to_int_sum_average.cpp`](./Task5_String_To_Int_Sum_Average/string_to_int_sum_average.cpp) | Reads six integer strings, converts them via `std::stoi`, and computes sum & average |
| **Task 6** | [`Task6_Line_Editor`](./Task6_Line_Editor) | [`line_editor_fixed.cpp`](./Task6_Line_Editor/line_editor_fixed.cpp), [`line_editor_dynamic.cpp`](./Task6_Line_Editor/line_editor_dynamic.cpp) | Interactive Windows console line editor (fixed 10-char buffer & dynamic `struct Line` versions) |
| **Task 7 (Extra)** | [`Task7_Employee_Records`](./Task7_Employee_Records) | [`employee_records.cpp`](./Task7_Employee_Records/employee_records.cpp) | Dynamic array of `employee` structs (`new[]` / `delete[]`) practice exercise |

## Notes

- Each task folder includes its own `README.md` with problem details and compilation instructions.
- Tasks 2, 6, and 7 use Windows console APIs (`system("cls")`, `<conio.h>`, `<windows.h>`) and are intended to be compiled and run on Windows.
- Compiled `.exe` binaries are ignored via `.gitignore` so only source code and documentation are pushed to GitHub.
