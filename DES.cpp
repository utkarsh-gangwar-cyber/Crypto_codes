#include<iostream>
#include<string>
#include<bitset>

using namespace std;

int IP[64]={
    58,50,42,34,26,18,10,2,
    60,52,44,36,28,20,12,4,
    62,54,46,38,30,22,14,6,
    64,56,48,40,32,24,16,8,
    57,49,41,33,25,17,9,1,
    59,51,43,35,27,19,11,3,
    61,53,45,37,29,21,13,5,
    63,55,47,39,31,23,15,7
};

int PC1[56]={
    57,49,41,33,25,17,9,
    1,58,50,42,34,26,18,
    10,2,59,51,43,35,27,
    19,11,3,60,52,44,36,
    63,55,47,39,31,23,15,
    7,62,54,46,38,30,22,
    14,6,61,53,45,37,29,
    21,13,5,28,20,12,4
};

int PC2[48]={
    14,17,11,24,1,5,
    3,28,15,6,21,10,
    23,19,12,4,26,8,
    16,7,27,20,13,2,
    41,52,31,37,47,55,
    30,40,51,45,33,48,
    44,49,39,56,34,53,
    46,42,50,36,29,32
};

int EBOX[48]={
    32,1,2,3,4,5,
    4,5,6,7,8,9,
    8,9,10,11,12,13,
    12,13,14,15,16,17,
    16,17,18,19,20,21,
    20,21,22,23,24,25,
    24,25,26,27,28,29,
    28,29,30,31,32,1
};

int main(){

    unsigned long long plaintext,key;

    string bin="";
    string permu="";
    string keyBin="";
    string keyPermu="";
    string C0="",D0="";
    string key56="";
    string key48="";

    string ePermu="";
    string xorR="";

    cout << "Enter plaintext : ";
    cin >> plaintext;
    cout << "Enter key: ";
    cin >> key;

    cout<< endl;

    bin=bitset<64>(plaintext).to_string();
    cout << "64-bit Bin: " << bin << endl;

    for(int i=0; i<64; i++){
        permu+=bin[IP[i]-1];
    }
    cout << "After IP: " <<permu << endl;

    string L0=permu.substr(0,32);
    string R0=permu.substr(32,32);
    cout << "L0 = " << L0 << endl;
    cout << "R0 = " << R0 << endl;

    cout<<endl;

    keyBin=bitset<64>(key).to_string();
    cout << "64-bit Key Binary:" << keyBin<< endl;

    for(int i=0; i<56; i++){
        keyPermu+=keyBin[PC1[i]-1];
    }
    cout << "After PC1: " << keyPermu<<endl;

    C0=keyPermu.substr(0,28);
    D0=keyPermu.substr(28,28);

    cout << "C0 = " << C0 << endl;
    cout << "D0 = " << D0 << endl;

    key56=C0+D0;

    for(int i=0; i<48; i++){
        key48+=key56[PC2[i]-1];
    }
    cout << "After PC2:" << key48<< endl;

    cout<<endl;

    
    for(int i=0; i<48; i++){
        ePermu+=R0[EBOX[i]-1];
    }
    cout << "After E-Box:" << ePermu << endl;

    for(int i=0; i<48; i++){
        xorR+=char(((ePermu[i]-'0')^(key48[i]-'0'))+'0');
    }
    cout << "After XOR:" << xorR << endl;

    return 0;
}