/*Xsquare likes strings a lot but much more, he likes palindromic strings. Today, he has a string S consisting of lower case English letters. Xsquare wants to convert his string S to a palindromic string. For the above purpose to be served , he can insert as many characters ( possibly zero ) as he wants in his string S such that characters in the new string S can be shuffled to make it a palindrome.

Xsquare is in hurry. Therefore, he wants to accomplish this task with the minimum possible number of insertions in his original string S.

Input :

First line of input contains a single integer T denoting the number of test cases. First and the only line of each test case contains a string S denoting the original string of the Xsquare.

Output :

For each test case, print the required answer.
Input:
5
radar
abc
ab
caa
ccdbb
ouput:
0
2
1
0
0

Input:
3
blahblah
play
book
ouput:
0
3
1
*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int main(){
	int t;
	scanf("%d",&t);
	while(t--){
		char s[1000];
		scanf("%s",s);
		int n = strlen(s), i, num=0;
		int *hash=(int*)malloc(26*sizeof(int));
		for(int i=0;i<n;i++){
			hash[s[i] - 97]++; // as ascii of a is 97
		}
		for(int i=0;i<26;i++){
			if(hash[i]>0 && hash[i]&1) ++num; // if its > 0 and odd then num++
		}
		if(num == 0 || num == 1) printf("0\n"); // if total odd numbers is 0 or 1 then its palindrome 
		else printf("%d\n", num-1);
	}
	return 0;
}