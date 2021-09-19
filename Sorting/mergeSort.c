// https://www.youtube.com/watch?v=4z9I6ZmeLOQ
#include <stdio.h>
void merge(int arr[],int l,int mid,int r){
    //so here from l to mid its is sorted and from mid to r it is sorted hence are 2 sorted arrays
    int n1 = mid-l+1;//size of 1st array
    int n2 = r-mid;//size of 2nd array
    int a[n1],b[n2];//temp arrays
    for(int i=0;i<n1;i++) {
        a[i] = arr[l+i];//because starting point of arr here is l
    }
    for(int i=0;i<n2;i++) {
        b[i] = arr[mid+1+i];//a is storing values from l to mid and b is storing mid+1 to r
    }
    int i=0,j=0,k=l;//k will traverse the array which starts from l
    while(i<n1 && j<n2){
        if(a[i]<b[j]) arr[k]=a[i++];//arr[k]=a[i];i++;
        else arr[k]=b[j++];//arr[k]=b[j];j++;
        k++;
    }
    while(i<n1) arr[k++]=a[i++];//for remaining elements
    while(j<n2) arr[k++]=b[j++];//for remaining elements
}
/* Here merge function does in ascending order to make it decending make 
    if(a[i]<b[j]) arr[k++]=b[j++];
    else arr[k++]=a[i++];
*/
void mergeSort(int a[],int l,int r){//divinding array
    if(r>l){
        int mid=(l+r)/2;
        mergeSort(a,l,mid);
        mergeSort(a,mid+1,r);

        merge(a,l,mid,r);
    }
}
int main(){
    int a[10];
    for(int i=0;i<10;i++) a[i]=10-i;
    mergeSort(a,0,9);
    for(int i=0;i<10;i++) printf("%d ",a[i]);
    return 0;
}