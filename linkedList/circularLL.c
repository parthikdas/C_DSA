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
void create_insertAtEnd(int item) {//creating
//This function when you want the first element as input becomes the head
    Node *new_node = (Node*)malloc(sizeof(Node));
	new_node->data = item;
	if(isEmpty()) {
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
void create_insertAtStart(int item) {//creating
//This function when you want the first element as input becomes the last
    Node *new_node = (Node*)malloc(sizeof(Node));
	new_node->data = item;
	if(head==NULL){//if the head is empty
        new_node->next = head;
	    head = new_node;
	    head->next = head;//pointing to itself
    }
    //eg: a circular LL 2->1, here 2 is head and 1 is pointing again to head
	new_node->next = head;//imagine a new_node of value 3 and it points to 2(head)
	Node *temp = (Node*)malloc(sizeof(Node));
	temp = head;
	while(temp->next!=head){//we will traverse till the head which is 2 in our eg
	    temp=temp->next;
	}
	temp->next=new_node;//next of last element(1) will be new_node(upcoming new head also)(here in our eg which is 3)
	head = new_node;//head will be new_node so,3->2->1->3(circular LL)
}
void display() {
    if(isEmpty()){
        printf("List is empty\n");
        return;
    }
	Node *temp = (Node*)malloc(sizeof(Node));
	temp = head;
	while(temp->next != head) {
		printf("%d ",temp->data);
		temp=temp->next;
	}
	printf("%d\n",temp->data);//as it is now at head
}
int main ()  
{
    int n;
    scanf("%d",&n);
    int temp = n;
    while(n--){
        int data;
        scanf("%d",&data);
        create_insertAtStart(data);  
    }
    display();
    return 0;
}