#include<stdio.h>  
#include<stdlib.h>
typedef struct node  
{  
    int data;  
    struct node *next;  
} Node;
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
void delete_nth_node(int c) {
    if(isEmpty()){
        printf("List is empty\n");
        return;
    }
    if(c==0) {
        head=head->next;
    } else {
        Node *curr = (Node*)malloc(sizeof(Node));
        curr = head;
        while(c-->1 && curr->next!=NULL) {
            curr=curr->next;
        }
        Node *temp = curr->next;
        curr->next = curr->next->next;
        free(temp);
    }
    printf("Element deleted\n");
    display();
}
void delete_n_nodes_from_start(int no_of_nodes) {
    if(isEmpty()){
        printf("List is empty\n");
        return;
    }
    printf("After deletion\n");
	while(no_of_nodes--&&head!=NULL){
        Node *temp=head;
        head=head->next;
        free(temp);
    }
    display();
}
void delete_n_nodes_from_last(int size,int no_of_nodes) {
    if(isEmpty()){
        printf("List is empty\n");
        return;
    }
    printf("After deletion\n");
    if(size == no_of_nodes){
        head = NULL;
    } else {
        int c=size-no_of_nodes;//if total size is 6 and nodes to be deleted from last is 3 so we have to skip first 6-3 = 3 nodes
    	Node *temp = (Node*)malloc(sizeof(Node));
    	temp = head;
    	while(temp != NULL) {
    	    while(c-->1){
              temp=temp->next;
            }
            Node* t = temp->next;
            temp->next = NULL;
            free(t);
            break;
	    }
    }
    display();
}
void delete_nodes_till_nth_node(int val){//This function will delete all the nodes from starting till node whose value is val
    /*  6
        5 8 1 9 3 7
        8
        output: 8 1 9 3 7
    */
    if(isEmpty()){
        printf("List is empty\n");
        return;
    }
    Node *start = (Node*)malloc(sizeof(Node));
	start = head;
	while(start != NULL) {
		if(start->data==val) {head=start;break;}
		start=start->next;
	}
  if(start==NULL){printf("Invalid Node! \n");}
    display();
}
void deleteList(){// to completely delete the list
    if(isEmpty()){
        printf("List is empty\n");
        return;
    }
    while (head != NULL) {
        Node* temp = head;
        head = head->next;
        free(temp);
    }
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
     //to delete nodes before element
    int element;
    scanf("%d",&element);
    delete_nodes_till_nth_node(element);

    //for deleting nodes from edges
    // int no_of_nodes;
    // scanf("%d",&no_of_nodes);
    // if(no_of_nodes>temp) printf("Segementation 11\n");
    // else delete_n_nodes_from_start(no_of_nodes);
    // if(no_of_nodes>temp) printf("Segementation 11\n");
    // else delete_n_nodes_from_last(temp,no_of_nodes);
    
    // int pos;
    // scanf("%d",&pos);
    // if(pos > temp) printf("Segmentation:11");
    // else delete_nth_node(pos-1);
    //deleteList();
    return 0;
}