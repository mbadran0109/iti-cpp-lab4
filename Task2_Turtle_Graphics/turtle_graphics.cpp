#include <iostream>
#include <cstdlib> // for system("cls") to clear the screen
using namespace std;

int TFloor[50][50] = {0}; // turtle floor with 50 rows and 50 columns
int penState = 1; // 1 for pen up, 2 for pen down
int currentRow = 0; // current row position of the turtle
int currentCol = 0; // current column position of the turtle
int direction = 0; // 3 turn right, 4 turn left
int steps = 0; // number of steps to move forward
void printFloor() {
    for (int i = 0; i < 50; i++) {
        for (int j = 0; j < 50; j++) {
            if (TFloor[i][j]) {
                cout << '*';
            } else {
                cout << ' ';
            }
        }
        cout << endl;
    }
}
void moveTurtle(int steps) {
    for (int i = 0; i < steps; i++) {
        if (penState == 2) {
            TFloor[currentRow][currentCol] = 1; // Mark the floor
        }
        // Move the turtle based on the current direction
        if (direction == 0 && currentRow > 0) { // Up
            currentRow--;
        } else if (direction == 1 && currentCol < 49) { // Right
            currentCol++;
        } else if (direction == 2 && currentRow < 49) { // Down
            currentRow++;
        } else if (direction == 3 && currentCol > 0) { // Left
            currentCol--;
        }
    }
}
int main() {
    cout << "Enter commands for the turtle (1-5, 6 to end):\n";
    cout << "1: Pen up\n";
    cout << "2: Pen down\n";
    cout << "3: Turn right\n";
    cout << "4: Turn left\n";
    cout << "5: Move forward x spaces (enter x after 5)\n";
    cout << "6: print the floor\n";
    cout << "9: End of data\n";
    while (true) {
        int command;
        cout << "Current position: (" << currentRow << ", " << currentCol << ")" << endl;
        cout << "pen state: " << (penState == 1 ? "Up" : "Down") << ", Direction: " ;
        cout << "Enter command: ";
        cin >> command;
        if (command == 1) {
            cout << "Pen up\n";
            penState = 1; // Pen up
        } else if (command == 2) {
            cout << "Pen down\n";
            penState = 2; // Pen down
        } else if (command == 3) {
            cout << "Turn right\n";
            direction = (direction + 1) % 4; // Turn right
        } else if (command == 4) {
            cout << "Turn left\n";
            direction = (direction + 3) % 4; // Turn left
        } else if (command == 5) {
            cout << "Move forward\n for how many steps? ";
            cin >> steps;
            moveTurtle(steps);
            cout << "Moved forward " << steps << " steps\n";
        } else if (command == 6) {
            system("cls"); // Clear the screen
            printFloor();
        } else if (command == 9) {
            break; // End of data
        } else {
            cout << "Invalid command! Please enter a valid command.\n";
        }
        
    }
    cin.ignore();
    cin.get(); // Wait for user input before closing
    return 0;
}