// Here to avoid collision we use seperate chaining
// Here we have to make an array of L List
#include <stdio.h>// 7 50 700 76 85 92 73 101
#include <stdlib.h>
#define size 7
typedef struct node{
    int data;
    struct node *next;
} Node;
Node *arr[size];// Array
int hash(int n){
    return n%size;
}
Node* createNewNode(int data){// Create a new node and return it
    Node *new = (Node*)malloc(sizeof(Node));
    new->data = data;
    return new;
}
void insert(int data){// Insertion in hash table
    int index = hash(data);
    if(arr[index] == NULL){
        arr[index] = createNewNode(data);
        return;
    } else {
            //last element will be at the head
            Node* newNode = createNewNode(data);
            newNode->next = arr[index];
            arr[index] = newNode;
        /*
            Node* temp = arr[index];
            while(temp->next != NULL){// Traverse till the last to put the node
                temp = temp->next;
            }
            temp->next = createNewNode(data);
        */
    }
}
void display(){
    printf("\n------:Hash Table contents:-----\n");
    int i;
    for(i=0;i<size;i++){
        if(arr[i] == NULL) printf("arr[%d] is empty\n",i);
        else {
            printf("arr[%d] contains : ",i);
            Node *temp = arr[i];
            while(temp != NULL){
                printf("%d->",temp->data);
                temp = temp->next;
            }
            printf("\n");
        }
    }
}
void find(int data){
    int index = hash(data);
    if(arr[index] == NULL) printf("%d not found.\n",data);// if the index is empty then its not found
    else {// if the index is not empty traverse till we find the element
        Node* temp = arr[index];
        while(temp != NULL){
            if(temp->data == data) {
                printf("\n%d is found at index %d.\n",data,index);
                return;
            }
            temp = temp->next;
        }
        printf("%d not found.\n",data);
    }
}
void delete(int data){
    int index = hash(data);
    if(arr[index] == NULL) printf("%d not found.\n",data);// if the index is empty then its not found
    else {// if the index is not empty traverse till we find the element
        Node* temp = arr[index];
        while(temp->next != NULL){
            if(temp->next->data == data) {
                temp->next = temp->next->next;
                return;
            }
            temp = temp->next;
        }
        printf("%d not found.\n",data);
    }
}
int main(){
    int t;
    scanf("%d",&t);
    while(t--){
        int data;
        scanf("%d",&data);
        insert(data);
    }
    display();
    find(101);
    delete(85);
    display();
    return 0;
}