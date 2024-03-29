/*
Mathison recently inherited an ancient papyrus that contained some text. Unfortunately, the text was not a pangram. Now, Mathison has a particular liking for holoalphabetic strings and the text bothers him. The good news is that Mathison can buy letters from the local store in order to turn his text into a pangram.
However, each letter has a price and Mathison is not very rich. Can you help Mathison find the cheapest way to obtain a pangram?

Input
The first line of the input file will contain one integer, T, representing the number of tests.
Each test will be formed from two lines. The first one contains 26 space-separated integers, representing the prices of all letters. The second will contain Mathison's initial text (a string of N lowercase letters).

Output
The output file will contain T lines, one for each test. Each line will contain the answer for the corresponding test.
Sample 1:
Input
2
1 2 3 4 5 6 7 8 9 10 11 12 13 14 15 16 17 18 19 20 21 22 23 24 25 26
abcdefghijklmopqrstuvwz
1 2 3 4 5 6 7 8 9 10 11 12 13 14 15 16 17 18 19 20 21 22 23 24 25 26
thequickbrownfoxjumpsoverthelazydog
Output
63
0
*/

#include <iostream>
using namespace std;

int main() {
	int t;
	cin>>t;
	while(t--) {
	    int a[26]={0},b[26],ans=0,trmp;
	    string s;
	    for(int i=0;i<26;i++) cin>>b[i];
	    cin>>s;
	    for(int i=0;i<s.length();i++) a[s[i]-'a']++;
	    for(int i=0;i<26;i++) if(!a[i]) ans+=b[i];
	    cout<<ans<<endl;
	}
	return 0;
}
