#include <stdio.h>
#include <stdlib.h>
struct node{
    int data;
    struct node *left, *right;
};
typedef struct node Node;
Node* create_node(int data){
    Node *temp = (Node*)malloc(sizeof(Node));
    temp->data = data;
    temp->left = temp->right =NULL;
    return temp;
}
//All traversals
void preOrder(Node* node){
    if(node == NULL) return;
    printf("%d ",node->data);
    preOrder(node->left);
    preOrder(node->right);
}
void inOrder(Node* node){
    if(node == NULL) return;
    inOrder(node->left);
    printf("%d ",node->data);
    inOrder(node->right);
}
void postOrder(Node* node){
    if(node == NULL) return;
    postOrder(node->left);
    postOrder(node->right);
    printf("%d ",node->data);
}
void printCurrentLevel(Node* node, int level){//Print nodes at a current level
    if(node==NULL) return;
    if(level == 1) printf("%d ",node->data);
    else if(level > 1){
        printCurrentLevel(node->left, level-1);
        printCurrentLevel(node->right, level-1);
    }
}
int height(Node* node){//Compute the "height" of a tree -- the number of nodes along the longest path from the root node down to the farthest leaf node.
    if (node==NULL)
        return 0;
    else {
        // compute the height of each subtree
        int lheight = height(node->left);
        int rheight = height(node->right);
        if (lheight > rheight)//use the larger one
            return(lheight+1);
        else return(rheight+1);
    }
}
void levelOrder(Node* node){
    int h = height(node), i;
    for(i=1;i<=h;i++){
       printCurrentLevel(node, i);//we will send the node and level
    }
}
int main() {
//     1
//    / \
//   2   3
//  / \
// 4   5
    Node* root = create_node(1);
    root->left = create_node(2);
    root->right = create_node(3);
    root->left->left = create_node(4);
    root->left->right = create_node(5);
    printf("Pre order traversal of the tree : ");
    preOrder(root);
    printf("\nIn order traversal of the tree : ");
    inOrder(root);
    printf("\nPost order traversal of the tree : ");
    postOrder(root);
    printf("\nLevel order traversal of the tree : ");
    levelOrder(root);
    printf("\nHeight of tree is : %d",height(root));
    return 0;
}
