#include <stdio.h>// dont use macro of max here idk why its not happening correctly
#include <stdlib.h>
typedef struct node{
    int data, height;
    struct node *left, *right;
} Node;
//Function to get maximum of 2 numbers
int max(int a, int b){
    return a>b ? a:b;
}
//Function to tell the height of the current node
int height(Node* node){
    if(node == NULL) return 0;
    return node->height;
}
//Function to create a new node and assign values and return it
Node* create_new_node(int data){
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = data;
    newNode->height = 1;
    newNode->left = newNode->right = NULL;
    return newNode;
}
//Function to get the balance factor of a node
int getBalance(Node* node){
    if(node == NULL) return 0;
    return height(node->left) - height(node->right);
}
//Function to left rotate subtree rooted with x
Node* leftRotate(Node* x){
    Node* y = x->right;
    Node* t2 = y->left;
    // Perform rotation
    y->left = x;
    x->right = t2;
    //  Update heights
    x->height = max(height(x->left), height(x->right))+1;
    y->height = max(height(y->left), height(y->right))+1;
    // Return new root
    return y;
}
//Function to right rotate subtree rooted with x
Node* rightRotate(Node* y){
    Node* x = y->left;
    Node* t2 = x->right;
    // Perform rotation
    x->right = y;
    y->left = t2;
    // Update heights
    y->height = max(height(y->left), height(y->right))+1;
    x->height = max(height(x->left), height(x->right))+1;
    // Return new root
    return x;
}
//Function to insert a data in AVL tree
Node* insert(Node* node, int data){
    //1. Just like BST insertion operations
    if(node == NULL) return create_new_node(data);
    if(data < node->data) node->left = insert(node->left, data);
    else if(data > node->data) node->right = insert(node->right, data);
    else // Equal datas are not allowed in BST
        return node;

    //2. Update height of the ancestor node
    node->height = 1 + max(height(node->left), height(node->right));

    //3. Get the balance factor of this ancestor node to check whether this node became unbalanced
    int balance = getBalance(node);
    //if the node is unbalanced there are 4 cases:
    //Left Left case
    if(balance > 1 && data < node->left->data) return rightRotate(node);
    //Right Right case
    if(balance < -1 && data > node->right->data) return leftRotate(node);
    //Left Right case
    if(balance > 1 && data > node->left->data){
        node->left = leftRotate(node->left);
        return rightRotate(node);
    }
    //Right Left case
    if(balance < -1 && data < node->right->data){
        node->right = rightRotate(node->right);
        return leftRotate(node);
    }
    return node; // everything is done
}
//Function to traverse the tree
void preOrder(Node *root){
    if(root != NULL){
        printf("%d ", root->data);
        preOrder(root->left);
        preOrder(root->right);
    }
}
struct node* minValueNode(struct node* node) {
    struct node* temp = node;
    while (temp && temp->left != NULL) temp = temp->left;
    return temp;
}
Node* deleteNode(Node* root, int data) {
    // STEP 1: PERFORM STANDARD BST DELETE
    if (root == NULL)
        return root;
    // If the data to be deleted is smaller than the root's data, then it lies in left subtree
    if ( data < root->data )
        root->left = deleteNode(root->left, data);
    // If the data to be deleted is greater than the root's data, then it lies in right subtree
    else if( data > root->data )
        root->right = deleteNode(root->right, data);
    // if data is same as root's data, then This is the node to be deleted
    else {
        if(root->left && root->right){// if the one to be deleted has 2 children
            Node *temp = minValueNode(root->right);
            root->data = temp->data;
            root->right = deleteNode(root->right,temp->data);
        }else{
        // node with only one child or no child
            Node *temp = root->left ? root->left : root->right;
            // No child case
            if (temp == NULL)
            {
                temp = root;
                root = NULL;
            }
            else // One child case
            *root = *temp; // Copy the contents of the non-empty child
            free(temp);
        }
    }
 
    // If the tree had only one node then return
    if (root == NULL)
    return root;
    // STEP 2: UPDATE HEIGHT OF THE CURRENT NODE
    root->height = 1 + max(height(root->left), height(root->right));
    // STEP 3: GET THE BALANCE FACTOR OF THIS NODE (to check whether this node became unbalanced)
    int balance = getBalance(root);
    // If this node becomes unbalanced, then there are 4 cases

    // Left Left Case
    if (balance > 1 && getBalance(root->left) >= 0)
        return rightRotate(root);
 
    // Left Right Case
    if (balance > 1 && getBalance(root->left) < 0) {
        root->left = leftRotate(root->left);
        return rightRotate(root);
    }
 
    // Right Right Case
    if (balance < -1 && getBalance(root->right) <= 0)
        return leftRotate(root);
 
    // Right Left Case
    if (balance < -1 && getBalance(root->right) > 0) {
        root->right = rightRotate(root->right);
        return leftRotate(root);
    }
 
    return root;
}
//Main function
int main(){
    //       9
    //      / \
    //     1  10
    //     / \  \
    //     4 5  11
    //    / / \
    //   -1 2 6
    //9 9 5 10 4 6 11 -1 1 2
    Node* root = NULL;
    int n,i;
    scanf("%d",&n);
    for(i=0;i<n;i++){
        int data;
        scanf("%d",&data);
        root = insert(root, data);
    }
    preOrder(root);
    deleteNode(root,1);
    printf("\n");
    preOrder(root);
    return 0;
}