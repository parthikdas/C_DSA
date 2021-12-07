/*
We define super digit of an integer  using the following rules:
Given an integer, we need to find the super digit of the integer.
If  has only  digit, then its super digit is .
Otherwise, the super digit of  is equal to the super digit of the sum of the digits of .
For example, the super digit of  will be calculated as:
    super_digit(9875)       9+8+7+5 = 29 
    super_digit(29)     2 + 9 = 11
    super_digit(11)     1 + 1 = 2
    super_digit(2)      = 2  
Example:
The number  is created by concatenating the string   times so the initial .
    superDigit(p) = superDigit(9875987598759875)
                  9+8+7+5+9+8+7+5+9+8+7+5+9+8+7+5 = 116
    superDigit(p) = superDigit(116)
                  1+1+6 = 8
    superDigit(p) = superDigit(8)
Sample Input 0
148 3
Sample Output 0
3

 HINT:
consider this example, where n = 23, k = 3
accoring to problem we can do it as 2+3+2+3+2+3 = 6+9 or (n*k) means (23*3) = 69 eventually which leads to 6+9 
*/
#include <stdio.h>
#include <math.h>
int sumd(int n){
    int sum=0;
    while(n){
        sum+=n%10;
        n/=10;
    }
    return sum;
}
int superd(int num){
    if(num>0&&num<10) return num;
    num=sumd(num);
   return  superd(num);
}
int main()
{
int n,k;
scanf("%d%d",&n,&k);
n*=k;
n = superd(n);
printf("%d",n);
	return 0;
}