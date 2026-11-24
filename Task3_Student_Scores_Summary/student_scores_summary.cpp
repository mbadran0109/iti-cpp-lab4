#include <iostream>
using namespace std;

int students [3][4] = {0}; // 3 students, 4 subjects
int totalScores[3] = {0}; // Array to hold total scores for each student
int subjectaverage[4] = {0}; // Array to hold average scores for each subject
int main() {
    cout << "Enter the scores for 3 students in 4 subjects:\n";
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 4; j++) {
            cout << "Student " << i + 1 << ", Subject " << j + 1 << ": ";
            cin >> students[i][j];
        }
    }

    cout << "\nScores entered:\n";
    cout << "Student\t\tSubject 1\tSubject 2\tSubject 3\tSubject 4\n";
    for (int i = 0; i < 3; i++) {
        cout << "Student " << i + 1 << ":\t";
        for (int j = 0; j < 4; j++) {
            cout << students[i][j] << "\t\t   ";
            totalScores[i] += students[i][j]; // Calculate total score for each student
            subjectaverage[j] += students[i][j]; // Calculate total score for each subject
        }
        cout << endl;
    }

    cout << "\nTotal scores:\n";
    for (int i = 0; i < 3; i++) {
        cout << "Student " << i + 1 << ": " << totalScores[i] << endl;
    }

    cout << "\nSubject averages:\n";
    for (int j = 0; j < 4; j++) {
        cout << "Subject " << j + 1 << ": " << int(subjectaverage[j]) / 3 << endl;
    }

    return 0;
}