#include <iostream>
#include <cctype>
using namespace std;

char s[100];

int main() {
    while (true) {
        cout << "Enter a string: ";
        cin.getline(s, 100); // Read a line of input into the string s
        if (s[0] == '\0') { // Check if the input is empty
            break; // Exit the loop if the input is empty
        }
        for (int i = 0; s[i] != '\0'; i++) {
            if (isalpha(s[i])) { // Check if the character is a letter
                if (s[i] >= 'a' && s[i] <= 'z') { // If the character is a lowercase letter
                    s[i] = s[i] - 32; // Convert to uppercase by subtracting 32 from its ASCII value
                }
                else if (s[i] >= 'A' && s[i] <= 'Z') { // If the character is an uppercase letter
                    s[i] = s[i] + 32; // Convert to lowercase by adding 32 to its ASCII value
                }
            }
            else{
                cout << "Invalid input! Please enter a string containing only letters.\n";
                break; // Exit the loop if the input contains non-letter characters
            }
        }
        break; // Exit the loop after processing the input string
    }
    cout << "Converted uppercase and lowercase: " << s << endl; // Output the modified string
    return 0;
}