/*
For a given positive number num, identify the palindrome formed by performing the
following operations-
Add num and its reverse
Check whether the sum is palindrome or not. If not, add the sum and its reverse and repeat
the process until a palindrome is obtained

For example:
If original integer is 195, we get 9,339, as the resulting palindrome after the fourth addition:
195 +591 = 786
786 + 687 = 1473
1473 + 3741 = 5214
5214+ 4125 = 9339
9339 is a palindrome number

Input format: Read num from the standard input stream.
Output format: Print the palindrome calculated to the standard output stream.
*/
// @Parthik | 21 September, 2021
#include <stdio.h>
#include <math.h>
int idigits; // To store the number of digits
int rev(int inum){ //Function to reverse a number
    int ians=0;
    while(inum){
       ians = ians*10 + (inum%10);
        inum/=10;
    }
    return ians;
}
int palindrome(int inum){// Function to check if number is palindrome or not
    int ifirst = idigits&1? inum/(int)pow(10,idigits/2+1): inum/(int)pow(10,idigits/2); // to get the ifirst part
    // if number of idigits are odd then, n/(int)pow(10,idigits/2+1) eg:n=123, idigits=3 ifirst=123/pow(10,1+1), ifirst = 123/100 = 1
    int isecond = inum%(int)pow(10,idigits/2);
    return ifirst == rev(isecond);
}
int ans(int inum){// Recursive function to find the palindrome number
    if(palindrome(inum)) return inum;// base case
    idigits = (int)log10(inum)+1;
    inum += rev(inum);
    return ans(inum);
}
int main() { // Driver Function
    int inum;
    scanf("%d",&inum);
    if(inum>-1) { // number should be +ve nos
   	 printf("%d",ans(inum));
    }
    return 0;
}
// one edge case is if user gives 001 then output is 2 which should be 1