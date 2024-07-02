#include <iostream>
using namespace std;
void fibo(int n, int a, int b){ // recursion fibo
	if (n > 0) {
		fibo(n - 1, b, a + b);
		cout << a << " ";
	}
}
int fibNthTerm(int n){ // recursion fibo nth term
    if(n<=1) return n;
    return fibNthTerm(n-1)+fibNthTerm(n-2);
}
int lcm(int a, int b) { // lowest common factor
    if(!a) return b;
    else if(!b) return a;
    int max = a>b?a:b;
    while(1) {
        if(!(max%a) && !(max%b)) return max;
        max++;
    }
}
int hcf(int a, int b) { // highest common factor
    if(!a || !b) return 0;
    int min = a>b?b:a;
    for(int i=1;i<=min;i++) {
        if(!(a%i) && !(b%i)) return i;
    }
    return 1;
}
int gcd(int a, int b) { // hcf in recursion
    if(!b) return a;
    return gcd(b, a%b);
}
void sieve(int &n) { // sieve of eratosthenes
    int *a = (int*)malloc((n+1)*sizeof(int));
    int *matArr = (int*)malloc((n+1)*sizeof(int));
    int size=0;
    for(int i=2;i*i<=n;i++){
        if(!a[i]) {
            for(int j=i*i;j<=n;j+=i) a[j]++; 
        }
    }
    for(int i=2;i<=n;i++) if(!a[i]) matArr[size++] = i;
}
int addWithoutOperator(int a, int b ) { // addition without using +
    for(int i=1;i<=b;i++) a++;
    return a;
}
void swap(int a, int b) { // swapping with and without third variable
    int temp = a; a = b; b = temp;
    // a = a+b; b = a-b; a = a-b;
    // a = a^b; b = a^b; a = a^b;
}
void printPrimeFactors(int n) {
    while (n % 2 == 0) {
        cout<<2;
        n/=2;
    }
    for (int i = 3; i <= sqrt(n); i = i + 2) {
        while (n % i == 0) {
            cout<<i;
            n /= i;
        }
    }
    if (n > 2) printf("%d, ", n);
}
int decToBinary(int n) {
    int s = 0,j=1;
    while(n>0) {
        s = (n&1)*j+s;
        n=n>>1;
        j*=10;
    }
    return s;
}
int decToOctal(int n) {
    int s = 0,j=1;
    while(n>0) {
        s = (n%8)*j+s;
        n=n/8;
        j*=10;
    }
    return s;
}
int leapYear(int n) {
    return ((!(n%400) || !(n%4)) && n%100 );
}