/*
Question is to find the kth largest/smallest of the given array.
1.One approach can be to sort the area with bubble shot and then print the middle element but it is a very long and Bad process 
its time complexity is best-O(n) and Avg-O(n^2)
2.Second approach is to use quick shot and when the high comes to the middle element we will stop the process and we will print
the middle element and we will not proceed further which will save us a lot of time
its time complexity is best-O(1) and Avg-O(n)
This is also known as Quick-Select
3.use a array and size of the array is k. First take k elements as input and sort the array and then take rest of the elements 
input and put them at their correct position
*/
//here assuming k=n/2 so kth largest=kth smallest

/*
#include <stdio.h>//approach 1
int main(){
   int arr[] = {7,11,6, 55, 98, 45, 16, 96, 46}; 
   int n = 8,i,j;
   for(i=0;i<n-1;i++){//used bubble sort here
    for(j=0;j<n-i-1;j++){
        if(arr[j]>arr[j+1]) {int t=arr[j];arr[j]=arr[j+1];arr[j+1]=t;}
    }
   }
   for(i=0;i<n;i++) printf("%d ",arr[i]);//after sort
   if(!(n&1)){//here its median (k=n/2)
       printf("\nMedian = %.1f ",(arr[n/2-1]+arr[n/2])/2);
   } else {
       printf("\nMedian = %d ",arr[n/2]);
   }
   return 0;
}
*/
#include <stdio.h>//approach 2
int midVal,n;
void swap(int* a, int* b){ 
    int t = *a; 
    *a = *b; 
    *b = t; 
} 
void printArray(int arr[], int size){ 
    int i; 
    for (i = 0; i < size; i++) 
        printf("%d ",arr[i]); 
    printf("\n");
} 
int partition (int arr[], int low, int high){ 
    int pivot = arr[high];// pivot 
    int i = (low - 1); // Index of smaller element and indicates the right position of pivot found so far
    for (int j = low; j <= high - 1; j++){ 
        if (arr[j] < pivot){// If current element is smaller than the pivot
            i++; // increment index of smaller element 
            swap(&arr[i], &arr[j]); 
        } 
    } 
    swap(&arr[i + 1], &arr[high]);
    if(high==midVal) return -1;//if the high is reached in middle that is our median so dont proceed
    return (i + 1); 
} 
void quickSort(int arr[], int low, int high){ 
    if (low < high){ 
        int pi = partition(arr, low, high);// pi is partitioning index, arr[p] is now at right place
        if(pi==-1) return;//that is we reached the mid position
        quickSort(arr, low, pi - 1);// Separately sort elements before partition
        quickSort(arr, pi + 1, high);// Separately sort elements after partition
    } 
}
int main(){ 
    int arr[] = {7,11,6, 55, 98, 45, 16, 96, 46}; 
    n = 9;
    midVal = n/2;
    quickSort(arr, 0, n - 1); 
    printArray(arr, n); 
    if(!(n&1)){//here its median (k=n/2)
       printf("Median = %.1f ",(float)(arr[n/2-1]+arr[n/2])/2);
    } else {
       printf("Median = %d ",arr[n/2]);
    }
    return 0; 
}
/*
//if u change only > to < in line 101 it will be 16 45 96 98 55
//if u change > to < of line 101 and u change < to > in line 87 it will be 98 96 55 45 16
#include <stdio.h>//approach 3
#include <time.h>
int pos(int a[],int n,int k){//This function checks where to put new element
    int i;
    for(i=0;i<=n;i++){
        if(k<a[i]) return i;
    }
    return -1;//means that k is larger than every elements in a
}
int main()
{
    int arr[] = {7,11,6, 55, 98, 45, 16, 96, 46};
    int n = 8;
    //6,7,11,16,45,46,55,96,98
    int size = n/2+1;
    int a[size],i,j;
    for(i=0;i<size;i++) a[i]=arr[i];//as in the above example we have to go to 4(index) not to 3
    for(i=0;i<size-1;i++){//sorted
        for(j=0;j<size-i-1;j++){
            if(a[j]>a[j+1]){
                int t=a[j];a[j]=a[j+1];a[j+1]=t;
            }
        }
    }
    //approach is to find first k small elements where k=size and a[size-1] is the median(ans)
    for(i=size;i<n;i++){//for the rest of the elements in arr[]
        int position = pos(a,size,arr[i]);//position will tell use where we have to put the arr[i]
        if(position!=-1){
            for(j=size-1;j>=position;j--) a[j]=a[j-1];//shifting elements
            a[position] = arr[i];//put it in right place
        }
    }
    for(i=0;i<size;i++) printf("%d ",a[i]);
    if(!(n&1)){//here its median (k=n/2)
        printf("\nMedian: %.1f",(float)(a[size-2]+a[size-1])/2);
    } else {
        printf("\nMedian: %d",a[size-1]);
    }
    return 0;
}
*/