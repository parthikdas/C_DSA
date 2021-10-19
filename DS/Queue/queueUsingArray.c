#include <stdio.h>
#define N 10
int queue[N];//or use int *queue = (int*)malloc(N*sizeof(int));
int front = -1;
int rear = -1;
// void enqueue(int x) {
//     if(rear == N-1) { //full
//         printf("Overflow\n");
//     } else if(front == -1 && rear == -1) { //empty
//         front = rear = 0;
//         queue[rear] = x;//entering from rear
//     } else {//queue is not empty not full it has some data 
//         queue[++rear] = x;//dont touch front here , from now rear will at last and front is at front
//     }
// }
int isFull(){
    return rear == N-1;
}
int isEmpty(){
    return (front == -1 && rear == -1);//can't do rear==front as when 1 element is left this would be true
}
void enqueue(int x) {
    if(isFull()) { //full
        printf("Overflow\n");
        return;
    if(front == -1) front++;
    queue[++rear] = x;//dont touch front here , from now rear will at last and front is at front
}
void dequeue() {
    if(isEmpty()) {
        printf("Queue is empty/Underflow\n");
    } else if(front == rear) {//means only 1 element is left and after this deletion queue is empty
        front = rear = -1;
    } else {
        printf("Deleted element: %d\n",queue[front]);
        front++;//we can delete from front only in queue
        //return queue[front++];//make deueue() as int do both things in 1 line, after return the value it will front+1 
    }
}
void peek() {
    if(isEmpty()) {
        printf("Queue is empty\n");
        return;
    
    printf("Data at front: %d\n",queue[front]);
}
void display() {
    if(front == -1 && rear == -1) {
        printf("Queue is empty\n");
    } else {
        int i = front;
        for(i=front;i<=rear;i++) {
            printf("%d ",queue[i]);
        }
        printf("\n");
    }
}
int main() {
    enqueue(2);
    enqueue(5);
    enqueue(-1);
    display();
    peek();
    dequeue();
    peek();
    display();
    return 0;
}
/*
Drawback:- suppose we have queue 1 2 3 4 5 and N is 5 so its is at its limit
                           index:0 1 2 3 4 and we do dequeue() 3 times so 
the queue becomes    4 5
        index: 0 1 2 3 4
so now you cannot insert but still you have 0,1,2 so in that case memory wastage happens so use circular queue see jenny video
*/