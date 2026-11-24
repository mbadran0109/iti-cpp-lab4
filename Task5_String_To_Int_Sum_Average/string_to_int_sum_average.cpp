#include <iostream>
#include <string>
using namespace std;

string s1, s2, s3, s4, s5, s6;

int main() {
    cout << "Enter first integer: ";
    cin >> s1; // Read a line of input into the string s1
    cout << "Enter second integer: ";
    cin >> s2; // Read a line of input into the string s2
    cout << "Enter third integer: ";
    cin >> s3; // Read a line of input into the string s3
    cout << "Enter fourth integer: ";
    cin >> s4; // Read a line of input into the string s4
    cout << "Enter fifth integer: ";
    cin >> s5; // Read a line of input into the string s5
    cout << "Enter sixth integer: ";
    cin >> s6; // Read a line of input into the string s6

    int num1 = stoi(s1); // Convert string to integer
    int num2 = stoi(s2); // Convert string to integer
    int num3 = stoi(s3); // Convert string to integer
    int num4 = stoi(s4); // Convert string to integer
    int num5 = stoi(s5); // Convert string to integer
    int num6 = stoi(s6); // Convert string to integer

    cout << "The sum of the six integers is: " << (num1 + num2 + num3 + num4 + num5 + num6) << endl; // Output the sum
    cout << "The average of the six integers is: " << (num1 + num2 + num3 + num4 + num5 + num6) / 6.0 << endl; // Output the average
    return 0;
}