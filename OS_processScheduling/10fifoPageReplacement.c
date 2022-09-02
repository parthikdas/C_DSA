// for few page strings increasing the page size causes the page faults to increase so that is known as belady anatomy
// 3 2 1 0 3 2 4 3 2 1 0 4
// 3
// ans: 9 for 4 ans is 10
#include <stdio.h>
#include <string.h>
int exist(int *frameArr, int f, int no) {
	for(int i=0;i<f;i++) if(frameArr[i] == no) return 1;
	return -1;
}
int main() {
	char pageString[1000];
	int n=0, f=0, index=0, pageFault=0;
	fgets(pageString, 1000, stdin);
	scanf("%d", &f);
	int frameArr[f];
	for(int i=0;i<f;i++) frameArr[i] = -1;
	printf("Frame Array State : \n");
	for(int i=0;i<strlen(pageString)-1;++i) {
		if(pageString[i] != ' ') {
			n++;
			int no = pageString[i]-'0';
			if(exist(frameArr, f, no) == -1) {
				pageFault++;
				frameArr[index++] = no;
				index %= f;
				for(int j=0;j<f;j++) printf("%d ",frameArr[j]);
				printf(" | %d\n",pageFault);	
			}
		}
	}
	printf("No of pages : %d\nNo of pageFault: %d", n, pageFault);	
	return 0;
}