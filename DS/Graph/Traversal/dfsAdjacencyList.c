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
Adjacancy List : 
0 : 1 3 
1 : 0 3 2 6 5 
2 : 3 1 4 5 
3 : 0 1 2 4 
4 : 3 2 6 
5 : 1 2 
6 : 4 1 
DFS : 0 1 3 2 4 6 5 
*/
#include <stdio.h>
#include <stdlib.h>
typedef struct node{
	int data;
	struct node *next;
} Node;
Node *arr[10];
int v,e;//v is vertices, e is edges
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
void display(){
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
void dfs(int s, int *visited){
	printf("%d ",s);
	visited[s] = 1;
	for(Node* i=arr[s];i!=NULL;i=i->next){
	    if(!visited[i->data]) dfs(i->data, visited);
	}
}
int main(){
    scanf("%d%d",&v,&e);
    int visited[v];
    for(int i=0;i<v;i++){
    	arr[i] = createNewNode(i);//head will store the vertex
    	visited[i] = 0;
    }
    for(int i=0;i<e;i++){
    	int a,b;
    	scanf("%d%d",&a,&b);
    	insert(a,b);//so first time b will be inserted
    	insert(b,a);//second time a will be inserted
    }
    printf("Adjacancy List : \n");
    display();
    printf("DFS : ");
    dfs(0, visited);
}