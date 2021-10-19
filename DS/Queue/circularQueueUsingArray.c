/* https://www.youtube.com/watch?v=dn01XST9-bI
Drawback:- suppose we have queue 1 2 3 4 5 and N is 5 so its is at its limit
                           index:0 1 2 3 4 and we do dequeue() 3 times so 
the queue becomes    4 5
        index: 0 1 2 3 4
so now you cannot insert but still you have 0,1,2 so in that case memory wastage happens so use circular queue see jenny video
*/
//to avoid above problem we use circular queue
#include <stdio.h>
#define N 5
int queue[N];
int front = -1;
int rear = -1;
// void enqueue(int x) {
//     if(front == -1 && rear == -1) { //empty
//         front = rear = 0;
//         queue[rear] = x;//entering from rear
//     } else if((rear+1)%N == front) { //full
//         printf("Queue is full/Overflow\n");//above statement understand from youtube video
//     } else {
//         rear = (rear+1) % N;
//         queue[rear] = x;
//     }
// }
int isFull(){
    return ((rear+1)%N == front);
}
int isEmpty(){
    return (front == -1 && rear == -1);//can't do rear==front as when 1 element is left this would be true
}
void enqueue(int x) {
    if(isFull()) {
        printf("Queue is full/Overflow\n");//above statement understand from youtube video
    } else {
        rear = (rear+1) % N;
        queue[rear] = x;
    }
}
void dequeue() {
    if(isEmpty()) {
        printf("Queue is empty/Underflow\n");
    } else if(front == rear) {//means only 1 element is left and after this deletion queue is empty
        front = rear = -1;
    } else {
        printf("Deleted element: %d\n",queue[front]);
        front = (front+1) % N;
    }
}
void display() {
    if(front == -1 && rear == -1) {
        printf("Queue is empty\n");
    } else {
        int i = front;
        while (i!=rear) {
           printf("%d ",queue[i]);
           i = (i+1) % N;
        }
        printf("%d\n",queue[rear]);
    }
}
void peek() {
    if(front == -1 && rear == -1) {
        printf("Queue is empty\n");
    } else {
        printf("Data at front: %d\n",queue[front]);
    }
}
int main() {
    enqueue(2);
    enqueue(-1);
    enqueue(5);
    enqueue(6);
    enqueue(7);//now i entered 5 values so list is full
    display();
    dequeue();//removed from 0 index
    dequeue();//removed from 1 index
    display();
    enqueue(99);//enqueue puts the value in 0
    enqueue(88);//enqueue puts the value in 1
    display();
    peek();
    return 0;
}