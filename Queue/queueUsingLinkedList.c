#include <stdio.h>
#include <stdlib.h>
struct node{
    int data;
    struct node* next;
};
struct node* front;
struct node* rear;
int isEmpty(){
    return front == NULL && rear == NULL ;
}
void enqueue(int x){
    struct node* new = (struct node*)malloc(sizeof(struct node));
    new->data = x;
    if(isEmpty()){//nothing in queue
        front = rear = new;//first when 1 node will be there which is new
    } else {
        rear->next = new;
        rear = new;
    }
}
void dequeue(){
    struct node* temp;
    temp = front;
    if(isEmpty()){//queue is empty
        printf("Queue is empty/underflow\n");
    } else if(front == rear){//only 1 node is there
        front = rear = NULL;
        free(temp);
    } else {
        front = front->next;
        free(temp);
    }
}
void peek(){
    if(isEmpty()){//queue is empty
        printf("Queue is empty/underflow\n");
    } else {
        printf("Element at top: %d\n",front->data);
    }
}
void display(){
    if(isEmpty()){//queue is empty
        printf("Queue is empty/underflow\n");
    } else {
        struct node* temp;
        temp = front;
        printf("Elements in Queue: ");
        while (temp->next!=NULL){
            printf("%d ",temp->data);
            temp = temp->next;
        }
        printf("%d\n",temp->data);
    }
}
int main() {
    enqueue(1);
    enqueue(-9);
    enqueue(2);
    enqueue(3);
    enqueue(-4);
    enqueue(5);
    display();
    dequeue();
    peek();
    display();
    return 0;
}