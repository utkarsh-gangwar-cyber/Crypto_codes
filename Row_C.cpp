#include <iostream>
#include <string>
using namespace std;

int main() {
    string text, key, clean = "", cipher = "";

    cout << "Enter plaintext: ";
    getline(cin, text);
    cout << "Enter numeric key: ";
    cin >> key;

    int cols = key.length();

    // Remove spaces
    for (char c : text)
        if (c != ' ') clean += c;

    // Validate key (must contain 1..cols)
    for (int i = 1; i <= cols; i++) {
        if (key.find('0' + i) == string::npos) {
            cout << "Invalid key!";
            return 0;
        }
    }

    // Padding
    while (clean.length() % cols != 0)
        clean += 'x';

    // Encryption: read columns in key order
    for (int k = 1; k <= cols; k++) {
        int col = key.find('0' + k);
        for (int i = col; i < clean.length(); i += cols)
            cipher += clean[i];
    }

    cout << "Ciphertext: " << cipher << endl;
    return 0;
}