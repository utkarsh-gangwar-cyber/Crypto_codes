#include <bits/stdc++.h>
using namespace std;

int main()
{
    long long p, q, n, fn, msg, e, d, cp, dd;

    cout << "ENTER THE PRIME NO:" << endl;
    cin >> p >> q;

    n = p * q;
    cout << "This is the value of n: " << n << endl;

    fn = (p - 1) * (q - 1);
    cout << "The value of Euler Fn.: " << fn << endl;

    cout << "ENTER THE PLAINTEXT:" << endl;
    cin >> msg;

    // Find e
    for(int i = 2; i < fn; i++)
    {
        if(gcd(i, fn) == 1)
        {
            e = i;
            break;
        }
    }

    cout << "e value: " << e << endl;

    // Find d
    for(int i = 1; i < fn; i++)
    {
        if((e * i) % fn == 1)
        {
            d = i;
            break;
        }
    }

    cout << "d value: " << d << endl;

    // Encryption
    cp = 1;
    for(int i = 0; i < e; i++)
    {
        cp = (cp * msg) % n;
    }

    cout << "RSA ENCRYPTION: " << cp << endl;

    // Decryption
    dd = 1;
    for(int i = 0; i < d; i++)
    {
        dd = (dd * cp) % n;
    }

    cout << "RSA DECRYPTION: " << dd << endl;

    return 0;
}






/*
#include<bits/stdc++.h>
using namespace std;

int main()
{
    double n,p,q,msg,e,d;
    int fn;
    cout<<"ENTER THE prime no"<<endl;
    cin>>p>>q;
     
     n = p*q;
     cout<<"This is the value of n:"<<n<<endl;

    cout<<"ENTER THE PLAINTEXT"<<endl;
    cin>>msg;

    fn = (p-1) * (q-1);
    
    cout<<"The value of Euler Fn.:"<<fn<<endl;

    for(int i = 2 ; i < fn;i++)
    {
        if(gcd(i,fn) == 1)
        {
            e=i;
            break;
        }
    }
    cout<<"e value:"<<e<<endl;
    
    d=fmod(1/e,fn);

    double r = pow(msg,e);
    double cp =   fmod(r,n);
    cout<<"RSA ENCRYPTION:"<<cp<<endl;

    double dc=pow(cp,d);
    double dd=fmod(dc,n);
    cout<<"RSA DECRYPTION:"<<ceil(dd)<<endl;

    return 0;

}

*/


/* 
#include <iostream>
using namespace std;

int main() {
    double  n,p,q,msg,e,d;
    int E_fn;
   cout<<"Enter the prime nos."<<endl;
    cin>> p>>q;
    //calculating n
    n=p*q;
    cout<<"value of n is"<< n<<endl;
    //calculating euler function
    E_fn = (p-1) * (q-1);
    cout<<"value of phi(n) {here E_fn} is"<< E_fn<<endl;

    cout<<"enter the message you wanna encrpt"<<msg<<endl;
    //Calculating Public key 'e'

    int(i=2;i<E_fn;i++)
    {
     if(GCD(i,E_fn)==1){
        e=i;
      break;
     }  
    }
    cout<<"Public key e is"<<e<<endl;
    
    //calculating Private key d:
    d= fmod(1/e,E_fn);
    cout<<"Private key e is"<<d<<endl;

    //Now Encrypting our Message
     double c = pow(msg,e);
     double cm = fmod(c,n);

    // Decryption
    double PT= pow(msg,d);
     double PTm = fmod(PT,n);

    cout<<"Encrpyted message is :"<<cm<<endl;
    cout<<"Decrypted msg is:"<<PTm <<endl;
    
    return 0;
}*/

