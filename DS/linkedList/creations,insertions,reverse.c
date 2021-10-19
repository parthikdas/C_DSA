#include<stdio.h>  
#include<stdlib.h>
struct node  
{  
    int data;  
    struct node *next;  
};
typedef struct node Node;
Node *head;
Node *last;//only for the create_insertAtEnd1 function
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
void create_insertAtEnd1(int item) {//creating
//So in create_insertAtEnd evertime we traverse till the last to add stuff , here we will have apointer so that it points at last evertime
    Node *new_node = (Node*)malloc(sizeof(Node));
    new_node->data = item;
    if(isEmpty()) {
        head = last = new_node;
        return;
    }
    last->next = new_node;//only 2 line stuff instead of create_insertAtEnd func
    last = new_node;//this thing will also make 1 2 3 4 5
}
//if you want element entered at first should be at last of list then
void create_insertAtStart(int item) {//creating
	Node *new_node = (Node*)malloc(sizeof(Node));
	new_node->data = item;
	new_node->next = head;
	head = new_node;
}
/*see if question tells to reverse then we can take input from opp i.e. if input is 1 2 3 4 5 we will make list from create_insertAtStart 
function so its content will be 5 4 3 2 1 so we dont have to use reverse() but if it says to reverse many times or according question
reallly we have to use reverse() then use it*/
void reverse() {//function to reverse the linked list
    if(isEmpty()){
        printf("List is empty\n");
        return;
    }
    Node* prev = NULL;
    Node* curr = head;
    Node* tom = NULL;
    while (curr != NULL) {
        tom = curr->next;
        curr->next = prev;
        prev = curr;
        curr = tom;
    }
    head = prev;
    printf("Reversed ");
}
//Function to reverse print the LL
void displayReverse(Node* head){
    if(isEmpty()) return;
    displayReverse(head->next);
    printf("%d ",head->data);
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
void insertBefore_nth_node(int insert_before, int value) {//This function will put a new node whose data is value, before node whose data is insert_before
	if(isEmpty()){
        printf("List is empty\n");
        return;
    }
    Node *temp = (Node*)malloc(sizeof(Node));
	Node *new_node = (Node*)malloc(sizeof(Node));
	new_node->data = value;
	temp = head;
  	if(head->data==insert_before){//if the insert_before is head
        new_node->next=head;head=new_node;
    }
    else{
	    int found = 0;
	    while(temp->next != NULL) {
            if(temp->next->data == insert_before) {
                new_node->next = temp->next;
                temp->next = new_node;
                found = 1;
                break;
            }
		temp = temp->next;
        }
        if(found==0) printf("Node not found! \n");
    }
	display();
}
void insertAfter_nth_node(int insert_after, int value) {//This function will put a new node whose data is value, after node whose data is insert_after
	if(isEmpty()){
        printf("List is empty\n");
        return;
    }
    Node *temp = (Node*)malloc(sizeof(Node));
	Node *new_node = (Node*)malloc(sizeof(Node));
	new_node->data = value;
	temp = head;
  	int found = 0;
	while(temp != NULL) {
		if(temp->data == insert_after) {
			new_node->next = temp->next;
			temp->next = new_node;
          	found=1;
			break;
		}
		temp = temp->next;
	}
  	if(!found) printf("Node not found! \n");
	display();
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
    //reverse();
    //insertion at particular point
    int element, val;
    scanf("%d%d",&element,&val);
    insertAfter_nth_node(element,val);
    //insertBefore_nth_node(element,val);
    return 0;
}