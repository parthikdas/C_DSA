/*
41
5=2+3 
17=2+3+5+7 
41=2+3+5+7+11+13 
Total count is 3
*/
#include <iostream>
#include <stdlib.h>
using namespace std;
int *matArr, size = 0, i, j;
void sieve(int &n) {
    int *a = (int*)malloc((n+1)*sizeof(int));
    matArr = (int*)malloc((n+1)*sizeof(int));
    for(i=2;i*i<=n;i++){
        if(!a[i]) {
            for(j=i*i;j<=n;j+=i) a[j]++; 
        }
    }
    for(i=2;i<=n;i++) if(!a[i]) matArr[size++] = i;
}
int isPrime(int n){
    for(i=0;i<size;i++) {
        if(matArr[i] == n) return 1;
    }
    return 0;
}
int main() {
    int n, count=0;
    cin>>n;
    sieve(n);
    int sum=matArr[0];
    for(i=1;i<size;i++){
        sum+=matArr[i];
        if(isPrime(sum)) {
            cout<<sum<<"=";
            for(j=0;j<=i;j++) cout<<matArr[j]<<(j==i?" ":"+");
            cout<<endl;
            count++;
        }
    }
    cout<<"Total count is "<<count<<endl;
    return 0;
}