#include <stdio.h>
#include <stdlib.h>
void sieve(int n) {
    int *visited = (int*)malloc((n+1)*sizeof(int));
    for(int i=2;i*i<=n;i++){
        if(!visited[i]) {
            for(int j=i*i;j<=n;j+=i) visited[j]++; 
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