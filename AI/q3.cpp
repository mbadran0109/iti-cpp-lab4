#include <iostream>
using namespace std;

int main() {
    const int STUDENTS = 3;
    const int SUBJECTS = 4;

    double grades[STUDENTS][SUBJECTS];
    double studentSum[STUDENTS] = {0.0};
    double subjectSum[SUBJECTS] = {0.0};

    // Input grades for each student
    for (int i = 0; i < STUDENTS; i++) {
        cout << "Enter grades for Student " << (i + 1) << ":\n";
        for (int j = 0; j < SUBJECTS; j++) {
            cout << "  Subject " << (j + 1) << ": ";
            cin >> grades[i][j];
            studentSum[i] += grades[i][j];
            subjectSum[j] += grades[i][j];
        }
        cout << endl;
    }

    // 1. Sum of each student & find Student Ranked 1st
    int firstRankIndex = 0;
    cout << "--- Sum of Each Student ---\n";
    for (int i = 0; i < STUDENTS; i++) {
        cout << "Student " << (i + 1) << " Total Sum = " << studentSum[i] << endl;
        if (studentSum[i] > studentSum[firstRankIndex]) {
            firstRankIndex = i;
        }
    }

    // 2. Average of each subject
    cout << "\n--- Average of Each Subject ---\n";
    for (int j = 0; j < SUBJECTS; j++) {
        double avg = subjectSum[j] / STUDENTS;
        cout << "Subject " << (j + 1) << " Average = " << avg << endl;
    }

    // 3. Student Ranked 1st in the class
    cout << "\n--- Top Ranked Student ---\n";
    cout << "Student Ranked 1st in the class is Student " << (firstRankIndex + 1)
         << " with a total score of " << studentSum[firstRankIndex] << endl;

    return 0;
}
