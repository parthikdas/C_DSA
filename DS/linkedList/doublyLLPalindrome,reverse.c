#include<stdio.h>  
#include<stdlib.h>  
struct node  
{  
    int data;  
    struct node *next;
    struct node *prev;
};
typedef struct node Node;
Node *head;
Node *last;
void create(int item) {
	Node *new_node = (Node*)malloc(sizeof(Node));
	new_node->data = item;
	if(head == NULL) {
		head = new_node;
		last = new_node;
        return;
	}
	Node *temp = (Node*)malloc(sizeof(Node));
	temp = head;
	while(temp->next != NULL) {
		temp=temp->next;
	}
	temp->next = new_node;
	new_node->prev = temp;
	last=new_node;
}
void display() {
	Node *temp = (Node*)malloc(sizeof(Node));
	temp = head;
	printf("Linked List : ");
	while(temp != NULL) {
		printf("->%d",temp->data);
		temp=temp->next;
	}
}
void isPalindrome() {
    Node *temp = (Node*)malloc(sizeof(Node));
	temp = head;
	while(temp!=last) {
	    if(temp->data!=last->data) {
	        printf("Not a Palindrome\n");
	        return;
	    }
	    temp=temp->next;
	    last=last->prev;
	}
	printf("Palindrome\n");
	return;
}
//Function to reverse a doubly LL
void reverse(Node **head){
	Node* temp = NULL;
	Node* current = *head;
	while(current != NULL){
		temp = current->prev;
		current->prev = current->next;
		current->next = temp;
		current = current->prev;
	}
	if(temp != NULL)
		*head = temp->prev;
}
int main ()  
{
    int n,item;
    scanf("%d",&n);
    while(n--){
        scanf("%d",&item);  
        create(item);  
    }
    isPalindrome();
    return 0;
}