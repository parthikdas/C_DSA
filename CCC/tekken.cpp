/*
    The ultimate battle has begun in Tekken. Each fight has two players. Let the initial health of the players be X, Y 
    then, after the fight, the health of both the players reduces by min(X,Y)
    Anna, Bob, and Claudio have initial health levels of A, B, C. Each pair of players fight exactly once.
    Considering that you can schedule the fight between each pair in any order, find whether Anna can have a positive health level at the end of the battle.
    Input Format
    The first line of input will contain a single integer T, denoting the number of test cases.
    The first and only line of each test case contains three space-separated integers 
    A,B,C — the initial health levels of Anna, Bob, and Claudio respectively.
    Output Format
    For each test case, output on a new line, YES, if you can schedule the fight between each pair in an order such that Anna can have a positive health at the end of the battle. Otherwise, output NO.
    You can print each character in uppercase or lowercase. For example NO, no, No, and nO are all considered identical.
    Sample 1:
    Input
    3
    4 2 0
    2 7 4
    5 1 4
    Output
    YES
    NO
    YES

    Link - https://www.codechef.com/problems/TEKKEN?tab=statement
*/
#include <iostream>
using namespace std;
#define min(a,b) a>b?b:a
#define max(a,b) a>b?a:b;
int main() {
	int t;
	cin>>t;
	while(t--) {
	    int a,b,c;
	    cin>>a>>b>>c;
	    int temp = min(b,c);
	    b-=temp;
	    c-=temp;
	    a -= max(b,c);
	    cout<<(a>0?"YES":"NO")<<endl;
	}
	return 0;
}