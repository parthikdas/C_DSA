#include <stdio.h> // done for right child same will be for left child
#include <stdlib.h>
typedef struct node{
    int data;
    struct node *left, *right;
} Node;
Node* createNewNode(int data){
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = data;
    newNode->left = newNode->right =  NULL;
    return newNode;
}
Node* insert(Node *root, int data){
    if(root == NULL) return createNewNode(data);
    else if(root->data > data) root->left = insert(root->left, data);
    else if(root->data < data) root->right = insert(root->right, data);
    return root;
}
void inOrder(Node *root){
    if(root == NULL) return;
    inOrder(root->left);
    printf("%d ",root->data);
    inOrder(root->right);
}
Node* search(Node* node, int data){
    if (node == NULL || node->data == data)// Base Cases: root is null or key is present at root
       return node;
    if (node->data < data)// Key is greater than root's key
       return search(node->right, data);
    return search(node->left, data);// Key is smaller than root's key
}
int main(){// 5 4 5 2 1 3
    Node* root = NULL;
    int n;
    scanf("%d",&n);
    for(int i=0;i<n;i++){
        int data;
        scanf("%d",&data);
        root = insert(root, data);
    }
    printf("Inorder traversal of the tree : ");
    inOrder(root);
    int key;
    printf("\nEnter the key whose right child you want to see : ");
    scanf("%d",&key);
    Node* found = search(root, key);
    if(found == NULL) printf("%d is not present in tree.", key);
    else if(found->data == key && found->right == NULL) printf("%d does not have a right child.", key);
    else printf("%d's right child is %d.", key, found->right->data);
    return 0;
}