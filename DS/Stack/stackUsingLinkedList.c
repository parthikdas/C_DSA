#include <stdio.h>
#include <stdlib.h>
struct stack{
 int data;
  struct stack *next;
};
struct stack *head;
int isEmpty(){
  return head == NULL;
}
void push(int data){
    struct stack* temp = (struct stack*)malloc(sizeof(struct stack));
    temp->data = data;
    if(isEmpty()) {
        head = temp;
        return;
    }
  
   temp->next = head;
   head = temp;
}
void pop(){
  if(isEmpty()) return;
  printf("Deleted element is %d\n",head->data);
  struct stack *temp = head;
  head=head->next;
  free(temp);
}
int peek(){
  if(isEmpty()) return;
  return head->data;
}
void display(){
 struct stack* temp = (struct stack*)malloc(sizeof(struct stack));
  temp=head;
  printf("Elements in stack: ");
  while(temp!=NULL){
   printf("%d ",temp->data);
   temp=temp->next;
  }
  printf("\n");
}
int main() {
    for(int i=1;i<=10;i++) {
        push(i);
    }
    display();
    pop();
    //display(); this one is illegal
    return 0;
}
