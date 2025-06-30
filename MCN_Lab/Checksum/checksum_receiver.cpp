#include <iostream>
#include <string>
using namespace std;

string onesComplement(string bin) {
    for (int i = 0; i < bin.length(); i++) {
        bin[i] = (bin[i] == '0') ? '1' : '0';
    }
    return bin;
}

// Function to add two binary strings of equal length with carry wrap
string binaryAddition(string a, string b) {
    int len = a.length();
    string result = "";
    int carry = 0;

    for (int i = len - 1; i >= 0; i--) {
        int sum = (a[i] - '0') + (b[i] - '0') + carry;
        result = char((sum % 2) + '0') + result;
        carry = sum / 2;
    }

    // If carry remains, wrap it around
    if (carry == 1) {
        string wrap = string(len - 1, '0') + "1";
        return binaryAddition(result, wrap);
    }

    return result;
}

// Function to verify checksum
bool verifyChecksum(string codeword, int segmentSize) {
    string sum = codeword.substr(0, segmentSize);

    for (int i = segmentSize; i < codeword.length(); i += segmentSize) {
        string segment = codeword.substr(i, segmentSize);
        sum = binaryAddition(sum, segment);
    }

    // Final result should be all 0s if no error
    string result = onesComplement(sum);
    cout << "Sum after adding all segments: " << sum << endl;
    cout << "Final result (one's complement): " << result << endl;

    for (char bit : result) {
        if (bit != '0') return false;
    }
    return true;
}

int main() {
    string codeword;
    int segmentSize;

    cout << "Enter received codeword (data + checksum): ";
    cin >> codeword;

    // To check if segment size is valid
    do {
        cout << "Enter segment size: ";
        cin >> segmentSize;
        if (codeword.length() % segmentSize != 0) {
            cout << "Segment size must divide codeword length. Try again.\n";
        }
    } while (codeword.length() % segmentSize != 0);

    bool isValid = verifyChecksum(codeword, segmentSize);

    if (isValid) {
        cout << "No error detected in codeword." << endl;
    } else {
        cout << "Error detected in codeword!" << endl;
    }

    return 0;
}
