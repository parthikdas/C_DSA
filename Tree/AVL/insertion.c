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
	else // Equal keys are not allowed in BST
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
//Main function
int main(){
	Node* root = NULL;
	int n,i;
	scanf("%d",&n);
	for(i=0;i<n;i++){
		int data;
		scanf("%d",&data);
		root = insert(root, data);
	}
	preOrder(root);
	return 0;
}