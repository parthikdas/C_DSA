/*
You are given two positive integers A and B. Find the number of pairs of positive integers (X,Y) such that 1≤X≤A, 1≤Y≤B and X+Y is even.
Sample Input 1 
 4
1 1
2 3
4 6
8 9
Sample Output 1 
1
3
12
36
*/
#include <stdio.h>
int main() {
        int U,V;
        scanf("%d%d",&U,&V);
	    int even_U = U / 2,even_V = V / 2,odd_U = (U + 1) / 2,odd_V = (V + 1) / 2;
       printf("%d",even_U * even_V + odd_U * odd_V);
	return 0;
}