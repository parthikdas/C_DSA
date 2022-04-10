#include <iostream>
using namespace std;
int main() {
	int t;
	cin>>t;
	while(t--) {
		int n;
		cin>>n;
		n*=2;
		int a[n][n], ans = 0;
		for(int i=0;i<n;i++) {
			for(int j=0;j<n;j++)
				cin>>a[i][j];
		}
		//rows checking
		int countTop = 0, countBottom = 0; // count for 1
		for(int i=0;i<n;i++) {
			for(int j=0;j<n;j++)
				if(a[i][j] == 1 && i<n/2) countTop++;
				else if(a[i][j] == 1 && i>=n/2) countBottom++;
		}
		cout<<countTop<<" "<<countBottom<<endl;
		if(countTop > countBottom) {
			// store all the possible positions of 0 in lower half
		} else {
			// store all the possible positions of 0 in upper half
		}
		//vertical checking
		int countLeft = 0, countRight = 0; // count for 1
		for(int i=0;i<n;i++) {
			for(int j=0;j<n;j++)
				if(a[i][j] == 1 && j<n/2) countLeft++;
				else if(a[i][j] == 1 && j>=n/2) countRight++;
		}
		cout<<countLeft<<" "<<countRight<<endl;
		if(countLeft > countRight) {
			// remove the positions from the possible positions array of the left side 0's and keep only right ones
		} else {
			// remove the positions from the possible positions array of the right side 0's and keep only left ones
		}
		//done
		cout<<ans<<endl;

		//*** or think about a solution  with those 4 count variables if u can minus something then find the ans
	}
	return 0;
}