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
        return;
	}
	Node *temp = (Node*)malloc(sizeof(Node));
	temp = head;
	while(temp->next != NULL) {//traversing till last node
		temp=temp->next;
	}
	temp->next = new_node;
}
void display() { //printing
    if(isEmpty()){
        printf("List is empty\n");
        return;
    }
	Node *temp = (Node*)malloc(sizeof(Node));
	temp = head;
	while(temp != NULL) {
		printf("%d ",temp->data);
		temp=temp->next;
	}
	printf("\n");
}
void isPalindrome(int n) { //integer list is palindrome or not
    if(isEmpty()){
        printf("List is empty\n");
        return;
    }
    Node *ptr1 = (Node*)malloc(sizeof(Node));
    ptr1=head;
    int i,j;
    for(int i=0;i<n/2;i++){
        Node *ptr2 = (Node*)malloc(sizeof(Node));
        ptr2=head;
        for(j=0;j<n-i-1;j++){//if i=0 then ptr2 should be at last,if i=1 then ptr2 should be at second last,like that
            ptr2=ptr2->next;
        }
        if(ptr1->data!=ptr2->data) {
            printf("Not Palindrome");
            return;
        }
        ptr1=ptr1->next;
    }
    printf("Palindrome");
}
int main ()  
{
    int n;
    scanf("%d",&n);
    int temp = n;
    while(n--){
        int data;
        scanf("%d",&data);  
        create_insertAtEnd(data);  
    }
    //to check if the string is palindrome, make changes in struct node and create, display functions and in main palindrome(strlen(s));
    char s[100];
    scanf("%s",s);
    for(int i=0;i<strlen(s);i++) create_insertAtEnd(s[i]);
    display();
    isPalindrome(temp);
    return 0;
}