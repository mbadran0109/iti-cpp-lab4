#include <iostream>
using namespace std;

const int SIZE = 50;

void printFloor(int floor[SIZE][SIZE]) {
    for (int r = 0; r < SIZE; r++) {
        for (int c = 0; c < SIZE; c++) {
            if (floor[r][c] == 1) {
                cout << "*";
            } else {
                cout << " ";
            }
        }
        cout << endl;
    }
}

void moveTurtle(int floor[SIZE][SIZE], int *row, int *col, int dir, int steps, int penDown) {
    for (int s = 0; s < steps; s++) {
        if (penDown == 1) {
            floor[*row][*col] = 1;
        }

        // Direction: 0 = Right, 1 = Down, 2 = Left, 3 = Up
        if (dir == 0 && *col + 1 < SIZE) {
            (*col)++;
        } else if (dir == 1 && *row + 1 < SIZE) {
            (*row)++;
        } else if (dir == 2 && *col - 1 >= 0) {
            (*col)--;
        } else if (dir == 3 && *row - 1 >= 0) {
            (*row)--;
        }

        if (penDown == 1) {
            floor[*row][*col] = 1;
        }
    }
}

int main() {
    int floor[SIZE][SIZE] = {0};

    // Sample command array from the lab manual to draw a 12-by-12 square
    int commands[100] = {
        2,
        5, 12,
        3,
        5, 12,
        3,
        5, 12,
        3,
        5, 12,
        1,
        6,
        9
    };

    int choice;
    cout << "1. Run sample turtle program (12-by-12 square)\n";
    cout << "2. Enter custom turtle commands into the command array\n";
    cout << "Enter your choice (1 or 2): ";
    cin >> choice;

    if (choice == 2) {
        cout << "\nCommands:\n";
        cout << "1: Pen up | 2: Pen down | 3: Turn right | 4: Turn left\n";
        cout << "5: Move forward (followed by steps) | 6: Print floor | 9: End of data\n\n";
        int idx = 0;
        while (idx < 99) {
            int cmd;
            cout << "Enter command: ";
            cin >> cmd;
            commands[idx++] = cmd;
            if (cmd == 9) {
                break;
            }
            if (cmd == 5) {
                int steps;
                cout << "Enter number of spaces to move: ";
                cin >> steps;
                commands[idx++] = steps;
            }
        }
    }

    int row = 0, col = 0;
    int penDown = 0; // 0 = Pen Up, 1 = Pen Down
    int dir = 0;     // 0 = Right, 1 = Down, 2 = Left, 3 = Up

    int i = 0;
    while (commands[i] != 9) {
        int cmd = commands[i];

        switch (cmd) {
            case 1:
                penDown = 0;
                break;
            case 2:
                penDown = 1;
                floor[row][col] = 1;
                break;
            case 3:
                dir = (dir + 1) % 4;
                break;
            case 4:
                dir = (dir + 3) % 4;
                break;
            case 5: {
                i++;
                int steps = commands[i];
                moveTurtle(floor, &row, &col, dir, steps, penDown);
                break;
            }
            case 6:
                cout << "\n--- Turtle Sketchpad ---\n";
                printFloor(floor);
                break;
            default:
                cout << "Unknown command: " << cmd << endl;
                break;
        }
        i++;
    }

    return 0;
}
