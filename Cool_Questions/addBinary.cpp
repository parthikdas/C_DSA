/*
    Leetcode 67 Add Binary
    Given 2 binary strings A, B return thier sum as a binary string
    Example: input: a="11" b="1" output:"100"
    Example: input: a="1010" b="1011" output:"10101"
*/
#include <iostream>
using namespace std;
string addBinary(string a, string b) {
    string ans = "";
    int carry = 0, i = a.length()-1, j = b.length()-1;
    while(i>=0 || j>=0) {
        int sum = carry;
        if(i>=0) sum += (a[i] - '0');
        if(j>=0) sum += (b[j] - '0');
        carry = sum/2; // if its 3 then 1 if its 2 then 1 if its 1 then 0
        ans = (sum % 2 == 0 ? '0' : '1') + ans; // prepend ans
    }
    if(carry) ans = '1' + ans;
    return ans;
}