// Print the max sum of contiguous sub-array.
// Used Kadane's algo here
#include <stdio.h>
int main()
{
    int t;
    scanf("%d",&t);
    while(t--) {
        int n,i;
        scanf("%d",&n);
        int a[n];
        for(i=0;i<n;i++) scanf("%d",&a[i]);
        int sofar = a[0], max = a[0];
        for(i=1;i<n;i++) {
            sofar+=a[i];
            if(sofar > max) max=sofar;
        }
        printf("%d\n",max);
    }
	return 0;
}