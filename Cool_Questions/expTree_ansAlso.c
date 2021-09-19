/* A strict binary tree that is used to re-present mathematical expressions are called as expression trees. Each 
internal note of expression tree holds an operator and each leaf node holds a operands.
lets say the postfix exp is 359+2*+ so the tree is  +
                                                   / \
                                                  3   *
                                                     / \
                                                    +   2
                                                   / \
                                                  5   9
in-order(infix exp)(for above eg: 3+5+9*2),pre-order(prefix exp)(for above eg: +3*+592),post-order(postfix exp)(for above its in postfix only)
Now for constructing expression tree we use a stack, we look through input expression and do following for every character.
1. If character is operand push in ontto stack.
2. If character is operator pop 2 values from stack make them its child and puch current node again.
At the end, only one element of stack will be root of expression of tree.(this we did in make_expression_tree() and the head of the stack is the root node of the tree)
*/
/*In this program to make a expression tree you need a postfix expression */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
//TREE
struct tree{
    char data;
    struct tree *left, *right;
};
typedef struct tree Tree;
Tree* create_new_node(char data){
    Tree *new_node = (Tree*)malloc(sizeof(Tree));
    new_node->data = data;
    new_node->left = NULL;
    new_node->right = NULL;
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
    return ((c>='a' && c<='z')||(c>='A' && c<='Z')||(c>='1' && c<='9'));
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
    if(isOperand(node->data)) return node->data-48;//making it a int before returning as they are always b/w 1-9
    int A = evaluate(node->left);
    int B = evaluate(node->right);
    int ans = compute(A,B,node->data);
    return ans;
}
int main(){
    char s[100];
    scanf("%s",s);
    make_expression_tree(s);//made the string to expression tree
    printf("Pre-order traversal of expression tree : ");
    preOrder(head->data);
    //so evaluate can't be done on a exp having a-z only can be done with 1-9
    printf("\nSolution of the above expression is : %d\n",evaluate(head->data));//as head of stack is the root of the tree
    return 0;
}