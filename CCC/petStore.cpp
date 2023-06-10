/*
https://www.codechef.com/problems/PETSTORE?tab=statement
*/
#include <iostream>
using namespace std;

int main() {
	// your code goes here
	int t; cin>>t;
	while(t--){
	    int n; cin>>n;
	    int a[n];
	    for(int i=0;i<n;i++){
	        cin>>a[i];
	    }
	    sort(a,a+n);
	    if(n%2!=0)
	    cout<<"NO"<<endl;
	    else{
	        int i;
	        for(i=0;i<n;i+=2){
	            if(a[i]!=a[i+1]){
	                cout<<"NO"<<endl;
	                break;
	            }
	        }
	        if(i==n)
	        cout<<"YES"<<endl;
	    }
	}
	return 0;
}
//if there are odd number of inputs then we have to print NO because it is not possible to divide equal number of pet to both of them. And in sorted array of even inputs we will check wether the adjacent two elements are same or not if not we will break the loop and if adjacent elements are same throughout the loop we will print YES else print NO.