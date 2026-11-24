#include <iostream>
#include <cstdlib>
#include <string>
#include <cctype>
#include <conio.h>
#include <windows.h>
using namespace std;

char s[11] = {0}; // Buffer for up to 10 characters + null terminator

void gotoxy(int x, int y) {
    COORD coord;
    coord.X = x;
    coord.Y = y;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
}

int main() {
    gotoxy(13, 11);
    cout << "Enter string of 10 elements only letters and numbers: ";
    
    int i = 0;   // Current cursor/array index position (0 to 10)
    int len = 0; // Total number of valid characters currently typed
    
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
                if (i < len) {
                    i++;
                }
            }
            else if (ext_key == 83) { // Delete key
                if (i < len) {
                    // Shift all characters to the left starting from index i
                    for (int j = i; j < len - 1; j++) {
                        s[j] = s[j + 1];
                    }
                    len--;
                    s[len] = '\0';
                    
                    // Redraw the line cleanly on the screen
                    gotoxy(13, 12);
                    cout << "          "; // Clear the 10-slot area
                    gotoxy(13, 12);
                    for (int k = 0; k < len; k++) {
                        cout << s[k];
                    }
                }
            }
            else if (ext_key == 71) { // Home key
                i = 0;
            }
            else if (ext_key == 79) { // End key
                i = len;
            }
            continue; // Skip the rest of the loop
        }
        else if (ch == 27) { // Escape key
            gotoxy(13, 13);
            cout << "\nExiting input...\n";
            return 0;
        }
        else if (ch == 13) { // Enter key
            s[len] = '\0'; // Null-terminate the string at the current length
            gotoxy(13, 13); // Move to a separate line below
            cout << "\nTyped string: " << s << endl;
            cout << "Press any key to exit...";
            _getch(); // Wait for user input before closing
            break; // Stop editing
        }
        else if (ch == 8) { // Backspace key
            if (i > 0) {
                // Shift all characters to the left starting from index i-1
                for (int j = i - 1; j < len - 1; j++) {
                    s[j] = s[j + 1];
                }
                len--;
                i--;
                s[len] = '\0';
                
                // Redraw the line cleanly on the screen
                gotoxy(13, 12);
                cout << "          "; // Clear the 10-slot area
                gotoxy(13, 12);
                for (int k = 0; k < len; k++) {
                    cout << s[k];
                }
            }
        }
        else if (isalnum(ch)) { // Letters and numbers only
            if (len < 10) {
                // If we are inserting in the middle, shift characters to the right
                if (i < len) {
                    for (int j = len; j > i; j--) {
                        s[j] = s[j - 1];
                    }
                    len++;
                } else {
                    len++;
                }
                s[i] = ch;
                
                // Redraw the line to reflect insertion/updates
                gotoxy(13, 12);
                for (int k = 0; k < len; k++) {
                    cout << s[k];
                }
                
                if (i < 10) {
                    i++;
                }
            }
        }
    }
    return 0;
}