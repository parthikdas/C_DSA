#include<stdio.h>
int main() {
	int n,flag,temp;
	printf("Enter the no of process:\n ");
	scanf("%d",&n);
	int process[n],turn_around[n],waiting[n],bt[n];
	float avgtt=0,avgwt=0;
	for (int i=0;i<n;i++){
		printf("Enter burst time for the %d process\n",i+1);
		scanf("%d",&bt[i]);
	}
	waiting[0]=0;
	for (int i=0;i<n;i++){
		process[i]=i+1;
	}
	for (int i=0;i<n;i++){
		for (int j=1+1;j<n;j++){
			if (bt[i]>bt[j]){
			temp=bt[i];
			bt[i]=bt[j];
			bt[j]=temp;
			flag=process[i];
			process[i]=process[j];
			process[j]=flag;
			}
		}
	}
	for(int i=1;i<=n;i++)
	{
	waiting[i]=waiting[i-1]+bt[i-1];
	printf("Waiting time for %d process= %d\n",i,waiting[i-1]);
	avgwt+=waiting[i];
	}
	for (int i=0;i<n;i++)
	{
	turn_around[i] = waiting[i]+bt[i];
	printf("turn around time for %d process= %d\n",i+1,turn_around[i]);
	avgtt += turn_around[i];
	}
	printf("Average turn around time: %f\n",avgtt/n);
	printf("Average waiting time:%f\n",avgwt/n);
	return 0;
}
