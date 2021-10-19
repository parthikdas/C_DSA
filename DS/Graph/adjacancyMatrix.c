//Given a directed graph, find out if a vertex j is reachable from another vertex i for all vertex pairs (i, j) in the given graph.
//Here reachable mean that there is a path from vertex i to j. The reach-ability matrix is called the transitive closure of a graph.
// So adjacancy matrix is also called transitive closure of a graph. (i am not sure maybe)

// for this is for undirected graph, if u were given directed then remove line 14
#include <stdio.h>
int main(){
    int v,e;//v is vertices, e is edges
    scanf("%d%d",&v,&e);
    int mat[v][v];//adjacancy matrix
    for(int i=0;i<e;i++){
        int a,b;
        scanf("%d%d",&a,&b);
        mat[a][b] = 1;
        mat[b][a] = 1;
    }
    return 0;
}
/*
5 4
0 1
0 2
0 3
0 4
*/