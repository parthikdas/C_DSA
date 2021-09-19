#include <stdio.h>
#include <stdlib.h>
/*
Eg:
7
10 
0 1
0 3
1 2
2 3
3 4
4 2
4 6
1 6
2 5
1 5
ouput:
0 1 0 1 0 0 0 
0 0 1 0 0 1 1 
0 0 0 1 0 1 0 
0 0 0 0 1 0 0 
0 0 1 0 0 0 1 
0 0 0 0 0 0 0 
0 0 0 0 0 0 0 
BFS traversal : 
0 1 3 2 5 6 4
*/
//i did not want to waste memory so I did *mat,*visited or else simply i could do mat[100][100] but that is wasting of memory
//another thing i wanted mat, visited to have 0 in every index so malloc does it
//Queue
typedef struct node{
  int data;
  struct node *next;
} Node;
Node *front, *rear;//insertion from rear, deletion from front
int isEmpty(){
    return front == NULL && rear == NULL;
}
void enqueue(int data){
    Node *new = (Node*)malloc(sizeof(Node));
    new->data = data;
    if(isEmpty()){
        front = rear = new;
        return;
    }
    rear->next = new;
    rear = new;
}
void dequeue(){
    if(isEmpty()) return;
    if(front == rear) front = rear = NULL;
    else {
        Node *temp = front;
        front = front->next;
        free(temp);
    }
}
int peek(){
    if(isEmpty()) return -1;
    return front->data;
}
//Queue ends
void bfs(int start, int v, int **mat, int *visited){
    enqueue(start);
    visited[start] = 1;
    int vis;
    while(!isEmpty()){// while the queue is not empty
        vis = front->data;
        printf("%d ",vis);
        dequeue();
        for(int i=0;i<v;i++){
            if(!visited[i] && mat[vis][i] == 1){// if there is a edge and the node is not visited then do it
                enqueue(i);
                visited[i] = 1;
            }
        }
    }
}
int main(){
    int v, e; // v for vertices, e for edges
    scanf("%d%d",&v,&e);
    int *mat[v], *visited; // mat is ajacency matrix, visited array to check who is visited,
    for(int i=0;i<v;i++){
        mat[i] = (int*)malloc(v*sizeof(int));//adjacancy matrix
    }
    visited = (int*)malloc(v*sizeof(int));//to check if its visited
    for(int i=0;i<e;i++){
        int a,b;
        scanf("%d%d",&a,&b);
        mat[a][b] = 1;
    }
    printf("Adjacancy Matrix : \n");
    for(int i=0;i<v;i++){
        for(int j=0;j<v;j++){
            printf("%d ",mat[i][j]);
        }
        printf("\n");
    }
    printf("BFS traversal : \n");
    bfs(0, v, mat, visited);
    return 0;
}
/*
5 4
0 1
0 2
0 3
0 4
*/