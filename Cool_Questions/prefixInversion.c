/*
You are given a binary string S. You need to transform this string into another string of equal length consisting only of zeros, with the minimum number of operations.
A single operation consists of taking some prefix of the string S and flipping all its values. That is, change all the 0s in this prefix to 1s, and all the 1s in the prefix to 0s. You can use this operation as many number of times as you want over any prefix of the string.
Input
The only line of the input contains the binary string, S .
Output
Output a single line containing one integer, the minimum number of operations that are needed to transform the given string S into the string of equal length consisting only of zeros.
Sample Input 1 
 01001001
Sample Output 1 
 6
Explanation
For the given sample case, let us look at the way where we achieved minimum number of operations.
Operation 1: You flip values in the prefix of length 8 and transform the string into 10110110
Operation 2: You flip values in the prefix of length 7 and transform the string into 01001000
Operation 3: You flip values in the prefix of length 5 and transform the string into 10110000
Operation 4: You flip values in the prefix of length 4 and transform the string into 01000000
Operation 5: You flip values in the prefix of length 2 and transform the string into 10000000
Operation 6: You flip values in the prefix of length 1 and finally, transform the string into 00000000

Another Eg:
00001010101
EXPECTED OUTPUT
8
*/
#include <iostream>
#include <string.h>
using namespace std;
int main() {
    char S[1000000];
	cin>>S;
	int i,j,count=0;
    for (i=strlen(S)-1; i>=0; i--) {
	   if (S[i]=='1') {
	       count++;
	       for (j=0;j<i; j++) {
	           if (S[j]=='0')  S[j]='1';
	           else S[j]='0';
	       }
	   }
    }
	cout<<count;
	return 0;
}

/* Another code
	#include<bits/stdc++.h>
	using namespace std;
	int main(){
	string S;

	cin>>S;
	int COUNT=0;
	for(int i=S.size()-1;i>=0;i--){
	   if(COUNT%2==0 and S[i]=='1')
	   COUNT++;
	   if(COUNT%2!=0 and S[i]=='0')
	   COUNT++;
	}
	cout<<COUNT<<endl;
	}

*/