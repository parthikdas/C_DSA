/*  Same question of Type2_sortingWay.c
	1. Insert elements in BST one by one and if an element is already present then increment the count of the node. Node of the Binary Search Tree (used in this approach) will be as follows.
	2. Store the first indexes and corresponding counts of BST in a 2D array.
	3. Sort the 2D array according to counts (and use indexes in case of tie).
*/
//Here i have used self balancing binary tree that is AVL tree, u can also use normal BST
//Overall Time complexity O(nLogn)
#include <stdio.h>
#include <stdlib.h>
typedef struct node{
	int data, height, first_index, count;
	struct node *left, *right;
} Node;
int no_of_distinct_elements = 0;// to know how many elements are there in the tree
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
Node* create_new_node(int data, int first_index){
	Node* newNode = (Node*)malloc(sizeof(Node));
	newNode->data = data;
	newNode->height = newNode->count = 1;
	newNode->first_index = first_index;
	newNode->left = newNode->right = NULL;
	no_of_distinct_elements++;
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
Node* insert(Node* node, int data, int index){
	//1. Just like BST insertion operations
	if(node == NULL) return create_new_node(data, index);
	if(data < node->data) node->left = insert(node->left, data, index);
	else if(data > node->data) node->right = insert(node->right, data, index);
	else node->count++;

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
int ind=0;// this guy will help in insertion of array
void inOrder(Node *root, int b[no_of_distinct_elements][2]){
    if(root != NULL){
        inOrder(root->left, b);
        printf("%d(first_index-%d)(count-%d)\n", root->data, root->first_index, root->count);
        b[ind][0] = root->first_index;
        b[ind++][1] = root->count;
        inOrder(root->right, b);
    }
}
void merge2D(int l,int mid,int r,int arr[r][2]){
    int n1 = mid-l+1;//size of 1st array
    int n2 = r-mid;//size of 2nd array

    //a, a1 is for the left array, where a is for value and a1 is for frequency
    //b, b1 is for thr right array, where b is for value and b1 is for frequency
    int a[n1],b[n2];//temp arrays to store value
    int a1[n1],b1[n2];//temp arrays to store freq

    for(int i=0;i<n1;i++) {
        a[i] = arr[l+i][0];//value, 1st col is storing value
        a1[i] = arr[l+i][1];//freq, 2nd col is storing frequency
    }
    for(int i=0;i<n2;i++) {
        b[i] = arr[mid+1+i][0];
        b1[i] = arr[mid+1+i][1];
    }

     int i=0,j=0,k=l;//k will traverse the array which starts from l
    while(i<n1 && j<n2){//made it descending, tomake ascending swap line 27,28 <=> 31,32
        //compairing a1, b1 (they store freq) as we need to sort on basis of frequency
        if(a1[i]<b1[j]) {
        	arr[k][0]=b[j];//1st col of arr, b is for value.So, put the value in kth position
        	arr[k][1]=b1[j++];//2nd col of arr, b1 is for frequency.So, put the value in kth position
        }
        else if(a1[i]>b1[j]){
        	arr[k][0]=a[i];
        	arr[k][1]=a1[i++];
        } else {//if freq is equal then sort the 0th col(that is stroing indexs)
            //here compairing a, b because we have to put smaller first as freq is same
        	if(a[i]>b[j]){//if a is greater then b is smaller, so put b
        		arr[k][0]=b[j];
        		arr[k][1]=b1[j++];
        	}else {//if a is smaller then b is greater, so put a
        		arr[k][0]=a[i];
        		arr[k][1]=a1[i++];
        	}
        }
        k++;//as kth row is done, increment k.Now, for the next row
    }
    while(i<n1) {//for remaining elements
    	arr[k][0]=a[i];
        arr[k++][1]=a1[i++];
    }
    while(j<n2){//for remaining elements
       	arr[k][0]=b[j];
        arr[k++][1]=b1[j++];
    }
}
void mergeSort2D(int l,int r,int a[r][2]){//dividing array
    if(r>l){
        int mid=(l+r)/2;
        mergeSort2D(l,mid,a);
        mergeSort2D(mid+1,r,a);
        merge2D(l,mid,r,a);
    }
}
//Main function
int main(){
	Node* root = NULL;
	int n,i;
	scanf("%d",&n);
	int a[n];
	for(i=0;i<n;i++)
		scanf("%d",&a[i]);
	for(i=0;i<n;i++)
		root = insert(root, a[i], i);
	//Lets see the AVL tree and Convert the bst into 2d array
	int b[no_of_distinct_elements][2];
	for(i=0;i<no_of_distinct_elements;i++) b[i][0]=b[i][1]=0;
	inOrder(root, b);
	free(root);// i dont need the tree anymore
	//Sort the 2d array according to counts and use indexes in case of a tie
	mergeSort2D(0, no_of_distinct_elements-1, b);
	for(i=0;i<no_of_distinct_elements;i++){
		for(int j=0;j<b[i][1];j++){
			printf("%d ",a[b[i][0]]);
		}
	}
	//Here i am printing only if u want to store it make int *c and put all the values then do a=c then free c
	return 0;
}
/*Input: 2 5 2 8 5 6 8 8
Output: 8 8 8 2 2 5 5 6

Input:2
5
5 5 4 6 4
5
9 9 9 2 5
Output:4 4 5 5 6
9 9 9 2 5

Input: 2 5 2 6 -1 9999999 5 8 8 8
Output: 8 8 8 2 2 5 5 -1 6 9999999
Input: 37
1 3 7 7 7 3 2 2 2 7 3 1 7 1 6 3 5 5 4 5 6 2 1 2 4 7 3 1 3 5 4 1 7 2 6 1 2
Output: 1 1 1 1 1 1 1 2 2 2 2 2 2 2 7 7 7 7 7 7 7 3 3 3 3 3 3 5 5 5 5 4 4 4 6 6 6
*/