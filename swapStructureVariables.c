#include <stdio.h>
#include <stdlib.h>
struct node{
    int t;
    char s;
};
struct node *arr,x; 
int main()
{
    arr=(struct node*)malloc(3*sizeof(struct node));
   arr[0].t = 1;
   arr[1].t = 2;
   arr[2].t = 3;
   arr[0].s = 'a';
   arr[1].s = 'b';
   arr[2].s = 'c';
   
   x=arr[0];
   arr[0]=arr[1];
   arr[1]=x;
    printf("%d %d %d\n",arr[0].t,arr[1].t,arr[2].t);
    printf("%c %c %c",arr[0].s,arr[1].s,arr[2].s);
    return 0;
}
