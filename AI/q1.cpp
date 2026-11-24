#include <iostream>
using namespace std;

int main() {
    const int PRODUCTS = 5;
    const int SALESPEOPLE = 4;
    double sales[PRODUCTS][SALESPEOPLE] = {0.0};

    int salesperson, product;
    double value;

    cout << "Enter sales slips information (Salesperson [1-4], Product [1-5], Dollar Value).\n";
    cout << "Enter -1 for salesperson number to end input.\n\n";

    while (true) {
        cout << "Enter salesperson number (1-4, or -1 to finish): ";
        cin >> salesperson;

        if (salesperson == -1) {
            break;
        }

        cout << "Enter product number (1-5): ";
        cin >> product;

        cout << "Enter total dollar value sold: ";
        cin >> value;

        if (salesperson >= 1 && salesperson <= SALESPEOPLE &&
            product >= 1 && product <= PRODUCTS && value >= 0) {
            sales[product - 1][salesperson - 1] += value;
        } else {
            cout << "Invalid input! Please enter valid salesperson (1-4), product (1-5), and non-negative value.\n";
        }
        cout << endl;
    }

    cout << "\n--- Monthly Sales Summary ---\n\n";
    cout << "Product\t\tSP 1\t\tSP 2\t\tSP 3\t\tSP 4\t\tProduct Total\n";
    cout << "---------------------------------------------------------------------------------------------\n";

    double salespersonTotals[SALESPEOPLE] = {0.0};
    double grandTotal = 0.0;

    for (int i = 0; i < PRODUCTS; i++) {
        double productTotal = 0.0;
        cout << "Product " << (i + 1) << "\t";

        for (int j = 0; j < SALESPEOPLE; j++) {
            cout << sales[i][j] << "\t\t";
            productTotal += sales[i][j];
            salespersonTotals[j] += sales[i][j];
        }

        grandTotal += productTotal;
        cout << productTotal << endl;
    }

    cout << "---------------------------------------------------------------------------------------------\n";
    cout << "SP Total\t";
    for (int j = 0; j < SALESPEOPLE; j++) {
        cout << salespersonTotals[j] << "\t\t";
    }
    cout << grandTotal << endl;

    return 0;
}
