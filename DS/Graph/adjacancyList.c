#include <stdio.h>// this is for undirected graph, if u were given directed then remove line 60
#include <stdlib.h>
/*
5 7
0 1
0 3
1 3
1 2
3 4
2 4
3 2
output:
0 : 1 3 
1 : 0 3 2 
2 : 1 4 3 
3 : 0 1 4 2 
4 : 3 2 
*/
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
    display();
}
