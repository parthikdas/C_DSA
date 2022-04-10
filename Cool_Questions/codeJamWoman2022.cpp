/*
	After the troubles with printing advertising for IO 2 yrs ago, the marketing team
	of the conference decided to use an interactive installation. It consists of a matrix 
	of 2N rows and cols of touchscreen. Each touchscreen can display either an uppercase I or O.
	When one is touched it swithes the letter to one its not. Eg:
	mat:
	1 1 0 0    1 1 0 0
	0 0 0 1 -> 0 0 1 1
	1 1 1 1    1 1 1 1
	0 0 0 1    0 0 0 0
	Explaination: in left N=2. The top 2 rows show 3 letter I, while the bottom 2 rows shows 5. On
	the other hand, both the leftmost 2 cols and rightmost 2 cols show 4 letter I's. By touching the
	2 highlighted screens((1,2), (3,3)) we can change the state to shown in right, which shows 4 letter I's
	in top 2 cols and in bottom 2 cols, and also maintains the balance b/w left and right sides.

	Given the state of installation, can u find the min no of letter chamges neede to achieve your organizational goal?

	Input: testcase, matrix size, matrix

	Sample Input:
	3
	2
	IIOO
	OOOI
	IIII
	OOOI
	1
	IO
	OO
	2
	OIOI
	IOIO
	OIOI
	IOIO

	Sample Ouput:
	Case #1: 2
	Case #2: 1
	Case #3: 0

	Sample Case #1 is the onw explained in the statement. not touching anything does not work and a single touch would leave
	and odd no of of letters I in total, so the result cannot be balanced. It is explained in the statment how it can be balanced with 2 touches
	Sample Case #2 changing the top left corner to O leaves no letter I so all halves have the same amount
	Sample Case #3 the installation is already organized acc to your req, so no touch needed
*/

// One thing i noticed that out of 2 conditions that left right and top bottom need to same , so out of those 2 one will be true for sure.
// dividing the matrix into 4 parts

#include <iostream>
#include <math.h>
using namespace std;
int main() 
{
	int t;
	cin>>t;
	for(int x=0;x<t;x++) {
	    int n, upleftCount=0, uprightCount=0, lowleftCount=0, lowrightCount=0;
	    cin>>n;
	    n*=2;
	    char a[n][n];
	    for(int i=0;i<n;i++) {
	        for(int j=0;j<n;j++) {
	            cin>>a[i][j];
	            if(a[i][j] == 'I') {
	                if(i<n/2) {
	                    if(j<n/2) upleftCount++;
	                    else uprightCount++;
	                } else {
	                    if(j<n/2) lowleftCount++;
	                    else lowrightCount++;
	                }
	            }
	        }
	    }
	    int count=0;
        if((upleftCount+uprightCount)!=(lowleftCount+lowrightCount))
            count+=abs(upleftCount+uprightCount-lowleftCount-lowrightCount);
        else if((upleftCount+lowleftCount)!=(uprightCount+lowrightCount))
            count+=abs(upleftCount+lowleftCount-uprightCount-lowrightCount);
	    cout<<"Case #"<<x+1<<": "<<count<<endl;
	}
	return 0;
}