/*
Problem Description:
Given 'n' words w[1..n], which originate from the same stem (e.g. grace, graceful, disgraceful, gracefully), we are interested in the original stem.&nbsp;
To simplify the problem, we define the stem as the longest consecutive substring that occurs in all the 'n' words. If there are ties, we will choose the smallest one in the alphabetical (lexicographic) order.
Constraints:
1 <= T & <= 10
1 <= n & <= 10
1 <= |w[i]| <= 20
Input Format:
The first line contains an integer 'T' denoting the total number of test cases.
In each test cases, the first line contains an integer 'n' denoting the number of words.&nbsp;
In the second line, 'n' words 'w[1..n]' consisting of lower case characters are given as a single space-spearated list.
Output Format:
Print the stem in a new line.
Test Case 1
INPUT (STDIN)
2
3
actor acting reenact
2
acrid acrimony
EXPECTED OUTPUT
act
acri

Test Case 2
INPUT (STDIN)
4
2
benefactor benevolent
3
diction dictate edict
2
corporal corpse
3
lumen luminary luminous
EXPECTED OUTPUT
bene
dict
corp
lum
*/
#include <iostream>
using namespace std;
int main()
{
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        string arr[n];
        for(int i=0;i<n;i++) cin>>arr[i];
        string s = arr[0];
        int len = s.length();
        string res = "";
        for (int i = 0; i < len; i++) {
            for (int j = i + 1; j <= len; j++) {
                string stem = s.substr(i, j);
                int k = 1;
                for (k = 1; k < n; k++) {
                    if (arr[k].find(stem) == std::string::npos)
                        break;
                }
                if (k == n && res.length() < stem.length()) res = stem;
            }
        }
        cout<<res<<endl;
    }
	return 0;
}