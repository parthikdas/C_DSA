#include <stdio.h> //https://youtu.be/VmsTAVpz0xo
#include <stdlib.h>
#define maxSize 100
int stack[maxSize];
int top = -1;
int isFull();
int isEmpty();
void display();
void push() {
	if(isFull()) {
		printf("Overflow\n");
		return;
	} else {
		int data;
		printf("Enter data to be pushed: ");
		scanf("%d",&data);
		stack[++top] = data;
		display();
	}
}
int pop() {
	if(isEmpty()) {
		printf("Stack is empty\n");
		return -10;
	} else {
		return stack[top--];
	}
}
int peek() {
	if(isEmpty()) {
		printf("Stack is empty\n");
		return -10;
	} else {
		return stack[top];
	}
}
void display() {
	int i;
	printf("Elements in Stack: ");
	for(i=top;i>=0;i--) {
		printf("%d ",stack[i]);
	}
	printf("\n");
	return;
}
int isFull() {
	return top == maxSize-1;
}
int isEmpty() {
	return top == -1;
}
void reverse(int i,int n)//recursive
{
  if(i>n)
    return ;
  int temp=stack[i];
  stack[i]=stack[n];
  stack[n]=temp;
  reverse(i+1,n-1);
}
int main() {
	while(1) {
		printf("----------------------------\n");
		printf("Press 1 to push element in Stack\n");
		printf("Press 2 to pop element from Stack\n");
		printf("Press 3 to get topmost element from Stack\n");
		printf("Press 4 to display Stack\n");
		printf("Press 5 to check Stack is full or no\n");
		printf("Press 6 to check Stack is empty or not\n");
		printf("Press 7 to exit\n");
		int choice;
		scanf("%d",&choice);
		switch(choice) {
			case 1: push();
					break;
			case 2: {
						int data = pop();
						if(data != -10) printf("%d is popped\n",data);
						break;
					}
			case 3: {
						int data = peek();
						if(data != -10) printf("%d is at top of Stack\n", data);
						break;
					}
			case 4: display();
					break;
			case 5: if(isFull()) printf("Stack is full\n");
					else printf("Stack is not full\n");
					break;
			case 6: if(isEmpty()) printf("Stack is empty\n");
					else printf("Stack is not empty\n");
					break;
			case 7: reverse(0,top);
			case 8: exit(1);
			default:printf("Wrong choice\n");
					break;
		}
	}
	return 0;
}