#include <stdio.h> 
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
    if (node == NULL) return node; // key is present at root
    else if((node->left && node->left->data == data) || (node->right && node->right->data == data))  return node; // its in left or right child
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
    printf("\nEnter the key whose sibling you want to see : ");
    scanf("%d",&key);
    if(root->data == key) printf("root don't have sibling.");
    else {
        Node* found = search(root, key);
        if(found == NULL) printf("%d is not present in tree.", key);
        else if((found->left->data == key && found->right == NULL) ||   // if its in left child and it dont have right child
                (found->right->data == key && found->left == NULL))     // if its in right child and it dont have left child
                printf("%d does not have a sibling.", key);
        else {// its there
            if(found->left->data == key) printf("%d is sibling of %d.", found->right->data, key);
            else if(found->right->data == key) printf("%d is sibling of %d.", found->left->data, key);
        }
    }
    return 0;
}