/*
Given a List of numbers separated with comma.
The numbers 5 and 8 are present in the list.
Note: Assume that 8 always comes after 5 and there is only one 8 and only one 5 in the
input list.
Perform these two Cases on input list.
Case 1: num1 -&gt; Add all numbers which do not lie between 5 and 8 in the input List.
Case 2: num2 -&gt; Number formed by concatenating all numbers from 5 to 8 in the input list.
After that print sum of num1 and num2.

Constraints
5 &lt;= N &lt;= 1000

Input Format:
First line will be given an Integer N which will denote number of integers in the list.
Second line you will get N integers be Integers separated with commas.
Output Format: Print Output in a single line according to given rules above.

Test Case 1
Input:
8
3,2,6,5,1,4,8,9

Output: 5168
Explanation 1

num1: 3+2+6+9 = 20 (According to Case 1: adding all numbers which do not lie between 5
and 8).
num2: 5148 (According to Case 2: Concatenating all numbers which is lie between 5 and 8,
including 5 and 8).
Adding num1 and num2 will be our final output.

so num1 + num2 = 20 + 5148 = 5168.

Test Case 2
Input:
10
3,4,5,10,20,8,9,7,45,66

Output: 510342

Explanation 2
num1: 3+4+9+7+45+66 = 134 (According to Case 1: adding all numbers which do not lie
between 5 and 8).
num2: 510208 (According to Case 2: Concatenating all numbers which is lie between 5 and
8, including 5 and 8).
Adding num1 and num2 will be our final output.
so num1 + num2 = 134 + 510208 = 510342.
*/
// @Parthik | 21 September, 2021
#include <stdio.h>
#include <math.h>
//8 3,2,6,5,1,4,8,9
int main()
{
    int inum;
    scanf("%d",&inum);
    if(inum>0){ // array size should be greater than 0
        int iarr[inum],icheck=-1;
        for(int i=0;i<inum;i++) {
            scanf("%d,",&iarr[i]);
            if(iarr[i] < 0) { // checking for negative numbers
                printf("No negative numbers..");
                return 0; // exit
            }
        }
        for(int i=0;i<inum;i++) { // ichecking if 8 and 5 is present or not
            if(iarr[i]==8 || iarr[i]==5) icheck++;
        }
        if(icheck) { // if 8,5 is present
            int inum1=0,inum2=0;
            icheck = 0;
            for(int i=0;i<inum;i++){
                if(iarr[i] == 5) icheck=1;
                else if(iarr[i-1] == 8) icheck=0;
                if(icheck) {
                    int idigit = iarr[i] == 0 ? 1 : (int)log10(iarr[i])+1; // if element is 0 then digit is 1 else forumla
                    inum2 = inum2*pow(10,idigit)+iarr[i];
                }
                else inum1 += iarr[i];
            }
            printf("%d",inum1 + inum2);
        }
        
    }
    return 0;
}