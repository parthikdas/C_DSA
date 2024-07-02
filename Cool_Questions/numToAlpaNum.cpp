/*
    Given num n divide it with 2 till becomes 1 and store the binary then count the no of ones and do modulo
    like total digit in binary % no of 1s then with that start from 'A'
    Eg: 55
    output: 1A1B1C1D1E
    55 divide by 2 is 111011
    no of 1s is 5 and no of digits is 6
    6%5=1 so start from A

    Eg: 19
    output: 1B1C1D
    19 by 2 is 11001
    no of 1s is 3 and no of digits is 5
    5%3=2 hence start from B
*/
#include <iostream>
#include <string.h>
using namespace std;
int main() {
    int n,c=0;
    cin>>n;
    string s="";
    while(n>0) {
        if(n&1) c++;
        s += (n&1) + '0';
        n = n>>1;
    }
    int d = s.length();
    c = d % c;
    c--;
    for(int i=0;i<d;i++) {
        if(s[i]=='1') cout<<s[i]<<(char)(c++ + 'A');
    }
    return 0;
}