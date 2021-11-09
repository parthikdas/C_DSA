// The sieve of Eratosthenes is one of the most efficient ways to find all primes smaller than n when n is smaller than 10 million
// Time Complexity: O(n*log(log(n)))
// Auxiliary Space: O(n)
#include <stdio.h>
#include <stdlib.h>
// All prime nos in a range
void sieve(int n) {
    int *visited = (int*)malloc((n+1)*sizeof(int)); // All of them will be marked as 0
    for(int i=2;i*i<=n;i++){
        if(!visited[i]) {
            for(int j=i*i;j<=n;j+=i) visited[j]++; // Make the multiples 1
        }
    }
    for(int i=2;i<=n;i++) if(!visited[i]) printf("%d ",i);
}
int main() {
    int n;
    scanf("%d",&n);
    sieve(n);
    return 0;
}