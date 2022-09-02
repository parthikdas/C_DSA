#include <stdio.h>
#include <stdlib.h>
int noProcess(int *bt, int n) {
    for(int i=0;i<n;i++) if(bt[i]!=0) return 0;
    return 1;
}
int main() {
    int n, quantTime; // no of processes, quantum time
    printf("Enter the quantum time : ");
    scanf("%d", &quantTime);
    printf("Enter the no of Processes : ");
    scanf("%d",&n);
    int bt[n], wt[n]; // burst time, waiting time of each processes
    for(int i=0;i<n;i++) {
        printf("Enter the burst time of P%d : ",i+1);
        scanf("%d",&bt[i]);
        wt[i] = 0;
    }

    printf("\n\nCPU starting..................\n");
    int i=0, tempQuantTime = quantTime, flag = 0, last_quant=0, *prev_quant = (int*) malloc(n * sizeof(int));// current process, temp var to store the quantum
    // prev_quatn is like context switch its saves the state of old process and loads the state of new process
    while(!noProcess(bt, n)) {
        if(bt[i]) {
            if(flag) wt[i] = last_quant-prev_quant[i]; // skip first process
            quantTime = quantTime > bt[i] ? bt[i] : tempQuantTime; // changing quantum time
            prev_quant[i] += quantTime;
            last_quant += quantTime;
            bt[i] -= quantTime;
            printf("\nP%d : BT = %d, WT = %d", i+1, bt[i], wt[i]);
        }
        i = ++i % n;
        flag = 1;
        //quantTime = tempQuantTime; // reset quantTime
    }
    printf("\n\nFinal Table : \nProcess | Wait Time | Turn Around Time");
    for(int i=0;i<n;i++) {
        printf("\nP%d\t| %d\t    | %d", i+1, wt[i], prev_quant[i] + wt[i]); // prev_quant is now original bt, so bt + wt = turn around time
        if(i) wt[0]+=wt[i];
    }
    printf("\nTotal waiting time : %d\nAverage waiting time : %f", wt[0], (float)wt[0]/n);
    return 0;
}
// 4 3 4 5 6