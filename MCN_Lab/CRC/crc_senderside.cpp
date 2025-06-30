#include <iostream>
using namespace std;

void computeCRC(int data[], int g[], int m, int k) {
    int n = m + k - 1;
    int remainder[100];  // Make sure the size is large enough

    // Copy original data into remainder
    for (int i = 0; i < n; ++i) {
        remainder[i] = data[i];
    }

    // Perform CRC division
    for (int i = 0; i < m; ++i) {
        if (remainder[i] == 1) {
            for (int j = 0; j < k; ++j) {
                remainder[i + j] ^= g[j];  // XOR with generator polynomial
            }
        }
    }

    // Append CRC (remainder) to original data
    cout << "CRC code: ";
    for (int i = m; i < n; ++i) {
        data[i] = remainder[i];  // Store CRC bits in data array
        cout << remainder[i];
    }
    cout << endl;
}

int main() {
    int m, k;
    int data[100];  // Predefined size
    int g[50];      // Generator polynomial

    cout << "Enter number of bits in data: ";
    cin >> m;
    cout << "Enter number of bits in G(x): ";
    cin >> k;

    int n = m + k - 1;

    // Initialize all data bits to 0
    for (int i = 0; i < n; ++i) {
        data[i] = 0;
    }

    cout << "Enter data bits:\n";
    for (int i = 0; i < m; ++i) {
        cin >> data[i];
    }

    cout << "Enter G(x):\n";
    for (int i = 0; i < k; ++i) {
        cin >> g[i];
    }

    cout << "Data entered: ";
    for (int i = 0; i < m; ++i) {
        cout << data[i];
    }
    cout << "\nG(x) entered: ";
    for (int i = 0; i < k; ++i) {
        cout << g[i];
    }
    cout << endl;

    computeCRC(data, g, m, k);

    cout << "Final codeword: ";
    for (int i = 0; i < n; ++i) {
        cout << data[i] << " ";
    }
    cout << endl;

    return 0;
}
