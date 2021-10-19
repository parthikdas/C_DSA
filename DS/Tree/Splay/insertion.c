// if we insert every element in ascending or descending order the tree becomes left or right skewed tree
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
//Function to insert
struct node *insert(Node *root, int k){
    if (root == NULL) return newNode(k);
    // Bring the closest leaf node to root
    root = splay(root, k);
    // If key is already present, then return
    if (root->data == k) return root;
    // Otherwise allocate memory for new node
    struct node *newnode  = newNode(k);
 
    // If root's key is greater, make root as right child
    // of newnode and copy the left child of root to newnode
    if (root->data > k){
        newnode->right = root;
        newnode->left = root->left;
        root->left = NULL;
    }
    // If root's key is smaller, make root as left child
    // of newnode and copy the right child of root to newnode
    else {
        newnode->left = root;
        newnode->right = root->right;
        root->right = NULL;
    }
    return newnode; // newnode becomes new root
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
    root = insert(root, 7);
    printf("\nPreorder traversal of the modified splay tree : ");
    preOrder(root);
}
/*
    Inserting 7
         4              6              7
        / \   Splay    / \  Insert   /  \
       2   6  --->   4   5   --->   6    5 
     / \  /  for 7  /             /     
    1  3 5         2             4     
                  / \           /            
                 1   3        2
                             / \
                            1  3
*/