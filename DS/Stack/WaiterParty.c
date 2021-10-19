/*
You are a waiter at a party. There are N stacked plates on pile Ao .
Each plate has a number written on it. Then there will be q iterations. In i-th iteration, you start picking up the plates in Ai-1 from the top one by one and check whether the number written on the plate is divisible by the -th prime. 
If the number is divisible, you stack that plate on pile Bi . 
Otherwise, you stack that plate on pile Ai . After Q iterations, plates can only be on pile B1,B2,......Bq, Aq . 
Output numbers on these plates from top to bottom of each piles in order of B1,B2,....Bq, Aq .  
Input Format
The first line contains two space separated integers, N and Q. 
The next line contains N space separated integers representing the initial pile of plates, i.e., Ao .
The leftmost value represents the bottom plate of the pile.
Constraints
1&lt;=N&lt;=5*10^4
2&lt;=number(i)&lt;=10^4
1&lt;=Q&lt;=1200
Output Format
Output N lines. Each line contains a number written on the plate. Printing should be done in the order defined above.


See waiter question in hackerank
*/
#include <stdio.h>
#include <stdlib.h>
struct Stack {
    int top;
    unsigned capacity;
    int* array;
};
struct Stack* createStack(unsigned capacity)
{
    struct Stack* stack = (struct Stack*)malloc(sizeof(struct Stack));
    stack->capacity = capacity;
    stack->top = -1;
    stack->array = (int*)malloc(stack->capacity * sizeof(int));
    return stack;
}
int isFull(struct Stack* stack)
{
    return stack->top == stack->capacity - 1;
}
int isEmpty(struct Stack* stack)
{
    return stack->top == -1;
}
void push(struct Stack* stack, int item)
{
    if (isFull(stack))
        return;
    stack->array[++stack->top] = item;
    //printf("%d pushed to stack\n", item);
}
int pop(struct Stack* stack)
{
    if (isEmpty(stack))
        return -100;
    return stack->array[stack->top--];
}
int peek(struct Stack* stack)
{
    if (isEmpty(stack))
        return -100;
    return stack->array[stack->top];
}
int primeNo(int n){
    if(n==2 || n==3) return 1;
    int i;
    for( i=2;i*i<=n;i++){
        if(n%i==0) return 0;
    }
    return 1;
}
int main(){
    int n,q,i;
    scanf("%d%d",&n,&q);
    struct Stack* head = createStack(n);
    struct Stack* a = createStack(n);
    struct Stack* b = createStack(n);
    int* ans = (int*)malloc(sizeof(int)*n);
    for(i=0;i<n;i++){
        int data;
        scanf("%d",&data);
        push(head,data);
    }
    int prime[q],k=0;
    for(i=2;i<=1200 && k<q;i++){//generating prime number array of size q and 1200 given in constraints
        if(primeNo(i)) prime[k++] = i; 
    }
    k=0;
    if(q==1){
        while(isEmpty(head)==0){
            int temp = pop(head);
            if(temp%prime[0]==0) push(b,temp);
            else push(a,temp);
        }
        while(isEmpty(b)==0){
            ans[k++] = pop(b);
        }
        while(isEmpty(a)==0){
            ans[k++] = pop(a);
          }
          for(i=0;i<n;i++) printf("%d\n",ans[i]);//it will be in correct order
    }
    else{
      while(q-->0){
        while(isEmpty(head)==0){
            int temp = pop(head);
            if(temp%prime[q]==0) push(b,temp);
            else push(a,temp);
        }
       	while(isEmpty(b)==0){
            ans[k++] = pop(b);
        }
       	while(isEmpty(a)==0){
            push(head,pop(a));
        }
      }
   	  for(i=n-1;i>=0;i--) printf("%d\n",ans[i]);//it will be in reverse order
    }
    return 0;
}
 