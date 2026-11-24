#include <iostream>
#include <cstdlib>
using namespace std;

int stringToInt(char str[]) {
    int result = 0;
    int sign = 1;
    int i = 0;

    if (str[0] == '-') {
        sign = -1;
        i = 1;
    } else if (str[0] == '+') {
        i = 1;
    }

    while (str[i] != '\0') {
        if (str[i] >= '0' && str[i] <= '9') {
            result = result * 10 + (str[i] - '0');
        }
        i++;
    }

    return result * sign;
}

int main() {
    const int COUNT = 6;
    char str[COUNT][20];
    int sum = 0;

    cout << "Enter 6 strings that represent integers:\n";
    for (int i = 0; i < COUNT; i++) {
        cout << "String " << (i + 1) << ": ";
        cin >> str[i];

        int value = stringToInt(str[i]);
        sum += value;
    }

    double average = (double)sum / COUNT;

    cout << "\nSum of the six values = " << sum << endl;
    cout << "Average of the six values = " << average << endl;

    return 0;
}
