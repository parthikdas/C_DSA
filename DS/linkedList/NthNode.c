// use of 2 pointers to reach nth node

//Basically to reach nth node i use a iteration to determine the whole length then minus it again do iteration
// here with the help of 2 pointer we will do in 1 go somehow

// To make:
// 1. print nth node from last ////not working
// 2. delete nth node from last ////not working
#include<stdio.h>  
#include<stdlib.h>
struct node  
{  
    int data;  
    struct node *next;  
};
typedef struct node Node;
Node *head;
void create_insertAtStart(int item) {//creating
	Node *new_node = (Node*)malloc(sizeof(Node));
	new_node->data = item;
	new_node->next = head;
	head = new_node;
}
void printNthNode(int k) {
    if(head == NULL) return; // if head empty or only head is present
    Node* slow = head;
    Node* fast = head;
    while(fast) {
        int temp = k;
        while(temp-- && fast) {
            fast = fast->next;
        }
        if(fast) slow=slow->next;
        else break;
    }
    if(slow) printf("lol");
    printf("%d",slow->data);
}
//5 1 2 3 4 5 3
// Function to delete middle node
void deleteMidNode() {
    if(head == NULL || head->next == NULL) return; // if head empty or only head is present
    Node* slow = head;
    Node* fast = head->next;
    if(fast->next == NULL) { // if 2 nodes are there
        slow->next = NULL;
        return;
    }
    Node* temp = NULL;
    while(fast && fast->next) {
        temp = slow; // store previous position
        slow = slow->next; // 1x
        fast = fast->next->next; // 2x
    }
    if(fast == NULL) temp->next = slow->next; // for odd no of elements
    else if(fast->next == NULL) temp->next = fast; // for even
}
void display() { //printing
    if(head==NULL){
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
int main () {
    int n;
    scanf("%d",&n);
    while(n--){
        int data;
        scanf("%d",&data);
        create_insertAtStart(data);  
    }
    int pos;
    scanf("%d",&pos);
    display();
    printNthNode(pos);
    //display();
    return 0;
}

/*
void deleteNthNode(int k) {
    if(head == NULL || head->next == NULL) return; // if head empty or only head is present
    Node* slow = head;
    Node* fast = head->next;
    //printf("%d",slow->data);
    // if(fast->next == NULL) { // if 2 nodes are there
    //     slow->next = NULL;
    //     return;
    // }
    // Node* temp = NULL;
    // while(fast && fast->next) {
    //     temp = slow; // store previous position
    //     slow = slow->next; // 1x
    //     fast = fast->next->next; // 2x
    // }
    // if(fast == NULL) temp->next = slow->next; // for odd no of elements
    // else if(fast->next =c = NULL) temp->next = fast; // for even
    while(fast) {
        int temp = k;
        while(temp-- && fast) fast = fast->next;
        slow=slow->next;
        printf("%d ",slow->data);
    }
}
*/
