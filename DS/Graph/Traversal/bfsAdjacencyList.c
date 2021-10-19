//idk if its correct or not
/*
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
Adjacancy List : 
0 : 1 3 
1 : 0 2 6 5 
2 : 1 3 4 5 
3 : 0 2 4 
4 : 3 2 6 
5 : 2 1 
6 : 4 1 
BFS traversal : 
2 0 1 3 6 5 4 
*/
#include <stdio.h>
#include <stdlib.h>
int v, e; // v for vertices, e for edges
//Structure
typedef struct node{
  int data;
  struct node *next;
} Node;
//List
Node *arr[40];
Node* createNewNode(int data){// Create a new node and return it
    Node *new = (Node*)malloc(sizeof(Node));
    new->data = data;
    return new;
}
void insert(int index, int data){
	//we will not check here if head is empty or not it will surely not be empty
	Node* temp = arr[index];
	while(temp->next != NULL){
		temp = temp->next;
	}
	Node* new = (Node*)malloc(sizeof(Node));
	new->data = data;
	temp->next = new;
}
void display(int v){
	for(int i=0;i<v;i++){
		Node *temp = arr[i];
		while(temp!=NULL){
			if(temp == arr[i]) printf("%d : ",temp->data);
			else printf("%d ",temp->data);
			temp=temp->next;
		}
		printf("\n");
	}
}
//List ends
//Queue
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
void bfs(int start){
    // also malloc will initialize it with 0
    int *visited = (int*)malloc(v*sizeof(int));// visited array to check who is visited
    //start it
    enqueue(arr[start]->data);
    visited[start] = 1;
    int vis;
    while(!isEmpty()){// while the queue is not empty
        // Dequeue a vertex from queue and print it
        vis = front->data;
        printf("%d ",vis);
        dequeue();
        for(int i=0;i<v;i++){
    		Node *temp = arr[i];
    		while(temp!=NULL){
    			if(!visited[temp->data]){// if there is a edge and the node is not visited then do it
                    enqueue(temp->data);
                    visited[temp->data] = 1;
                }
    			temp=temp->next;
    		}
	    }
    }
}
int main(){
    scanf("%d%d",&v,&e);
    for(int i=0;i<v;i++){
        arr[i] = createNewNode(i);//head will store the vertex
    }
    for(int i=0;i<e;i++){
        int a,b;
    	scanf("%d%d",&a,&b);
    	insert(a,b);//so first time b will be inserted
    	insert(b,a);//second time a will be inserted
    }
    printf("Adjacancy List : \n");
    display(v);
    printf("BFS traversal : \n");
    bfs(2);
    return 0;
}