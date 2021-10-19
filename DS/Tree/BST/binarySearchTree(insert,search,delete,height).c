#include <stdio.h>
#include <stdlib.h>
struct node{
    int key;
    struct node *left, *right;
};
typedef struct node Node;
Node* root;//if i not made this global then head is becoming 1 and the whole tree is gone
Node* new_node(int key){
    Node *temp = (Node*)malloc(sizeof(Node));
    temp->key = key;
    temp->left = temp->right =NULL;
    return temp;
}
Node* insert(Node* node, int key){//A new key is always inserted at the leaf.We start searching a key from the root until we hit a leaf node.Once a leaf node is found, the new node is added as a child of the leaf node. 
    if(node == NULL) return new_node(key);//root case
    if(key < node->key) node->left = insert(node->left, key);
    else if(key>node->key) node->right = insert(node->right, key);
    //else node; //equal keys not allowed in bst
    return node;//return the (unchanged) node pointer
}
void inOrder(Node* node){
    if(node == NULL) return;
    inOrder(node->left);
    printf("%d ",node->key);
    inOrder(node->right);
}
Node* search(Node* node, int key){
    if (node == NULL || node->key == key)// Base Cases: root is null or key is present at root
       return node;
    if (node->key < key)// Key is greater than root's key
       return search(node->right, key);
    return search(node->left, key);// Key is smaller than root's key
}
//  Deletions
//cases like : 1) Node to be deleted is the leaf: Simply remove from the tree. 
//              50                              50
//            /     \         delete(20)      /   \
//           30      70       --------->    30     70 
//          /  \    /  \                     \    /  \ 
//       20   40  60   80                   40  60   80
//2) Node to be deleted has only one child: Copy the child to the node and delete the child
//              50                              50
//            /     \         delete(30)      /   \
//           30      70       --------->   40     70 
//             \    /  \                         /  \ 
//             40  60   80                      60   80
//3) Node to be deleted has two children: Find inorder successor of the node. Copy contents of the inorder successor to the node and delete the inorder successor. Note that inorder predecessor can also be used. 
//              50                            60
//           /     \         delete(50)      /   \
//           40      70       --------->    40    70 
//                  /  \                            \ 
//                 60   80                           80

// i can also inorder predecesor(largest of left sub tree)
struct node* minValueNode(struct node* node){//Given a non-empty binary search tree, return the node with minimum key value found in that tree.leftmost leaf is smallest
    struct node* current = node;
    while (current && current->left != NULL)
        current = current->left;
    return current;
}
Node* deleteNode(Node* root, int key){//Given a binary search tree and a key, this function deletes the key and returns the new root
    if(root == NULL) return root;
    if (key < root->key)// If the key to be deleted is smaller than the root's key, then it lies in left subtree
        root->left = deleteNode(root->left, key);
    else if (key > root->key)// If the key to be deleted is greater than the root's key, then it lies in right subtree
        root->right = deleteNode(root->right, key);
    else {// if key is same as root's key, then This is the node to be deleted
        // node with only one child or no child
        if (root->left == NULL) {
            struct node* temp = root->right;
            free(root);
            return temp;
        }
        else if (root->right == NULL) {
            struct node* temp = root->left;
            free(root);
            return temp;
        }
        // node with two children: Get the inorder successor (smallest in the right subtree)
        struct node* temp = minValueNode(root->right);
        // Copy the inorder successor's content to this node
        root->key = temp->key;
        // Delete the inorder successor
        root->right = deleteNode(root->right, temp->key);
    }
    return root;
}
#define max(a,b) a>b?a:b
int height(Node* node){
    if (node == NULL)
        return 0;
    return max(height(node->left), height(node->right))+1;
}
int main() {
//     14       another eg     50
//    /  \                    /  \
//   3    16                30   70
//  / \  / \               / \  / \
// 1  6 15 18            20 40 60 80
    root = insert(root,50);
    insert(root,30);
    insert(root,20);
    insert(root,40);
    insert(root,70);
    insert(root,60);
    insert(root,80);
    
    Node* found = search(root, 60);
    if(found == NULL) printf("Not found\n");
    else printf("%d found\n",found->key);
    printf("Height of tree : %d\n",height(root));
    
    printf("\nInorder traversal of the given tree \n");
    inOrder(root);
    
    root = deleteNode(root, 20);
    printf("\nInorder traversal of the modified tree \n");
    inOrder(root);
    root = deleteNode(root, 30);
    printf("\nInorder traversal of the modified tree \n");
    inOrder(root);
    root = deleteNode(root, 50);
    printf("\nInorder traversal of the modified tree \n");
    inOrder(root);
    return 0;
}
