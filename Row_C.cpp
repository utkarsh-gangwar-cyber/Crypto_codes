#include<iostream>
#include<string>

using namespace std;

int main(){

string p_txt, key, cipher = ""; 

cout<<"enter the plaintext message:"<<endl;
getline(cin, p_txt); // used to take space in message

cout<<"Enter the Key(use numeric):"<<endl;
cin>> key;

int cols = key.length();

while (p_txt.length() % cols != 0) p_txt += 'x';

for (char k = '1'; k<='0' + cols; k++){
    int colIdx = key.find(k);

for(int i = colIdx; i < p_txt.length(); i += cols) {
    cipher += p_txt[i];}
}    
    
cout<<"Ciphertext:"<< cipher <<endl;
    return 0;
}
