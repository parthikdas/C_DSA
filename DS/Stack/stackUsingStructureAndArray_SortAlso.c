// C program for array implementation of stack
#include <limits.h>
#include <stdio.h>
#include <stdlib.h>
 
// A structure to represent a stack
struct Stack {
    int top;
    unsigned capacity;
    int* array;
};
 
// function to create a stack of given capacity. It initializes size of
// stack as 0
struct Stack* createStack(unsigned capacity)
{
    struct Stack* stack = (struct Stack*)malloc(sizeof(struct Stack));
    stack->capacity = capacity;
    stack->top = -1;
    stack->array = (int*)malloc(stack->capacity * sizeof(int));
    return stack;
}
 
// Stack is full when top is equal to the last index
int isFull(struct Stack* stack)
{
    return stack->top == stack->capacity - 1;
}
 
// Stack is empty when top is equal to -1
int isEmpty(struct Stack* stack)
{
    return stack->top == -1;
}
 
// Function to add an item to stack.  It increases top by 1
void push(struct Stack* stack, int item)
{
    if (isFull(stack))
        return;
    stack->array[++stack->top] = item;
    printf("%d pushed to stack\n", item);
}
 
// Function to remove an item from stack.  It decreases top by 1
int pop(struct Stack* stack)
{
    if (isEmpty(stack))
        return INT_MIN;
    return stack->array[stack->top--];
}
 
// Function to return the top from stack without removing it
int peek(struct Stack* stack)
{
    if (isEmpty(stack))
        return INT_MIN;
    return stack->array[stack->top];
}
 
//Functions to sort a stack
void sortedInsert(struct Stack *stack,int x){//https://www.geeksforgeeks.org/sort-a-stack-using-recursion/
//// Recursive function to insert an item x in sorted way
 if(isEmpty(stack) || x>stack->array[stack->top]) {// Base case: Either stack is empty or newly inserted
   push(stack,x);                                  // item is greater than top (more than all existing)
  return;
    }
 
    // If top is greater, remove the top item and recur
    int temp = pop(stack);
    sortedInsert(stack, x);
 
    // Put back the top item removed earlier
    push(stack, temp);
}
void sort(struct Stack *stack){// Function to sort stack
  if(!isEmpty(stack)){// If stack is not empty
   int x = pop(stack); // Remove the top item
    sort(stack);// Sort remaining stack
    sortedInsert(stack,x);// Push the top item back in sorted stack
  }
}
//Function to display
void display(struct Stack *stack){
    printf("stack elements: ");
    for(int i=stack->top;i>=0;i--) {
        printf("%d ",stack->array[i]);
    }
    printf("\n");
}
// Driver program to test above functions
int main()
{
    struct Stack* stack = createStack(100);
 
    push(stack, 30);
    push(stack, 10);
    push(stack, 20);
    push(stack, 80);
    push(stack, 5);
    display(stack);
    printf("%d popped from stack\n", pop(stack));
    display(stack);
    sort(stack);
    display(stack);
    return 0;
}