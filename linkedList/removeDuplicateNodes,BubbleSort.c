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
void create_insertAtEnd(int item) {
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
void bubbleSort(){
    Node *i,*j;
    i=head;
    for(i=head;i->next!=NULL;i=i->next) {
        for(j=i->next;j!=NULL;j=j->next) {//heading from i->next , remember j<n-i-1
            if(i->data > j->data) {
                int temp = i->data;
                i->data = j->data;
                j->data = temp;
            }
        }
    }
    printf("After sorting\n");
    display();
}
void removeDuplicates_Sorted(int size){// to remove duplicates from sorted list
    if(isEmpty()){
        printf("List is empty\n");
        return;
    }
    bubbleSort();//first sort it
    Node *curr = head;
    while (curr->next != NULL) {
        if(curr->data == curr->next->data) {
            Node* temp = curr->next->next;
            free(curr->next);
            curr->next = temp;
        } else {
            curr = curr->next;
        }
    }
    printf("After deleting duplicates\n");
    display();
}
void removeDuplicates_unsorted() {
    Node *ptr1, *ptr2, *dup;
    ptr1 = head;
    /* Pick elements one by one */
    while (ptr1 != NULL && ptr1->next != NULL) {
        ptr2 = ptr1;
        // Compare the picked element with rest of the elements
        while (ptr2->next != NULL) {
            if (ptr1->data == ptr2->next->data) { // If duplicate then delete it 
                // sequence of steps is important here */
                dup = ptr2->next;
                ptr2->next = ptr2->next->next;
                delete(dup);
            }
            else // This is tricky
                ptr2 = ptr2->next;
        }
        ptr1 = ptr1->next;
    }
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
    // 2 ways to remove duplicates from a unsorted LL:-
    //removeDuplicates_unsorted(); //1. using 2 loops
    //listremoveDuplicates_Sorted(temp); //2.sort the list and then remove
    return 0;
}