#include <stdio.h>
#include <stdlib.h>
typedef struct node{
	int data;
	struct node *next;
} Node;
// To check the list is empty or not
int isEmpty(Node *head){
	return head == NULL;
}
// To insert in list
void insert(Node **head, int data){
	Node *newNode = (Node*)malloc(sizeof(Node));
	newNode->data = data;
	if(isEmpty(*head)){
		*head = newNode;
		return;
	}
	Node* temp = *head;
	while(temp->next){
		temp = temp->next;
	}
	temp->next = newNode;
}
// To display the List
void display(Node *head){
	if(isEmpty(head)) return;
	Node* temp = head;
	while(temp){
		printf("%d->",temp->data);
		temp = temp->next;
	}
	printf("\n");
}
// To merge 2 sorted lists
Node* sortedMerge(Node *a, Node *b){
	Node* ans = NULL;
	while(a!=NULL && b!=NULL){
		if(a->data > b->data){
			insert(&ans, b->data);
			b = b->next;
		} else {
			insert(&ans, a->data);
			a = a->next;
		}
	}
	while(a!=NULL){ // for remaining elements
		insert(&ans, a->data);
		a = a->next;
	}
	while(b!=NULL){ // for remaining elements
		insert(&ans, b->data);
		b = b->next;
	}
	return ans;
}
// Split the nodes of the given list into front and back halves and return the two lists using the reference parameters.
// If the length is odd, the extra node should go in the front list. Uses the fast/slow pointer strategy.
void splitList(Node *source, Node **frontRef, Node **backRef){
	Node *slow = source;
	Node *fast = source->next;
	// Advance 'fast' two nodes, and advance 'slow' one node
	 while (fast != NULL){
        fast = fast->next;
        if (fast != NULL){
            slow = slow->next;
            fast = fast->next;
        }
    }
    // 'slow' is before the midpoint in the list, so split it in two at that point
    *frontRef = source;
    *backRef = slow->next;
    slow->next = NULL;
}
// To sort the List
void mergeSort(Node **head){
	// base case: length 0 or 1
	if(isEmpty(*head) || (*head)->next==NULL) return;
	Node *a, *b;
	// split the list into a and b sublists
	splitList(*head, &a, &b);
	// recurisvely sort the sublists
	mergeSort(&a);
	mergeSort(&b);
	// ans = merge the two lists together
	*head = sortedMerge(a, b);
	//display(*head);
}
// Driver function
int main(){
	Node *head = NULL;
	int n, i;
	scanf("%d",&n);
	for(i=0;i<n;i++){
		int data;
		scanf("%d",&data);
		insert(&head, data);
	}
	printf("Before Sorting : ");
	display(head);
	mergeSort(&head);
	printf("After Sorting : ");
	display(head);
}