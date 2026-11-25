
#include <iostream>
#include <string>
using namespace std;

int main() {
    string text, rail1 = "", rail2 = "", cipher = "";

    cout << "Enter plaintext: ";
    getline(cin, text);

    // Put characters in two rails
    for (int i = 0; i < text.length(); i++) {
        if (i % 2 == 0)
            rail1 += text[i];
        else
            rail2 += text[i];
    }

    // Combine both rails
    cipher = rail1 + rail2;

    cout << "Ciphertext: " << cipher << endl;

    return 0;
}
