#include <iostream>
using namespace std;

int main() {
    char s[100];

    cout << "Enter a line of text: ";
    cin.getline(s, 100);

    int makeUpper = 1;
    for (int i = 0; s[i] != '\0'; i++) {
        if ((s[i] >= 'a' && s[i] <= 'z') || (s[i] >= 'A' && s[i] <= 'Z')) {
            if (makeUpper == 1) {
                if (s[i] >= 'a' && s[i] <= 'z') {
                    s[i] = s[i] - ('a' - 'A');
                }
                makeUpper = 0;
            } else {
                if (s[i] >= 'A' && s[i] <= 'Z') {
                    s[i] = s[i] + ('a' - 'A');
                }
                makeUpper = 1;
            }
        }
    }

    cout << "Alternating uppercase and lowercase: " << s << endl;

    return 0;
}
