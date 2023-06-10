/*
You are given an N × N grid initially filled by zeros. Let the rows and columns of the grid be numbered from 1 to N, inclusive. There are two types of operations can be applied to the grid:
RowAdd R X: all numbers in the row R should be increased by X.
ColAdd C X: all numbers in the column C should be increased by X.
Now after performing the sequence of such operations you need to find the maximum element in the grid.

Input
The first line of the input contains two space separated integers N and Q denoting the size of the grid and the number of performed operations respectively. Each of the following Q lines describe an operation in the format described above.
Output
Output a single line containing the maximum number at the grid after performing all the operations.
Sample 1:
Input
2 4
RowAdd 1 3
ColAdd 2 1
ColAdd 1 4
RowAdd 2 1
Output
7
Explanation:
The grid changes as follows:
00  33  34  74  74
00  00  01  41  52
The maximum number in the final grid is 7.
*/
// C approach using arrays
#include <stdio.h>
#include <string.h>
int main() {
	int n,q,a,b,rmax=0,cmax=0,i;
	scanf("%d%d",&n,&q);
	int r[n],c[n];
	for(int i=0;i<n;i++) {
	    r[i]=0;
	    c[i]=0;
	}
	for(i=0;i<q;i++) {
	    char s[6];
	    scanf("%s%d%d",s,&a,&b);
	    if(strcmp(s,"RowAdd")==0) {
	        r[a-1]+=b;
	        if(r[a-1]>rmax) rmax=r[a-1];
	    } else{
	        c[a-1]+=b;
	        if(c[a-1]>cmax)  cmax=c[a-1];
	    }
	  }
	printf("%d",rmax+cmax);
	return 0;
}

 // C++ approach using vector
#include <iostream>
#include <vector>
// #include <bits/stdc++.h> // for *max_element
using namespace std;
int main() {
	long int n,q,a,b;
	cin>>n>>q;
    vector<int> r(n,0); // for row
    vector<int> c(n,0); // for col
	while(q--) {
	    string s;
	    cin>>s>>a>>b;
	    if(s[0] == 'R') {
	        r[a-1] += b;
	    } else {
	        c[a-1] += b;
	    }
	}
	int mr = *max_element(r.begin(),r.end());
	int mc = *max_element(c.begin(),c.end());
	cout<<mr+mc<<endl;
	return 0;
}