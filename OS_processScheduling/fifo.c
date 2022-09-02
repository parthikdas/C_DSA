// FIFO - First in First out Scheduling, uses QUEUE by the way
// Here the program takes no of processes and their burst time as input and shows wait and turn around time
#include <stdio.h>
int main(){
    int n;
    printf("Enter the no of Processes : ");
    scanf("%d",&n);
    int bt[n];
    for(int i=0;i<n;i++) {
        printf("Enter the burst time of P%d : ",i+1);
        scanf("%d",&bt[i]);
    }
    int waitTime = 0, turnAroundTime = 0;
    float avgWaitTime = 0, avgTurnAroundTime = 0;
    printf("Processes are about to run\n");
    for(int i=0;i<n;i++) {
        if(i) waitTime += bt[i-1], avgWaitTime += waitTime;
        turnAroundTime = bt[i] + waitTime, avgTurnAroundTime += turnAroundTime;
        printf("P1 : Waiting Time = %d, Turn Around Time = %d\n", waitTime, turnAroundTime);
    }
    printf("\nAverage Waiting Time = %f\nAverage Turn Around Time = %f", avgWaitTime/n, avgTurnAroundTime/n);
    return 0;
}