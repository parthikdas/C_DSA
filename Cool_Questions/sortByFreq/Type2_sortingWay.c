//https://www.geeksforgeeks.org/sort-elements-by-frequency/
//This whole program takes o(nlogn)+o(n)+o(nlogn), o(nlogn) for mergeSort 2 times and o(n) for arranging 2d array

//Question is to sort the array by frequency in decreasing order and if 2 freq is same then then print the one which came first.

#include <stdio.h>
#include <stdlib.h>
void merge2D(int l,int mid,int r,int arr[r][2]){
    int n1 = mid-l+1;//size of 1st array
    int n2 = r-mid;//size of 2nd array

    //a, a1 is for the left array, where a is for value and a1 is for frequency
    //b, b1 is for thr right array, where b is for value and b1 is for frequency
    int a[n1],b[n2];//temp arrays to store value
    int a1[n1],b1[n2];//temp arrays to store freq

    for(int i=0;i<n1;i++) {
        a[i] = arr[l+i][0];//value, 1st col is storing value
        a1[i] = arr[l+i][1];//freq, 2nd col is storing frequency
    }
    for(int i=0;i<n2;i++) {
        b[i] = arr[mid+1+i][0];
        b1[i] = arr[mid+1+i][1];
    }

     int i=0,j=0,k=l;//k will traverse the array which starts from l
    while(i<n1 && j<n2){//made it descending, tomake ascending swap line 27,28 <=> 31,32
        //compairing a1, b1 (they store freq) as we need to sort on basis of frequency
        if(a1[i]<b1[j]) {
        	arr[k][0]=b[j];//1st col of arr, b is for value.So, put the value in kth position
        	arr[k][1]=b1[j++];//2nd col of arr, b1 is for frequency.So, put the value in kth position
        }
        else if(a1[i]>b1[j]){
        	arr[k][0]=a[i];
        	arr[k][1]=a1[i++];
        } else {//if freq is equal then sort the 0th col(that is stroing indexs)
            //here compairing a, b because we have to put smaller first as freq is same
        	if(a[i]>b[j]){//if a is greater then b is smaller, so put b
        		arr[k][0]=b[j];
        		arr[k][1]=b1[j++];
        	}else {//if a is smaller then b is greater, so put a
        		arr[k][0]=a[i];
        		arr[k][1]=a1[i++];
        	}
        }
        k++;//as kth row is done, increment k.Now, for the next row
    }
    while(i<n1) {//for remaining elements
    	arr[k][0]=a[i];
        arr[k++][1]=a1[i++];
    }
    while(j<n2){//for remaining elements
       	arr[k][0]=b[j];
        arr[k++][1]=b1[j++];
    }
}
void mergeSort2D(int l,int r,int a[r][2]){//dividing array
    if(r>l){
        int mid=(l+r)/2;
        mergeSort2D(l,mid,a);
        mergeSort2D(mid+1,r,a);
        merge2D(l,mid,r,a);
    }
}
//merge sort for 1d array starts
void merge1D(int arr[],int c[], int l,int m,int r)
{
    int n1=m-l+1;//size of 1st array
    int n2=r-m;//size of 2nd array

    int a[n1],b[n2];//temp arrays for main array
    int a1[n1],b1[n2];//temp arrays for index array (c)

    int i;
    for(i=0;i<n1;i++)//filling up for left array
    {
        a[i]=arr[l+i];
        a1[i]=c[l+i];
    }

    for(i=0;i<n2;i++)//filling up for right array
    {
        b[i]=arr[m+1+i];
        b1[i]=c[m+1+i];
    }

    int j=0,k=l;//k will traverse the array which starts from l
    i=0;
    while(i<n1 && j<n2)//made it ascending, n1 is size of left array, n2 is size of right array
    {
        //comparing a, b as we need to sort on basis of who is greater
        if(a[i]<b[j])//if ith element in a is smaller than jth in b
        {//fill the kth position of arr(original array)
            arr[k]=a[i];//put the value in kth position
            c[k]=a1[i];
            i++;//increment i, as it's used
        }
        else if(a[i]>b[j])//if ith element in a is larger than jth in b
        {//fill the kth position of arr(original array)
            arr[k]=b[j];//put the value in kth position
            c[k]=b1[j];
            j++;//increment j, as its used
        }
        else//sort on basis on index
        {
            if(a1[i]<b1[j]){//see the index array
                arr[k]=a[i];//put the value in kth position
                c[k]=a1[i];
                i++;//increment i, as it's used
            } else{
                arr[k]=b[j];//put the value in kth position
                c[k]=b1[j];
                j++;//increment j, as its used
            }
        }
        k++;//as kth row is done, increment k.Now, for the next row
    }
    while(i<n1){//for remaining elements
        arr[k]=a[i];
        c[k]=a1[i];
        k++;
        i++;
    }
    while(j<n2){//for remaining elements
        arr[k]=b[j];
        c[k]=b1[j];
        k++;
        j++;
    }
}
void mergeSort1D(int arr[],int c[], int l, int r){//dividing array
    if(r>l){
        int m=(l+r)/2;
        mergeSort1D(arr, c, l, m);
        mergeSort1D(arr, c, m+1, r);
        merge1D(arr, c, l, m, r);
    }
}

int main(){
	int n;
	scanf("%d",&n);
	int a[n],i,j,k=0,b[n][2];//k for the b array, k is also the count of distinct elements/ k rows/ k will indicate number of elements in a column
	int c[n],temp[n];// c is the index array of a, we will disturb a we will work with temp
    for(i=0;i<n;i++) {
        scanf("%d",&a[i]);
        temp[i]=a[i];
        c[i] = i;
    }
    //sorting the 1D array in ascending order
    mergeSort1D(temp,c,0,n-1);

	for(i=0;i<n;i++){//filup 2d array, 1st col will store 1st appearing index and 2nd one will store frequency
		b[k][0]=c[i];//1st column filup
		int count=1;//initialized with 1 because we already found 1 element
		while(temp[i]==temp[i+1]){//increment till we are getting the previous number
			count++;i++;
		}
		b[k++][1]=count;//after filling count then only k++//2nd column filup
	}

	//sorting the 2D array in descending order on basis of  its frequency
	mergeSort2D(0,k-1,b);

	for(i=0;i<k;i++){//Again printing the array in 1D format
		for(j=0;j<b[i][1];j++){//as 2nd column was storing the frequency, we will print that many times
			printf("%d ", a[b[i][0]]);//1st column was storing the 1st appearing index
		}
	}
	return 0;
}
/*Input: 2 5 2 8 5 6 8 8
Output: 8 8 8 2 2 5 5 6

Input:2
5
5 5 4 6 4
5
9 9 9 2 5
Output:4 4 5 5 6
9 9 9 2 5

Input: 2 5 2 6 -1 9999999 5 8 8 8
Output: 8 8 8 2 2 5 5 -1 6 9999999
Input: 37
1 3 7 7 7 3 2 2 2 7 3 1 7 1 6 3 5 5 4 5 6 2 1 2 4 7 3 1 3 5 4 1 7 2 6 1 2
Output: 1 1 1 1 1 1 1 2 2 2 2 2 2 2 7 7 7 7 7 7 7 3 3 3 3 3 3 5 5 5 5 4 4 4 6 6 6
*/