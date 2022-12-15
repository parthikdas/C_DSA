// To print fibonacci series in rev
// 0 1 1 2 3 5 ...

// Using recursion
// C++ program for the above approach
#include <iostream>
using namespace std;
void fibo(int n, int a, int b){
	if (n > 0) {
		fibo(n - 1, b, a + b);
		cout << a << " ";
	}
}
int main(){
	int N = 10;
	fibo(N, 0, 1);
	return 0;
}

// Using array
/* 
Algo:
1) Declare an array of size n. 
2) Initialize a[0] and a[1] to 0 and 1 respectively. 
3) Run a loop from 2 to n-1 and store 
sum of a[i-2] and a[i-1] in a[i]. 
4) Print the array in the reverse order.
*/
void reverseFibonacci(int n) {
    int a[n];
    a[0] = 0;
    a[1] = 1;
    for (int i = 2; i < n; i++) a[i] = a[i - 2] + a[i - 1];
    for (int i = n - 1; i >= 0; i--) cout << a[i] << " ";
}
