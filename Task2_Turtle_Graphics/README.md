# Task 2: Turtle Graphics Sketchpad (50x50 2D Array)

> **Educational Notice:** This project was created strictly for **educational purposes** as part of a C++ Object-Oriented Programming lab assignment (Lab 4).

## Problem Description

Simulate a mechanical turtle that walks around a room represented by a `50 x 50` 2D array (`TFloor`) initialized to zeros:
- The turtle starts at position `(0, 0)` with its pen **up**.
- While the pen is **down**, the turtle marks visited positions on the floor with `1`.
- While the pen is **up**, the turtle moves freely without marking the floor.
- Printing the floor displays `*` for every `1` and a blank space for every `0`.

### Supported Commands

| Command | Meaning |
| :---: | :--- |
| `1` | Pen up |
| `2` | Pen down |
| `3` | Turn right |
| `4` | Turn left |
| `5` | Move forward `x` spaces (prompts for number of steps) |
| `6` | Clear console and print the `50 x 50` floor |
| `9` | End of data (exit program) |

## How the Code Works

- **File:** [`turtle_graphics.cpp`](./turtle_graphics.cpp)
- Maintains global state for the `50 x 50` floor grid (`TFloor`), current coordinates (`currentRow`, `currentCol`), `penState`, and `direction` (`0` = Up, `1` = Right, `2` = Down, `3` = Left).
- `moveTurtle(int steps)` marks cells when `penState == 2` and moves step-by-step within the grid bounds (`0` to `49`).
- `printFloor()` renders the `50 x 50` grid to the console using `*` and spaces.
- Note: Uses `system("cls")` to clear the screen on Windows consoles.

## Compile & Run

```bash
g++ turtle_graphics.cpp -o turtle_graphics
./turtle_graphics
```
