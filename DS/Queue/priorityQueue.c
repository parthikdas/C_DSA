#include <stdio.h>
#include <stdlib.h>
struct node{
  int data;
  int priority;
  struct node* next;
};
typedef struct node Node;
Node* head;
Node* newNode(int n,int p){
 Node* temp = (Node*)malloc(sizeof(Node));
  temp->data = n;
  temp->priority = p;
  temp->next = NULL;
  return temp;
}
int isEmpty(){
  return head==NULL;
}
void enque(int d,int p){
    Node* temp = newNode(d, p);
    if(head == NULL) {
        head = temp;
        return;
    }
    Node* start = (head);//for traversal
    if (head->priority > p) {
        temp->next = head;
        head = temp;
    } else {
         while (start->next != NULL && start->next->priority < p) {
            start = start->next;
        }
        temp->next = start->next;
        start->next = temp;
    }
}
void deque(){
  if(isEmpty()) {
    printf("Underflow\n");return;
  }
  Node* temp = head;
  head = head->next;
  free(temp);
}
void display(){
  if(isEmpty()) {
    printf("Underflow\n");return;
  }
  Node*temp = (Node*)malloc(sizeof(Node));
  temp = head;
  while(temp!=NULL){
   printf("%d %d->",temp->priority,temp->data); 
    temp=temp->next;
  }
  printf("\n");
}
int main() {
  while(1){
   int ch;
    scanf("%d",&ch);
    if(ch==0) return 0;
    else if(ch==1){
      int p,n;
      scanf("%d %d",&p,&n);
      enque(n,p);
    }
    else if(ch==2) deque();
    else if(ch==3) display();
  }
	return 0;
}
/*
1
3 4
1
2 3
1
3 5
3
2
3
2
3
0
output:
2 3->3 4->3 5->
3 4->3 5->
3 5->
*/