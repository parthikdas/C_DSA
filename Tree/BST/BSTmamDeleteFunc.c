#include <stdio.h>
#include <stdlib.h>
struct node{
    int data;
    struct node *left, *right;
};
struct node* new_node(int data){
    struct node *temp = (struct node*)malloc(sizeof(struct node));
    temp->data = data;
    temp->left = temp->right =NULL;
    return temp;
}
struct node* insert(struct node* node, int data){
    if(node == NULL) return new_node(data);
    if(data < node->data) node->left = insert(node->left, data);
    else if(data>node->data) node->right = insert(node->right, data);
    return node;
}
void preOrder(struct node* node){
    if(node == NULL) return;
    printf("%d ",node->data);
    preOrder(node->left);
    preOrder(node->right);
}
struct node* min(struct node* node) {
    struct node* temp = node;
    while (temp && temp->left != NULL) temp = temp->left;
    return temp;
}
struct node* delete(struct node* node, int data){// returns the new root of the tree
    if(node == NULL) return node;
    if(data<node->data) node->left = delete(node->left,data);
    else if(data>node->data) node->right = delete(node->right,data);
    else if(node->left && node->right){// if the one to be deleted has 2 children
        struct node *temp = min(node->right);
        node->data = temp->data;
        node->right = delete(node->right,temp->data);
    }else{//one child or no child case
        struct node *temp;
        if(node->left == NULL) temp = node->right;
        else if(node->right == NULL) temp = node->left;
        free(node);
        return temp;
    }
    return node;
}
int main() {
//   20             20                  3               3
//   /              /                   \                \    
//  3              3                    10                12    
//  \        ->    \        ->          / \     ->       / \    
//   10             10                 7  12            7   15
//   / \            / \                \   \             \
//  7   12         7  12                8   15            8
//   \   \         \   \
//   8   15        8    15
//     \
//      9
  // Input for the above tree : 8 20 3 10 7 8 9 12 15
  struct node* root;
    int n,i;
    scanf("%d",&n);
    for(i=0;i<n;i++){
        int data;
        scanf("%d",&data);
        root = insert(root,data);
    }
    printf("Inorder Traversal: ");
    preOrder(root);
    
    root = delete(root,9);//no child
    printf("\nAfter deleting preOrder Traversal: ");
    preOrder(root);

    root = delete(root,20);//one child
    printf("\nAfter deleting preOrder Traversal: ");
    preOrder(root);
    
    root = delete(root,10);//two children
    printf("\nAfter deleting preOrder Traversal: ");
    preOrder(root);
    return 0;
}
