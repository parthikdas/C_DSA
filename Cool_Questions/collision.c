/*
Once N boys and M girls attended a party. You are given a matrix A of N rows and M columns where Aij is 1 if the i-th boy likes the j-th girl, otherwise it will be 0. Note that it is not necessary that if a boy x likes girl y, then girl y should like boy x.

You know that if there are two different boys x and y, who both like girl z, then there will be a collision. Can you calculate the number of different collisions at this party? Note that order of boys in the collision doesn't matter.
Sample Input 1 
2
4 3
111
100
110
000
2 2
10
01
Sample Output 1 
 4
0
*/
#include<stdio.h>
int main(){
     int i,j;
     int t,men,women,collisions=0;
     scanf("%d",&t);
     while(t--) {
        scanf("%d%d",&men,&women);
        char a[men][women];
        for( i=0;i<men;i++) scanf("%s",a[i]);
        for( i=0;i<women;i++)
        {
            int cnt=0;
            for( j=0;j<men;j++)
            {
                if(a[j][i]=='1')
                cnt++;
            }
            collisions += (cnt*(cnt-1))/2;
        }
        printf("%d\n",collisions);
     } 
    return 0;
}