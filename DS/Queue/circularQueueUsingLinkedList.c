#include <stdio.h>// https://www.youtube.com/watch?v=40Ttkii9NPA&t=232s
#include <stdlib.h>
struct node{
    int data;
    struct node* next;
};
struct node* front=0;
struct node* rear=0;
void enqueue(int x){
    struct node* new = (struct node*)malloc(sizeof(struct node));
    new->data = x;
    new->next = 0;
    if(rear == 0){//nothing in queue
        front = rear = new;//first when 1 node will be there which is new
        rear->next = front;//first node
    } else {
        rear->next = new;
        rear = new;
        rear->next = front;//as this is circular ll
    }
}
void dequeue(){
    struct node* temp;
    temp = front;
    if(front == 0 && rear == 0 ){//queue is empty
        printf("Queue is empty/underflow\n");
    } else if(front == rear){//only 1 node is there
        front = rear = 0;
        free(temp);
    } else {
        front = front->next;
        rear->next = front;//as the last node is goint to contain the address of first node
        free(temp);
    }
}
void peek(){
    if(front == 0 && rear == 0 ){//queue is empty
        printf("Queue is empty/underflow\n");
    } else {
        printf("Element at top: %d\n",front->data);
    }
}
void display(){
    if(front == 0 && rear == 0 ){//queue is empty
        printf("Queue is empty/underflow\n");
    } else {
        struct node* temp;
        temp = front;
        printf("Elements in Queue: ");
        while (temp->next!=front){
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