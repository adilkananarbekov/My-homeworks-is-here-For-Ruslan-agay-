#include <iostream>
#include <string>
#include <cmath>

using namespace std;

bool isBinary(const string& number) {
    for (char c : number) {
        if (c != '0' and c != '1') {
            return false;
        }
    }
    return true;
}

int binaryToDecimal(const string binary) {
    int decimal = 0;
    int power = 0;

    for (int i = binary.length() - 1; i >= 0; i--) {
        if (binary[i] == '1') {
            decimal += pow(2, power);
        }
        ++power;
    }

    return decimal;
}

string decimalToBinary(int decimal) {
    string binary = "";

    while (decimal > 0) {
        if (decimal % 2 == 0) {
    		binary = "0" + binary;
		}	
		else {
    		binary = "1" + binary;
		}

        decimal /= 2;
    }

    if (binary.empty()) {
    return "0";
} else {
    return binary;
}
}

void identifyAndConvert(const string& number) {
    bool binary = isBinary(number);

    try {
        int decimalValue = stoi(number);
        bool decimal = true;

        if (binary) {
            int binaryToDec = binaryToDecimal(number);
            cout << "Binary number: " << number << " -> Decimal: " << binaryToDec << endl;
        }

        string decimalToBin = decimalToBinary(decimalValue);
        cout << "Decimal number: " << number << " -> Binary: " << decimalToBin << endl;

        if (binary) {
            cout << "The number " << number << " can be both binary and decimal." << endl;
        }

    } catch (invalid_argument& e) {
        if (binary) {
            int binaryToDec = binaryToDecimal(number);
            cout << "Binary number: " << number << " -> Decimal: " << binaryToDec << endl;
        } else {
            cout << "The number " << number << " is not a valid binary or decimal number." << endl;
        }
    }
}

int main() {
    string n;
    cin >> n;
    identifyAndConvert(n);
    cout << endl;
}
