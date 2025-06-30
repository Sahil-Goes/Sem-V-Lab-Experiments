#include <iostream>
using namespace std;

void crcrcode(int cw[], int g[], int n, int k) {
    int tmp[100];  // Temporary copy of codeword
    int rem[50];   // To store remainder
    int i, j, l;

    // Copy cw into tmp
    for (i = 0; i < n; i++) {
        tmp[i] = cw[i];
    }

    // Perform division
    for (i = 0; i < n - k + 1; i++) {
        if (tmp[i] == 1) {
            for (j = 0; j < k; j++) {
                tmp[i + j] = tmp[i + j] ^ g[j];  // XOR with generator polynomial
            }
        }
    }

    // Extract remainder (last k-1 bits)
    int flag = 0;
    cout << "Remainder: ";
    for (i = n - k + 1; i < n; i++) {
        cout << tmp[i];
        rem[i - (n - k + 1)] = tmp[i];
        if (tmp[i] != 0) {
            flag = 1;
        }
    }
    cout << endl;

    if (flag == 0) {
        cout << "No error detected in codeword." << endl;
    } else {
        cout << "Error detected in codeword!" << endl;
    }
}

int main() {
    int n, k;
    int cw[100], g[50];  // Predefined sizes

    cout << "Enter number of bits in received codeword: ";
    cin >> n;
    cout << "Enter number of bits in G(x): ";
    cin >> k;

    cout << "Enter received codeword:\n";
    for (int i = 0; i < n; i++) {
        cin >> cw[i];
    }

    cout << "Enter G(x):\n";
    for (int i = 0; i < k; i++) {
        cin >> g[i];
    }

    crcrcode(cw, g, n, k);

    return 0;
}
