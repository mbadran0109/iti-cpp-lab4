#include <iostream>
#include <conio.h>
#include <windows.h>
using namespace std;

void gotoxy(int x, int y) {
    COORD coord;
    coord.X = x;
    coord.Y = y;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
}

void redrawLine(char *line, int length, int startX, int startY, int maxLen) {
    gotoxy(startX, startY);
    for (int i = 0; i < maxLen; i++) {
        if (i < length) {
            cout << *(line + i);
        } else {
            cout << " ";
        }
    }
}

int main() {
    const int MAX_LEN = 50;
    char line[MAX_LEN + 1] = {0};

    int startX = 10;
    int startY = 5;
    int cursor = 0; // Current cursor index (0 to length)
    int length = 0; // Current number of characters in line

    system("cls");
    gotoxy(startX, startY - 2);
    cout << "--- Line Editor (Arrows, Home, End, Backspace, Delete, Enter to submit, Esc to exit) ---";

    // Draw visual boundaries for the editor line
    gotoxy(startX - 1, startY);
    cout << "[";
    gotoxy(startX + MAX_LEN, startY);
    cout << "]";

    gotoxy(startX, startY);

    bool running = true;
    bool submitted = false;

    while (running) {
        int key = _getch();

        // 1. Extended Keys (Arrows, Home, End, Delete)
        if (key == 224 || key == 0) {
            int ext = _getch();

            switch (ext) {
                case 75: // Left Arrow
                    if (cursor > 0) {
                        cursor--;
                    }
                    break;

                case 77: // Right Arrow
                    if (cursor < length) {
                        cursor++;
                    }
                    break;

                case 71: // Home
                    cursor = 0;
                    break;

                case 79: // End
                    cursor = length;
                    break;

                case 83: // Delete (deletes character at current cursor position)
                    if (cursor < length) {
                        for (int i = cursor; i < length - 1; i++) {
                            *(line + i) = *(line + i + 1);
                        }
                        length--;
                        *(line + length) = '\0';
                        redrawLine(line, length, startX, startY, MAX_LEN);
                    }
                    break;
            }
        }
        // 2. Normal Keys
        else if (key == 13) { // Enter
            *(line + length) = '\0';
            submitted = true;
            running = false;
        }
        else if (key == 27) { // Esc
            running = false;
        }
        else if (key == 8) { // Backspace
            if (cursor > 0) {
                for (int i = cursor - 1; i < length - 1; i++) {
                    *(line + i) = *(line + i + 1);
                }
                cursor--;
                length--;
                *(line + length) = '\0';
                redrawLine(line, length, startX, startY, MAX_LEN);
            }
        }
        else if (key >= 32 && key <= 126) { // Printable ASCII characters
            if (length < MAX_LEN) {
                // Shift characters to the right to insert at cursor position
                for (int i = length; i > cursor; i--) {
                    *(line + i) = *(line + i - 1);
                }
                *(line + cursor) = (char)key;
                cursor++;
                length++;
                *(line + length) = '\0';
                redrawLine(line, length, startX, startY, MAX_LEN);
            }
        }

        // Update console cursor position
        gotoxy(startX + cursor, startY);
    }

    gotoxy(0, startY + 3);
    if (submitted) {
        cout << "Final Edited Text: " << line << endl;
    } else {
        cout << "Editing cancelled." << endl;
    }

    return 0;
}
