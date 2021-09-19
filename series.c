//@Parthik_18_September_2021
//asked by tcs
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