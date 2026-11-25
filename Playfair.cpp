#include <iostream>
#include <string>
using namespace std;

int main() {
    string key, plaintext, matrix = "";

    cout << "Enter key: ";
    cin >> key;

    cout << "Enter plaintext: ";
    cin >> plaintext;

    key += "ABCDEFGHIKLMNOPQRSTUVWXYZ";

    for (char c : key) {
        if (c == 'J') c = 'I';

        if (matrix.find(c) == string::npos)
            matrix += c;
    }

    cout << "\nPlayfair Matrix:\n";

    for (int i = 0; i < 25; i++) {
        cout << matrix[i] << " ";
        if ((i + 1) % 5 == 0)
            cout << endl;
    }

    return 0;
}







/*
#include <iostream>
#include <string>
using namespace std;

int main()
{
    string key, plaintext, s = "";
    char matrix[5][5];

    cout << "Enter key: ";
    cin >> key;

    cout << "Enter plaintext: ";
    cin >> plaintext;

    // Key + Alphabet
    key += "ABCDEFGHIKLMNOPQRSTUVWXYZ";

    // Remove duplicates
    for(char c : key)
    {
        if(c == 'J')
            c = 'I';

        if(s.find(c) == string::npos)
            s += c;
    }

    // Fill 5x5 matrix
    int k = 0;

    for(int i = 0; i < 5; i++)
    {
        for(int j = 0; j < 5; j++)
        {
            matrix[i][j] = s[k++];
            cout << matrix[i][j] << " ";
        }
        cout << endl;
    }

    cout << "\nPlaintext: " << plaintext;

    return 0;
}
/