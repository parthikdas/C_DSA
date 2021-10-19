/*
 Here i am not taking care of collision.
 Its just to see what basic hash is.
 Here if i do collision it will override one position and we will lose the old value.
*/
#include <stdio.h>
#define n 10
int hash(int a){
    return a%10;//Division method
}
int main(){
    int a[n];
    for(int i=11;i<=20;i++){
        a[hash(i)] = i;
    }
    for(int i=0;i<n;i++) printf("a[%d] = %d\n",i,a[i]);
    // Search in O(1)
    /* Now i want to find 16 in it so i dont need to linear search or binary search or any such algo i can simply do 
    a[hash(num)], hash(num) will tell the position so we dont need to traverse */
    int num = 16;
    printf("%d found at index %d",num,hash(num));
    return 0;
}
/* 
collision starts with when loop goes from 11 to 21, so at time index 1 will have 21 and 11 is gone i.e new value is overriding 
old value but we don't want that and both numbers having a same hash number is collition. We have two ways to deal it.
1. Open hashing(Closed Addressing) - uses seperate chaining (array of LL).
2. Closed hashing(Open Addressing)
    /      |       \
 Linear Quadratic  Double
 Probing probing    hashing

 so only in closed hashing increase of table happens as open hashing dont require that
"resizing is generally required for closed hashing as open hashing uses list to store all the values hatched into same index"

Quadratic Probing is better than Linear Probing because in linear Probing there is a problem called clustering and quadratic probing reduces it.
*/