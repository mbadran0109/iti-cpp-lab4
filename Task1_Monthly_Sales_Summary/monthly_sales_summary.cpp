#include <iostream>
using namespace std;

int sales[5][4] = {0}; // 5 products, 4 salespeople
int spTotals[4] = {0}; // Array to hold salesperson totals
int pTotals[5] = {0};  // Array to hold product totals
int grandTotal = 0; // Variable to hold the grand total

int main() {

    cout << "Enter sales slips information (Salesperson [1-4], Product [1-5], Dollar Value).\n";

    for (int i = 0; i<5; i++) {
        for (int j = 0; j<4; j++) {
            cout << "Enter total for product " << i + 1 << " and salesperson " << j + 1 << ": ";
            cin >> sales[i][j];
            while (sales[i][j] < 0) {
                cout << "Invalid input! Please enter a non-negative value for product " << i + 1 << " and salesperson " << j + 1 << ": ";
                cin >> sales[i][j];
            }
        }
    }

    // Nested loop to calculate both totals simultaneously
    for (int i = 0; i < 5; i++) {
        for (int j = 0; j < 4; j++) {
            pTotals[i] += sales[i][j]; // Sums across the row
            spTotals[j] += sales[i][j]; // Sums down the column
            grandTotal += sales[i][j]; // Sums all values
        }
    }
    
    cout << "\n--- Monthly Sales Summary ---\n\n";
    cout << "Product\t\tSP 1\t\tSP 2\t\tSP 3\t\tSP 4\t\tProduct Total\n";
    cout << "---------------------------------------------------------------------------------------------\n";
    cout << "Product 1\t" << sales[0][0] << "\t\t" << sales[0][1] << "\t\t" << sales[0][2] << "\t\t" << sales[0][3] << "\t\t" << pTotals[0] << endl;
    cout << "Product 2\t" << sales[1][0] << "\t\t" << sales[1][1] << "\t\t" << sales[1][2] << "\t\t" << sales[1][3] << "\t\t" << pTotals[1] << endl;
    cout << "Product 3\t" << sales[2][0] << "\t\t" << sales[2][1] << "\t\t" << sales[2][2] << "\t\t" << sales[2][3] << "\t\t" << pTotals[2] << endl;
    cout << "Product 4\t" << sales[3][0] << "\t\t" << sales[3][1] << "\t\t" << sales[3][2] << "\t\t" << sales[3][3] << "\t\t" << pTotals[3] << endl;
    cout << "Product 5\t" << sales[4][0] << "\t\t" << sales[4][1] << "\t\t" << sales[4][2] << "\t\t" << sales[4][3] << "\t\t" << pTotals[4] << endl;
    cout << "---------------------------------------------------------------------------------------------\n";
    cout << "SP Total\t" << spTotals[0] << "\t\t" << spTotals[1] << "\t\t" << spTotals[2] << "\t\t" << spTotals[3] << "\t\t" << grandTotal << endl;
    
    cin.ignore();
    cin.get(); // Wait for user input before closing
    return 0;
}
