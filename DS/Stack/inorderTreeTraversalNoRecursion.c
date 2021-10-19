#include <stdio.h>
#include <stdlib.h>
struct tNode1{
  int data;
  struct tNode1 *left;
  struct tNode1 *right;
};
#define N 5
int top=-1;
struct tNode1 *arr[N];
void push(struct tNode1 *x){
 if(top==N-1) return;
  else {arr[++top]= x;}
}
int isEmpty(){
  return top==-1;
}
struct tNode1* pop(){
  if(top==-1) return 0;
  else return arr[top--];
}
struct tNode1* peek(){
 if(top==-1) return 0;
  else return arr[top];
}
void inOrder(struct tNode1 *root) {  
  struct tNode1 *current = root;// set current to root of binary tree
  int done = 0;
 
  while (!done) {
    if(current !=  NULL) {// Reach the left most tNode of the current tNode
      /* place pointer to a tree node on the stack before traversing
        the node's left subtree */
      push( current);                                              
      current = current->left; 
    }
    /* backtrack from the empty subtree and visit the tNode
       at the top of the stack; however, if the stack is empty,
      you are done */
    else {
      if (!isEmpty())
      {
        current = pop();
        printf("%d ", current->data);
        /* we have visited the node and its left subtree.
          Now, it's right subtree's turn */
        current = current->right;
      }
      else
        done = 1;
    }
  }
}    
struct tNode1* newNode(int n) {
    struct tNode1* new = (struct tNode1*)malloc(sizeof(struct tNode1));
    new->data = n;
    new->left = NULL;
    new->right = NULL;
    return new;
}
int main()
{
  int n;
  scanf("%d",&n);
  struct tNode1 *root = newNode(n);
  scanf("%d",&n);
  root->left = newNode(n);
  scanf("%d",&n);
  root->right = newNode(n);
  scanf("%d",&n);
  root->left->left = newNode(n);
  scanf("%d",&n);
  root->left->right = newNode(n);
 
  inOrder(root);
 
  return 0;
}