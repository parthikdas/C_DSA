#include <stdio.h>
// This code retains the order of elements
int main()
{
    int a[5]={1,2,1,2,4}, size=5;
    for(int i=0;i<size;i++){
        for(int j=i+1;j<size;j++){
            if(a[i] == a[j]){// if the elements are same
                for(int k=j;k<size-1;k++){//remove the element from the array, position is j
                    a[k] = a[k+1];
                }
                size--;//reduce the size
                j--;//decrement j if deletion of element is done
            }
        }
    }
    for(int i=0;i<size;i++) printf("%d ",a[i]);
    return 0;
}
//Another approach is sort the array then do a while loop to print the distinct elements
//But here order of elements are not retained