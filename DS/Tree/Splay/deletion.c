/*
Following are the different cases to delete a key k from splay tree.

If Root is NULL: We simply return the root.
Else Splay the given key k. If k is present, then it becomes the new root. If not present, then last accessed leaf node becomes the new root.
If new root’s key is not same as k, then return the root as k is not present.
Else the key k is present.
Split the tree into two trees Tree1 = root’s left subtree and Tree2 = root’s right subtree and delete the root node.
Let the root’s of Tree1 and Tree2 be Root1 and Root2 respectively.
If Root1 is NULL: Return Root2.
Else, Splay the maximum node (node having the maximum value) of Tree1.
After the Splay procedure, make Root2 as the right child of Root1 and return Root1.
*/
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
// Function to zig rotate, returns the new root.
Node* rightRotate(Node* x){
    Node* y = x->left;
    x->left = y->right;
    y->right = x;
    return y;
}
//Function to zag rotate, returns the new root.
Node* leftRotate(Node* x){
    Node* y = x->right;
    x->right = y->left;
    y->left = x;
    return y;
}
// This function brings the key at root if key is present in tree.
// If key is not present, then it brings the last accessed item at
// root.  This function modifies the tree and returns the new root
Node* splay(Node* root, int data){
    //Base cases: root is NULL or data is present at the root
    if(root == NULL || root->data == data) return root;
    if(root->data > data){// element present at left sub-tree
        // element is not in tree, we are done
        if(root->left == NULL) return root;
            
        if(root->left->data > data){// Zig Zig Rotate (Right Right)
            // First recursively bring the key as root of left-left
            root->left->left = splay(root->left->left, data);
            // Do first rotation for root
            root = rightRotate(root);
        }
        else if(root->left->data < data){// Zag Zig Rotate (Left Right Rotate)
            // First recursively bring the key as root of left-right
            root->left->right = splay(root->left->right, data);
            
            // Do first rotation for root->left
            if (root->left->right != NULL)
                root->left = leftRotate(root->left);
        }
        return (root->left == NULL) ? root: rightRotate(root);
    } 
    else // element present at right sub-tree
    {
        // element is not in tree, we are done
        if(root->right == NULL) return root;
        
        if(root->right->data > data){// Zig Zag Rotate (Right Left Rotate)
            // First recursively bring the key as root of left-right
            root->right->left = splay(root->right->left, data);
            
            // Do first rotation for root->right
             if (root->right->left != NULL)
                root->right = rightRotate(root->right);
        }
        else if(root->right->data < data){// Zag Zag Rotate (Left Left Rotate)
            // First recursively bring the key as root of left-right
            root->right->right = splay(root->right->right, data);
            // Do first rotation for root
            root = leftRotate(root);
        }
        return (root->right == NULL) ? root: leftRotate(root);
    }
}
/*Write a tree in paper and do the splay to understand the steps*/
//Function to find maximum
int maximum(Node* root){
    if(root->right == NULL) return root->data;
    return maximum(root->right);
}
//Function to delete a node
Node* delete(Node* root, int data){
    if(root == NULL) return root;
    //make the data as root
    root = splay(root, data);
    if(root->data != data) return root; // not present in tree
    Node* root1 = root->left;
    Node* root2 = root->right;
    free(root);
    if(root1 == NULL) return root2;
    // make the maximum of root1 tree as the root of root1 tree
    root1 = splay(root1, maximum(root1));
    root1->right = root2;// then add them
    return root1;// return new root
}
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
    //  / \ / 
    // 1  3 5  
    Node *root = newNode(4);
    root->left = newNode(2);
    root->right = newNode(6);
    root->left->left = newNode(1);
    root->left->right = newNode(3);
    root->right->left = newNode(5);
    printf("Preorder traversal of the splay tree : ");
    preOrder(root);
    root = delete(root, 3);
    printf("\nPreorder traversal of the modified splay tree : ");
    preOrder(root);
}