#include <stdio.h>
// to check a single number is prime or not
int isPrime(int n){
	for(int i=2;i*i<=n;i++) if(!(n%i)) return 0;
	return 1;
}
// This function is to print factors but it may take time,(just for printing)
void factors(int n){
	for(int i=1;i<=n/2;i++) if(!(n%i)) printf("%d ",i);
	printf("%d", n);
}
// To store the factors in array irrespestive of who comes first then u can use a sorting algo to sort
void factors1(int n){
	int factorArr[n/3], j=0;
	for(int i=1;i*i<=n;i++) {
		if(!(n%i)) {
			factorArr[j++] = i;
			if(i!=n/i) factorArr[j++] = n/i;// the if statement is for cases like n=100 and i=10 and n/i=10 so no repeat
		}
	}
	for(int i=0;i<j;i++) printf("%d ",factorArr[i]);
}
/* Time difference between factors and factors1 will come for big nos. Eg: n=1000, so factors will go from 1-500, factors1 will go form 1-31 */
int main(){
	int n;
	scanf("%d",&n);
	//printf("%d",isPrime(n));
	//factors(n);
	factors1(n);
}