//Question is skip k-1 persons and kill a man, tell the postion which will survive
#include<stdio.h>  
#include<stdlib.h>
struct node  
{  
    int data;  
    struct node *next;  
};
typedef struct node Node;
Node *head;
int isEmpty(){
    return head == NULL;
}
void create(int item) {//creating
//This function when you want the first element as input becomes the head
    Node *new_node = (Node*)malloc(sizeof(Node));
	new_node->data = item;
	if(isEmpty(head)) {
		head = new_node;
		head->next = head;//pointing to itself
        return;
	}
	Node *temp = (Node*)malloc(sizeof(Node));
	temp = head;
	while(temp->next != head) {//traversing till last node
		temp=temp->next;
	}
	new_node->next = head;
	temp->next = new_node;
}
void display() {
    if(isEmpty(head)){
        printf("List is empty\n");
        return;
    }
    printf("Circular Linked List:");
	Node *temp = (Node*)malloc(sizeof(Node));
	temp = head;
	while(temp->next != head) {
		printf("%d ",temp->data);
		temp=temp->next;
	}
	printf("%d\n",temp->data);//as it is now at head
}
int skip(int k){
    if(isEmpty(head)) return -1;
    if(k==1) return 0;
    Node *temp = (Node*)malloc(sizeof(Node));
	temp = head;
	while(temp->next!=temp) {
	    for(int i=0;i<k-2;i++) {//k-2 because the k-1 guy will be killed
	        temp = temp->next;
	    }
	   	printf("%d is killed\n",temp->next->data);
	   	Node* x=temp->next;
	    temp->next=temp->next->next;//we killed it
	    free(x);
	    temp = temp->next;//moving to next one
	}
    return temp->data;
}
int main ()  
{
    int n;
    scanf("%d",&n);
    for(int i=0;i<n;i++){
        create(i+1);  
    }
    display();
    int k;
    scanf("%d",&k);
    printf("%d will survive\n",skip(k));
    free(head);
    return 0;
}