#include <stdio.h>
#include <stdlib.h>
typedef struct node{
    int data;
    struct node *left, *right;
} Node;
Node* newNode(int data){
    Node* newN = (Node*)malloc(sizeof(Node));
    newN->data = data;
    newN->left = newN->right = NULL;
    return newN;
}
//----------------------------------------------------
/* To see every step of Right Rotation
        4                       2   4           2
       / \                     / \ / \         / \
      2   6  -> x=4,y=2  ->   1   3   6   ->  1   4
     / \ / \                         / \         / \
    1  3 5  7                       5  7        3   6
                                                   / \
                                                  5  7
*/
Node* zigRotate(Node* x){ // Function to right rotate, returns the new root.
    Node* y = x->left;
    x->left = y->right;
    y->right = x;
    return y;
}
//----------------------------------------------------
/* To see every step of Right Rotation
        4                       4   6            6
       / \                     / \ / \          / \
      2   6  -> x=4,y=6  ->   2   5   7   ->   4   7
     / \ / \                 / \              / \
    1  3 5  7               1  3             2   5
                                            / \
                                           1  3
*/
Node* zagRotate(Node* x){ //Function to left rotate, returns the new root.
    Node* y = x->right;
    x->right = y->left;
    y->left = x;
    return y;
}
//----------------------------------------------------
void preOrder(Node* root){
    if(root == NULL) return;
    printf("%d ",root->data);
    preOrder(root->left);
    preOrder(root->right);
}
int main(){
    //     4
    //    / \
    //   2   6
    //  / \ / \
    // 1  3 5  7
    Node *root = newNode(4);
    root->left = newNode(2);
    root->right = newNode(6);
    root->left->left = newNode(1);
    root->left->right = newNode(3);
    root->right->left = newNode(5);
    root->right->right = newNode(7);
    printf("Preorder traversal of the splay tree : ");
    preOrder(root);
    root = zagRotate(root);
    printf("\nPreorder traversal of the modified splay tree : ");
    preOrder(root);
}