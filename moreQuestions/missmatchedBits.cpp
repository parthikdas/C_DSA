/******************************************************************************
Number of Mismatching Bits
Given two integers "first" and "second". Find the number of bits that do not match in the binary representation of the given numbers.
For example, let "first" be 11 and "second" be 15. Writing both the given numbers in binary we get first = 1011(binary representation of 11) and second = 1111(binary representation of 15) we can see all the bits are the same except the second bit.

Therefore only 1 bit differs hence we return 1 as shown in the diagram.
Note:
1. Do not print anything, just implement the provided function and return the number of mismatching bits for the given numbers.
Input format:
The first line of input contains an integer ‘T’ denoting the number of test cases. The next ‘T’ lines represent the ‘T’ test cases. The only line of each test case contains 2 space-separated integers "first" and "second"
Output Format
For each test case, print a single integer denoting the number of mismatched bits in their binary representation. The output of each test case will be printed in a separate line.
Constraints:
1 <= T <= 10 ^ 5 0 <= first, second <= 10^9 Where ‘T’ is the total number of test cases and "first", " second" are the given numbers. Time limit: 1 second


*******************************************************************************/
#include <iostream>

using namespace std;

int main()
{
    int a, b;
    cin>>a>>b;
    int first = a, second = b, count = 0;
    for(int i=0;i<30;i++) {
        if(((first>>i)&1) != ((second>>i)&&1)) { // evrytime we are doing half and then bit check
    // no>>1 is / by 2
    // no>>2 is / by 4 and so on
    
            count++;
        }
    }
    cout<<count<<endl;
    
    first = a, second = b, count = 0;
    int xorr = a^b;
    while(xorr>0) {
        xorr = xorr>>1; // we need to physically store it just >>1 does not change the value of var
        if(xorr& 1) count++;
    }
    cout<<count<<endl;
    return 0;
}