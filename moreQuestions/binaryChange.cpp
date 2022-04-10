// Que - Take a nos input, convert into bin, change all 0 to 1 and vice-versa, then convert to decimal again, print it
#include <iostream>
using namespace std;
/*int main() {
    // with no
    int no, bin=0, i=1;
    cin>>no;
    // converting no to binary
    while(no) {
        if(no&1) { // 1
            bin = bin*i + 1;
        } else { // 0
            bin *= i;
        }
        i=10;
        no>>=1;
    }
    // changing 0, 1 in binary
    int conBin = 0;
    i=1;
    while(bin) {
        conBin = conBin*i + (bin%10?0:1);
        i=10;
        bin/=10;
    }
    // converting binary to decimal
    i=1;
    no=0;
    while(conBin) {
        no += conBin%10 * i;
        i*=2;
        conBin/=10;
    }
    cout<<no;
    return 0;
}*/
int main() {
    // with string
    int no;
    string s;
    cin>>no;
    // converting no to binary
    while(no) {
        if(no&1) { // 1
            s+='1';
        } else { // 0
            s+='0';
        }
        no>>=1;
    }
    // changing 0, 1 in binary
    for(int i=0;i<s.length();i++) {
        if(s[i]=='1') s[i]='0';
        else s[i]='1';
    }
    // converting binary to decimal
    // using a predefined func
    cout << stoi(s, 0, 2);
    return 0;
}
/*
    stoi() vs atoi():
    Both takes string convert them into nos.

    atoi() is a legacy C-style function. stoi() is added in C++ 11. 
     
    atoi() works only for C-style strings (character array and string literal), stoi() works for both C++ strings and C style strings
    atoi() takes only one parameter and returns integer value.
    int atoi (const char * str); 
    stoi() can take upto three parameters, the second parameter is for starting index and third parameter is for base of input number.
    int stoi (const string&  str, size_t* index = 0, int base = 10); 
*/
