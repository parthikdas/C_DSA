/*
Chef recently saw the movie Matrix. He loved the movie overall but he didn't agree with some things in it. Particularly he didn't agree with the bald boy when he declared - There is no spoon. Being a chef, he understands the importance of the spoon and realizes that the universe can't survive without it. Furthermore, he is sure there is a spoon; he saw it in his kitchen this morning. So he has set out to prove the bald boy is wrong and find a spoon in the matrix. He has even obtained a digital map already. Can you help him?
Formally you're given a matrix of lowercase and uppercase Latin letters. Your job is to find out if the word "Spoon" occurs somewhere in the matrix or not. A word is said to be occurred in the matrix if it is presented in some row from left to right or in some column from top to bottom. Note that match performed has to be case insensitive.

Input
The first line of input contains a positive integer T, the number of test cases. After that T test cases follow. The first line of each test case contains two space separated integers R and C, the number of rows and the number of columns of the matrix M respectively. Thereafter R lines follow each containing C characters, the actual digital map itself.
Output
For each test case print one line. If a "Spoon" is found in Matrix, output "There is a spoon!" else output "There is indeed no spoon!" (Quotes only for clarity).
Input
3
3 6
abDefb
bSpoon
NIKHil
6 6
aaaaaa
ssssss
xuisdP
oooooo
ioowoo
bdylan
6 5
bdfhj
cacac
opqrs
ddddd
india
yucky

Output
There is a spoon!
There is a spoon!
There is indeed no spoon!
*/
#include <iostream>
using namespace std;

int main() {
	int t;
	cin>>t;
	while(t--){
	    int n,m,sp=0;
	    cin>>n>>m;
	    char s[n][m];
	    for(int i=0;i<n;i++){
	        for(int j=0;j<m;j++) cin>>s[i][j];
	    }
	    for(int i=0;i<n;i++){
	        for(int j=0;j<m;j++){
	            if((s[i][j]=='s'|| s[i][j]=='S') && (s[i][j+1]=='p'|| s[i][j+1]=='P') && (s[i][j+2]=='o'|| s[i][j+2]=='O') && (s[i][j+3]=='o'|| s[i][j+3]=='O') &&
	            (s[i][j+4]=='n'|| s[i][j+4]=='N')){
	                sp++;
	            }
	            if((s[i][j]=='s'|| s[i][j]=='S') && (s[i+1][j]=='p'|| s[i+1][j]=='P') && (s[i+2][j]=='o'|| s[i+2][j]=='O') && (s[i+3][j]=='o'|| s[i+3][j]=='O') &&
	            (s[i+4][j]=='n'|| s[i+4][j]=='N')){
	                sp++;
	            }
	        }
	    }
	    if(sp>0) cout<<"There is a spoon!"<<endl;
	    else cout<<"There is indeed no spoon!"<<endl;
	}
	return 0;
}