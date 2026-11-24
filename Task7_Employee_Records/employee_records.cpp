#include <iostream>
#include <cstdlib>
#include <string>
#include <cctype>
#include <conio.h>
#include <windows.h>
using namespace std;

struct employee {
    int id;
    char name[50];
    float salary;
};

int main() {
    // multiple employees input method
    // cout << " enter number of employees: ";
    // int n;
    // cin >> n;
    // cin.ignore(); // Clear the newline character from the input buffer
    // employee *employees = new employee[n]; // Dynamically allocate an array of employees
    // for (int i = 0; i < n; ++i) {
    //     cout << "Enter details for employee " << (i + 1) << ":\n";
    //     cout << "enter employee id: ";
    //     cin >> employees[i].id;
    //     cin.ignore(); // Clear the newline character from the input buffer
    //     cout << "enter employee name: ";
    //     cin.getline(employees[i].name, 50);
    //     cout << "enter employee salary: ";
    //     cin >> employees[i].salary;
    //     cin.ignore(); // Clear the newline character from the input buffer
    // }
    // cout << "\nEmployee details:\n";
    // for (int i = 0; i < n; ++i) {
    //     cout << "Employee " << (i + 1) << ":\n";
    //     cout << "ID: " << employees[i].id << endl;
    //     cout << "Name: " << employees[i].name << endl;
    //     cout << "Salary: " << employees[i].salary << endl;
    // }
    // delete[] employees; // Free the dynamically allocated memory


    // multiple employees input method
    cout << "enter number of employees: ";
    int numEmployees;
    cin >> numEmployees;
    cin.ignore(); // Clear the newline character from the input buffer
    employee *empArray = new employee[numEmployees]; // Dynamically allocate an array of employees
    for (int i = 0; i < numEmployees; ++i) {
        cout << "Enter details for employee " << (i + 1) << ":\n";
        cout << "enter employee id: ";
        cin >> empArray[i].id;
        cin.ignore(); // Clear the newline character from the input buffer
        cout << "enter employee name: ";
        cin.getline(empArray[i].name, 50);
        cout << "enter employee salary: ";
        cin >> empArray[i].salary;
        cin.ignore(); // Clear the newline character from the input buffer
    }
    cout << "\nEmployee details:\n";
    for (int i = 0; i < numEmployees; ++i) {
        cout << "Employee " << (i + 1) << ":\n";
        cout << "ID: " << empArray[i].id << endl;
        cout << "Name: " << empArray[i].name << endl;
        cout << "Salary: " << empArray[i].salary << endl;
    }
    delete[] empArray; // Free the dynamically allocated memory
    
    // Single employee input
    // cout << "enter employee id: ";
    // int id;
    // cin >> id;
    // cin.ignore(); // Clear the newline character from the input buffer
    // cout << "enter employee name: ";
    // char name[50];
    // cin.getline(name, 50);
    // cout << "enter employee salary: ";
    // float salary;
    // cin >> salary;
    // cin.ignore(); // Clear the newline character from the input buffer
    // employee emp;
    // emp.id = id;
    // strcpy(emp.name, name);
    // emp.salary = salary;
    // cout << "Employee details:\n";
    // cout << "ID: " << emp.id << endl;
    // cout << "Name: " << emp.name << endl;
    // cout << "Salary: " << emp.salary << endl;
    // cin.ignore(); // Wait for user input before closing
    // return 0;
}