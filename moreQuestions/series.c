//@Parthik_18_September_2021
//asked by tcs
// Series 1 : 1 2 4 8 ..
// Series 2: 1 3 9 27 .. 
// mix them and print nth term of the mixed series
#include <stdio.h>
// 1 1 2 3 4 9 8 27 16 81 ... 
int main(){
	int n,a,b;
	scanf("%d%d%d",&a,&b,&n);
	for(int i=0;i<n;i++){
		if(i&1){x
			printf("%d ",a);a*=3;
		} else {
			printf("%d ",b);b*=2;
			
		}
	}
	return 0;
}