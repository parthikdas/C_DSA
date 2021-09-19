/*
Write a program that would read an Arithmetic equation
Check for its correction and store it using appropriate structure program should also be able to evaluate the expression by reading a set of inputs for the variables in the expression
*/
//it takes only postfix expression
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
//TREE
struct tree{
    char data;// to store the variables
    int val;// to store the values
    struct tree *left, *right;
};
typedef struct tree Tree;
Tree* create_new_node(char data){
    Tree *new_node = (Tree*)malloc(sizeof(Tree));
    new_node->data = data;
    new_node->left = new_node->right = NULL;
    return new_node;
}
void preOrder(Tree* node){
    if(node == NULL) return;
    printf("%c ",node->data);
    preOrder(node->left);
    preOrder(node->right);
}
//TREE ENDS
//STACK
struct stack{
    Tree *data;//Stack is made up of tree nodes
    struct stack *next;
};
typedef struct stack Stack;
Stack *head;
int isEmpty(){
    return head == NULL;
}
void push(Tree* data){
    Stack *new_node = (Stack*)malloc(sizeof(Stack));
    new_node->data = data;
    if(isEmpty()) {
        head = new_node;
        return;
    }
    new_node->next = head;
    head = new_node;
}
Tree* pop(){
    if(isEmpty()) return NULL;
    Stack* temp = head;
    head = head->next;
    return temp->data;
}
//STACK ENDS
int isOperand(char c){
    return ((c>='a' && c<='z')||(c>='A' && c<='Z'));
}
void make_expression_tree(char* s){
    for(int i=0;i<strlen(s);i++){
        if(isOperand(s[i])) push(create_new_node(s[i]));//if its a operand make it a node and push
        else {// if its a operator
            Tree* root = create_new_node(s[i]);
            root->right = pop();
            root->left = pop();
            push(root);
        }
    }
}
//evaluate
int compute(int A, int B, char ch){
    int res = 0;
    if(ch == '+') res = A+B;
    else if(ch == '-') res = A-B;
    else if(ch == '*') res = A*B;
    else if(ch == '/') res = A/B;
    return res;
}
int evaluate(Tree* node){
    if(node==NULL) return 0;
    if(isOperand(node->data)) return node->val;
    int A = evaluate(node->left);
    int B = evaluate(node->right);
    int ans = compute(A,B,node->data);
    return ans;
}
//Function to take inputs
void inorderInput(Tree* node){
    if(node==NULL) return;
    inorderInput(node->left);
    if(isOperand(node->data)){
        printf("Enter the value of %c : ",node->data);
        scanf("%d",&node->val);
    }
    inorderInput(node->right);
}
int main(){
    printf("Give your postfix expression : ");
    char s[100];
    scanf("%s",s);
    make_expression_tree(s);//made the string to expression tree
    //See the tree
    printf("Pre-order traversal of expression tree : ");
    preOrder(head->data);
    int t;
    printf("\nEnter Number of testcases : ");
    scanf("%d",&t);
    while(t--){
        //Take the inputs
        printf("\nPlease enter number for the variables\n");
        inorderInput(head->data);
        //evaluation
        //as head of stack is the root of the tree
        printf("\nSolution of the above expression is : %d\n\n",evaluate(head->data));
    }
    return 0;
}