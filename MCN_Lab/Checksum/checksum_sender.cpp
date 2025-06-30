#include <iostream>
#include <string>
using namespace std;

// Function to compute 1's complement
string onesComplement(string bin) {
    for (int i = 0; i < bin.length(); i++) {
        bin[i] = (bin[i] == '0') ? '1' : '0';
    }
    return bin;
}

// Function to add two binary strings of equal length (wrap carry if needed)
string binaryAddition(string a, string b) {
    int len = a.length();
    string result = "";
    int carry = 0;

    for (int i = len - 1; i >= 0; i--) {
        int sum = (a[i] - '0') + (b[i] - '0') + carry;
        result = char((sum % 2) + '0') + result;
        carry = sum / 2;
    }

    // If carry remains, wrap it around by adding to LSB
    if (carry == 1) {
        string wrap = string(len - 1, '0') + "1";
        return binaryAddition(result, wrap);
    }

    return result;
}

// Compute the checksum for the given data and segment size
string calculateChecksum(string data, int segmentSize) {
    string sum = data.substr(0, segmentSize);

    for (int i = segmentSize; i < data.length(); i += segmentSize) {
        string segment = data.substr(i, segmentSize);
        sum = binaryAddition(sum, segment);
    }

    return onesComplement(sum);
}

int main() {
    string data;
    int segmentSize;

    cout << "Enter binary data: ";
    cin >> data;

    // To check if segment size is valid
    do {
        cout << "Enter segment size: ";
        cin >> segmentSize;
        if (data.length() % segmentSize != 0) {
            cout << "Segment size must divide data length. Try again.\n";
        }
    } while (data.length() % segmentSize != 0);

    string checksum = calculateChecksum(data, segmentSize);
    string codeword = data + checksum;

    cout << "Checksum: " << checksum << endl;
    cout << "Codeword: " << codeword << endl;

    return 0;
}
