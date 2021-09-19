/*He went over to the Graph-making factory to watch some freshly prepared graphs. Incidentally, one of the workers at the factory was ill today, so Jesse  decided to step in and do her job.Jesse's Job is to Identify whether the incoming graph is a tree or not. He is given N, the number of vertices in the graph and the degree of each vertex.Find if the graph is a tree or not.Mandatory declaration is "int SUM=0"Input:First line contains an integer N, the number of vertices.Second line contains N space-separated integers, the degrees of the N vertices.Output:Print "Yes" (without the quotes) if the graph is a tree or "No" (without the quotes) otherwise.Constraints:1  N  1001  Degreei  1000</a>
He went over to the Graph-making factory to watch some freshly prepared graphs. Incidentally, one of the workers at the factory was ill today, so Jesse  decided to step in and do her job.
Jesse's Job is to Identify whether the incoming graph is a tree or not. He is given N, the number of vertices in the graph and the degree of each vertex.
Find if the graph is a tree or not.
Mandatory declaration is "int SUM=0"
Input:
First line contains an integer N, the number of vertices.
Second line contains N space-separated integers, the degrees of the N vertices.
Output:
Print "Yes" (without the quotes) if the graph is a tree or "No" (without the quotes) otherwise.
Constraints:
1  Degreei  1000
1  N  100

testcase1:
input:3 
1 2 1
output:YES

testcase2:
input:3 
2 2 1
output:YES
*/

#include <stdio.h>
int main() {
  int v,i,deg;
  scanf("%d",&v);
  int SUM=0;
  for(i=0;i<v;i++){
    scanf("%d",&deg);
    SUM+=deg;
  }
  if(SUM == 2*(v-1)) printf("YES");
  else printf("NO");
	return 0;
}