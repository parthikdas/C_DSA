//In quadratic probing we have to insert in 1st free place from (u+i*i)%m
//So increasing of table is not mandatory here we can also remove 
//Hash tables often avoid this problem by making sure that the hash table size is a prime number. When you resize the table, double the size and then round up to the first prime number larger than that. Doing this avoids the clustering problems similar to what you describe.
#include <stdio.h>//7 50 700 76 85 92 73 101
#include <math.h>
#include <stdlib.h>
int maxSize = 7;//stores the size of table
int *a, size = 0;//stores how many elements are present in the array
int hash(int n, int i){//tells the hash value of a number
    return ((n%maxSize)+(i*i))%maxSize;
}
int hashVal(int*a, int n){//tells where to put the number in the table
    int i=0;
    int index = hash(n, i);
    while(a[index] != 0){// till we find a empty place
        index = hash(n, ++i);
        if(i==maxSize-1) return -1;// i range is 0 to m-1
    }
    return index;
}
int isPrime(int n){
    for(int i=2;i*i<=n;i++){
        if(n%i==0) return 0;
    }
    return 1;
}
int nextPrime(int n){
    if(isPrime(n)) return n;
    return nextPrime(++n);
}
void incTable(){//function to increase table size
    int newSize = nextPrime(maxSize*2);// if u send just the maxSize it will return maxSize only but by doing +1 we will get a new prime number
    int temp = maxSize;
    maxSize = newSize;
    int *b = (int*)malloc(maxSize * sizeof(int));
    for(int i=0;i<temp;i++) if(a[i]>0) b[hashVal(b,a[i])]=a[i];
    a = b;
    free(b);
}
void display(){
    for(int i=0;i<maxSize;i++) printf("a[%d] = %d\n",i,a[i]);
    printf("\n");
}
int find(int data){
    int i=0;
    int index = hash(data,i);
    while(a[index] != data){// till we find the numder
    	index = hash(data,++i);
    	if(i==maxSize-1) break;// i range is 0 to m-1
    }
    if(a[index] == data) return index;
    return -1;
}
void delete(int data){
    int index = find(data);
    a[index] = 0;
}
int main() {
    a = (int*)malloc(maxSize * sizeof(int));
    int t;
    scanf("%d",&t);
    while(t--){
        int n;
        scanf("%d",&n);
        int index = hashVal(a,n);
        if(index == -1) printf("Element can't be inserted\n");
        else a[index] = n;
        size++;
        if(size > ceil(0.7*maxSize)) {// if size of table becomes 70% of max size incTable
        	display();
        	incTable();
        }
    }
    display();
    int findVal = 76;
    int index = find(findVal);
    if(index != -1) printf("%d found at index %d.\n",findVal,index);
    else printf("%d not found.\n",findVal);
    delete(findVal);
    index = find(findVal);
    if(index != -1) printf("%d found at index %d.\n",findVal,index);
    else printf("%d not found.\n",findVal);
    return 0;
}