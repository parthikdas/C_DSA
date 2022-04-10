/*
Maximum increasing subsequence
7
5 2 6 8 2 4 2
Output:
3
Explanation:
2 6 8 so ans is 3
*/
#include <iostream>
using namespace std;
int main() {
    int n;
    cin>>n;
    int a[n], count = 1, max = 1;
    for(int i=0;i<n;i++) cin>>a[i];
    for(int i=1;i<n;i++) {
        if(a[i] > a[i-1]) count++;
        else count = 1;
        if(count > max) max = count;
    }
    cout<<max;
    return 0;
}