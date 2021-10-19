#include <stdio.h>
#include <stdlib.h>
typedef struct node{
    int data;
    struct node *left, *right;
} Node;
Node* root;//if i not made this global then head is becoming 1 and the whole tree is gone
Node* new_node(int data){
    Node *temp = (Node*)malloc(sizeof(Node));
    temp->data = data;
    temp->left = temp->right =NULL;
    return temp;
}
Node* insert(Node* node, int data){//A new data is always inserted at the leaf.We start searching a data from the root until we hit a leaf node.Once a leaf node is found, the new node is added as a child of the leaf node. 
    if(node == NULL) return new_node(data);//root case
    if(data < node->data) node->left = insert(node->left, data);
    else if(data>node->data) node->right = insert(node->right, data);
    return node;//return the (unchanged) node pointer
}
void preOrder(Node* node){
    if(node == NULL) return;
    printf("%d ",node->data);
    preOrder(node->left);
    preOrder(node->right);
}
int lca(Node *root, int v1, int v2){
    //Decide if you have to call rekursively
    //Samller than both
    if(root->data < v1 && root->data < v2){
        return lca(root->right,v1,v2);
    }
    //Bigger than both
    if(root->data > v1 && root->data > v2){
        return lca(root->left,v1,v2);
    }

    //Else solution already found
    return root->data;
}
int main() {
//     4
//    / \
//   2   7
//  / \  /
// 1  3 6
    root = insert(root,4);
    insert(root,2);
    insert(root,7);
    insert(root,1);
    insert(root,3);
    insert(root,6);
    int v1 = 1, v2 = 7;
    printf("Lowest Common Ancestor of %d and %d is %d\n",v1,v2,lca(root, v1, v2));
    return 0;
}