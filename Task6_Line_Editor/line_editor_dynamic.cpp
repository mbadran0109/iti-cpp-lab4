#include <iostream>
#include <cstdlib>
#include <string>
#include <cctype>
#include <conio.h>
#include <windows.h>
using namespace std;

struct Line {
    char *str; // Pointer to buffer for up to 'nc' characters + null terminator
    int len;   // Current number of valid characters typed
    int size;  // Maximum number of elements configured by the user (nc)
};

void gotoxy(int x, int y) {
    COORD coord;
    coord.X = x;
    coord.Y = y;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
}

int main() {
    int nc = 0; // Number of characters configured by the user
    gotoxy(13, 10);
    cout << "Enter the number of characters you want to type: ";
    cin >> nc;
    Line line;
    line.str = new char[nc + 1];
    line.len = 0;
    line.size = nc;
    line.str[0] = '\0';
    gotoxy(13, 11);
    cout << "Enter string of " << line.size << " elements only letters and numbers: ";
    
    int i = 0; // Current cursor/array index position (0 to line.size)
    
    while (true) {
        // Keep the cursor positioned at the active typing index
        gotoxy(13 + i, 12);
        int ch = _getch(); // Read as int to safely catch special codes

        if (ch == 224 || ch == 0) { // Extended keys prefix
            int ext_key = _getch();
            if (ext_key == 75) { // Left arrow
                if (i > 0) {
                    i--;
                }
            }
            else if (ext_key == 77) { // Right arrow
                if (i < line.len) {
                    i++;
                }
            }
            else if (ext_key == 83) { // Delete key
                if (i < line.len) {
                    // Shift all characters to the left starting from index i
                    for (int j = i; j < line.len - 1; j++) {
                        line.str[j] = line.str[j + 1];
                    }
                    line.len--;
                    line.str[line.len] = '\0';
                    
                    // Redraw the line cleanly on the screen
                    gotoxy(13, 12);
                    cout << "\r\x1b[2K" << std::flush;
                    gotoxy(13, 12);
                    for (int k = 0; k < line.len; k++) {
                        cout << line.str[k];
                    }
                }
            }
            else if (ext_key == 71) { // Home key
                i = 0;
            }
            else if (ext_key == 79) { // End key
                i = line.len;
            }
            continue; // Skip the rest of the loop
        }
        else if (ch == 27) { // Escape key
            gotoxy(13, 13);
            cout << "\nExiting input...\n";
            return 0;
        }
        else if (ch == 13) { // Enter key
            line.str[line.len] = '\0'; // Null-terminate the string at the current length
            gotoxy(13, 13); // Move to a separate line below
            cout << "\nTyped string: " << line.str << endl;
            cout << "Press any key to exit...";
            _getch(); // Wait for user input before closing
            break; // Stop editing
        }
        else if (ch == 8) { // Backspace key
            if (i > 0) {
                // Shift all characters to the left starting from index i-1
                for (int j = i - 1; j < line.len - 1; j++) {
                    line.str[j] = line.str[j + 1];
                }
                line.len--;
                i--;
                line.str[line.len] = '\0';
                
                // Redraw the line cleanly on the screen
                gotoxy(13, 12);
                cout << "\r\x1b[2K" << std::flush; // Clear the line
                gotoxy(13, 12);
                for (int k = 0; k < line.len; k++) {
                    cout << line.str[k];
                }
            }
        }
        else if (isalnum(ch)) { // Letters and numbers only
            if (line.len < line.size) { // Check if we can add more characters
                // If we are inserting in the middle, shift characters to the right
                if (i < line.len) {
                    for (int j = line.len; j > i; j--) {
                        line.str[j] = line.str[j - 1];
                    }
                    line.len++;
                } else {
                    line.len++;
                }
                line.str[i] = ch;
                
                // Redraw the line to reflect insertion/updates
                gotoxy(13, 12);
                for (int k = 0; k < line.len; k++) {
                    cout << line.str[k];
                }
                
                if (i < line.size) {
                    i++;
                }
            }
        }
    }
    return 0;
}