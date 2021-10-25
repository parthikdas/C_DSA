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
            sofar = a[i]>sofar+a[i]? a[i]:sofar+a[i]; // we will give the maximum of a[i] or sofar+a[i], to get this see line 22
            if(sofar > max) max=sofar;
        }
        printf("%d\n",max);
    }
	return 0;
}
/*
Let see if Eg: -4 -1 -3
    Here the max will be printed as -4 and the array will look:
        -4 -5 -3
        -4 -5 -8
    but ans should be -1
    So max of a[i] or sofar+a[i]
        -4 max(-5, -1) -3
        -4 -1 max(-4, -3)
        -4 -1 -3
    So ans is -1
*/