/*
Create a matrix of size n*n where every element is 0 representing there is no edge in the graph.
Now, for every edge of the graph between the vertices i and j set mat[i][j] = 1.
After the adjacency matrix has been created and filled, call the recursive function for the source i.e. vertex 0 that will recursively call the same function for all the vertices adjacent to it.
Also, keep an array to keep track of the visited vertices i.e. visited[i] = true represents that vertex i has been been visited before and the DFS function for some already visited node need not be called.
*/
#include <stdio.h>
#include <stdlib.h>
//i did not want to use extra memory so used *mat, *visited, i could also do mat[10][10] but there is chance of memory wastage
int *mat, *visited, v, e;
//mat is ajacency matrix, visited array to check who is visited, v for vertices, e for edges
void DFS();
int main(){
    scanf("%d%d",&v,&e);
    int *mat[v], *visited;
    for(int i=0;i<v;i++){
        mat[i] = (int*)malloc(v*sizeof(int));//adjacancy matrix
    }
    visited = (int*)malloc(v*sizeof(int));//to check if its visited
    for(int i=0;i<e;i++){
        int a,b;
        scanf("%d%d",&a,&b);
        mat[a][b] = 1;
    }
    printf("adjacancy matrix : \n");
    for(int i=0;i<v;i++){
        for(int j=0;j<v;j++){
            printf("%d ",mat[i][j]);
        }
        printf("\n");
    }
    printf("Depth first search : ");
    DFS(0, v, mat, visited);//we want to start from 0
    return 0;
}
void DFS(int i, int v, int *mat[v], int *visited){
    int j;
    printf("%d ",i);
    visited[i] = 1;
    for(j=0;j<v;j++){
        if(!visited[j] && mat[i][j] == 1){// if not visited and there is a connection
            DFS(j, v, mat, visited);
        }
    }
}
/*
7
11
0 1
0 3
1 3
3 2
1 2
3 4
4 2
4 6 1 6
1 5 2 5
adjacancy matrix : 
0 1 0 1 0 0 0 
0 0 1 1 0 1 1 
0 0 0 0 0 1 0 
0 0 1 0 1 0 0 
0 0 1 0 0 0 1 
0 0 0 0 0 0 0 
0 0 0 0 0 0 0 
Depth first search : 0 1 2 5 3 4 6 
*/