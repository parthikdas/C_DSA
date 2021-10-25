/*  Hackerank question : https://www.hackerrank.com/challenges/small-triangles-large-triangles/problem
You are given  triangles, specifically, their sides ,  and . Print them in the same style but sorted by their areas from the smallest one to the largest one. It is guaranteed that all the areas are different.
The best way to calculate a area of a triangle with sides ,  and  is Heron's formula:
 where .
Input Format
The first line of each test file contains a single integer .  lines follow with three space-separated integers, ,  and .
Output Format
Print exactly  lines. On each line print  space-separated integers, the ,  and  of the corresponding triangle.
Sample Input 0
3
7 24 25
5 12 13
3 4 5
Sample Output 0
3 4 5
5 12 13
7 24 25
Explanation 0
The square of the first triangle is . The square of the second triangle is . The square of the third triangle is . So the sorted order is the reverse one.
*/
#include <stdlib.h>
#include <math.h>
typedef struct triangle{
	int a;
	int b;
	int c;
} triangle;
void sort_by_area(triangle* tr, int n) {
	float ans[n];
    for(int i=0;i<n;i++){
        float p = (tr[i].a + tr[i].b + tr[i].c)/2.0; //use 2.0 compulsary int/int gives int, int/float gives float
        float s = (p * (p-tr[i].a) * (p-tr[i].b) *(p-tr[i].c));
        //formula without sqrt as areas are different guarenteed 
        //because sqrt dosent work well with float values
        ans[i] = s;
    }
    for(int i=0;i<n-1;i++) {
        for(int j=0;j<n-i-1;j++){
            if(ans[j] > ans[j+1]){
                int temp = ans[j];
                ans[j] = ans[j+1];
                ans[j+1] = temp;
                triangle tem = tr[j];
                tr[j] = tr[j+1];
                tr[j+1] = tem;
            }
        }
    }
}
int main(){
	int n;
	scanf("%d", &n);
	triangle *tr = malloc(n * sizeof(triangle));
	for (int i = 0; i < n; i++) {
		scanf("%d%d%d", &tr[i].a, &tr[i].b, &tr[i].c);
	}
	sort_by_area(tr, n);
	for (int i = 0; i < n; i++) {
		printf("%d %d %d\n", tr[i].a, tr[i].b, tr[i].c);
	}
	return 0;
}