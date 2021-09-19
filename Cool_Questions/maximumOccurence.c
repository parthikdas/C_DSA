/* hackerearth all test case accepted
You are given a string which comprises of lower case alphabets (a-z), upper case alphabets (A-Z), numbers, (0-9) and special characters like !,-.; etc.

You are supposed to find out which character occurs the maximum number of times and the number of its occurrence, in the given string. If two characters occur equal number of times, you have to output the character with the lower ASCII value.

For example, if your string was: aaaaAAAA, your output would be: A 4, because A has lower ASCII value than a.

Input format:
The input will contain a string.

Output format:
You've to output two things which will be separated by a space:
i) The character which occurs the maximum number of times. 
ii) The number of its occurrence.

Constraints:
The maximum length of the string can be 1000.

Testcase: Pulkit is a dog!!!!!!!!!!!!
ouput: ! 12
*/
#include <stdio.h>
#include <string.h>
void merge2D(int l,int mid,int r,int arr[r][2]){
    int n1 = mid-l+1;//size of 1st array
    int n2 = r-mid;//size of 2nd array

    //a, a1 is for the left array, where a is for value and a1 is for frequency
    //b, b1 is for thr right array, where b is for value and b1 is for frequency
    int a[n1],b[n2];//temp arrays to store value
    int a1[n1],b1[n2];//temp arrays to store freq
 int i;
    for( i=0;i<n1;i++) {
        a[i] = arr[l+i][0];//value, 1st col is storing value
        a1[i] = arr[l+i][1];//freq, 2nd col is storing frequency
    }
    for( i=0;i<n2;i++) {
        b[i] = arr[mid+1+i][0];
        b1[i] = arr[mid+1+i][1];
    }
    i=0;
     int j=0,k=l;//k will traverse the array which starts from l
    while(i<n1 && j<n2){//made it descending, tomake ascending swap line 27,28 <=> 31,32
        //compairing a1, b1 (they store freq) as we need to sort on basis of frequency
        if(a1[i]<b1[j]) {
        	arr[k][0]=b[j];//1st col of arr, b is for value.So, put the value in kth position
        	arr[k][1]=b1[j++];//2nd col of arr, b1 is for frequency.So, put the value in kth position
        }
        else if(a1[i]>b1[j]){
        	arr[k][0]=a[i];
        	arr[k][1]=a1[i++];
        } else {//if freq is equal then smaller number will come first
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
int main() {
	char s[100];
 scanf("%[^\n]%*c", s);
  int n = strlen(s);
  int a[n],i,j,c[n];//c[n] is for knowing whether we have visited that place or not
  for(i=0;i<n;i++) {
    a[i]=s[i];//now a will ascii value of s[i] in every of its index
    c[i]=0;
  }
  int k=0,b[n][2];
  for(i=0;i<n;i++){
		int flag = c[i]==0;//flag will be 1 if the place is not visited 
      	if(flag) b[k][0]=a[i];//1st column filup
      	c[i]=1;
		int count=1;//initialized with 1 because we already found 1 element
      	for(j=0;j<n;j++){
          if(a[i]==a[j]&&c[j]==0){//if found and not visited
           count++;
           c[j]=1;//visited
          }
        }
		if(flag) b[k++][1]=count;//after filling count then only k++//2nd column filup
	}
  mergeSort2D(0,k-1,b);
  printf("%c %d",b[0][0],b[0][1]);
	return 0;
}