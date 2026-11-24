# Task 3: Student Scores Summary (3 Students x 4 Subjects)

> **Educational Notice:** This project was created strictly for **educational purposes** as part of a C++ Object-Oriented Programming lab assignment (Lab 4).

## Problem Description

A class contains **3 students**, each studying **4 subjects**. The lab requirements are:
- Calculate the **sum** of scores for each student.
- Calculate the **average** score for each subject.
- Determine the student ranked 1st in the class.

## How the Code Works

- **File:** [`student_scores_summary.cpp`](./student_scores_summary.cpp)
- Reads scores for 3 students across 4 subjects into a 2D array `students[3][4]`.
- Prints the entered scores in a tabular format.
- Computes and displays:
  - Total score for each student (`totalScores[3]`).
  - Average score for each subject (`subjectaverage[4] / 3`).

## Compile & Run

```bash
g++ student_scores_summary.cpp -o student_scores_summary
./student_scores_summary
```
