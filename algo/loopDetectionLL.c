// C++ program to detect loop in a linked list
// Floyd’s Cycle-Finding Algorithm 
// Approach: This is the fastest method and has been described below:  
// Traverse linked list using two pointers.
// Move one pointer(slow_p) by one and another pointer(fast_p) by two.
// If these pointers meet at the same node then there is a loop. If pointers do not meet then linked list doesn’t have a loop.
// C program to detect loop in a linked list
#include <stdio.h>
#include <stdlib.h>
 
/* Link list node */
struct Node {
    int data;
    struct Node* next;
};
 
void push(struct Node** head_ref, int new_data)
{
    /* allocate node */
    struct Node* new_node
        = (struct Node*)malloc(sizeof(struct Node));
 
    /* put in the data  */
    new_node->data = new_data;
 
    /* link the old list off the new node */
    new_node->next = (*head_ref);
 
    /* move the head to point to the new node */
    (*head_ref) = new_node;
}
 
int detectLoop(struct Node* list)
{
    struct Node *slow_p = list, *fast_p = list;
 
    while (slow_p && fast_p && fast_p->next) {
        slow_p = slow_p->next;
        fast_p = fast_p->next->next;
        if (slow_p == fast_p) {
            return 1;
        }
    }
    return 0;
}
 
/* Driver program to test above function*/
int main()
{
    /* Start with the empty list */
    struct Node* head = NULL;
 
    push(&head, 20);
    push(&head, 4);
    push(&head, 15);
    push(&head, 10);
 
    /* Create a loop for testing */
    head->next->next->next->next = head;
 
    if (detectLoop(head))
        printf("Loop found");
    else
        printf("No Loop");
    return 0;
}
//Complexity Analysis:  Time complexity: O(n). Auxiliary Space:O(1). 

/*
Another Approach: This solution requires modifications to the basic linked list data structure. 

Have a visited flag with each node.
Traverse the linked list and keep marking visited nodes.
If you see a visited node again then there is a loop. This solution works in O(n) but requires additional information with each node.
A variation of this solution that doesn’t require modification to basic data structure can be implemented using a hash, just store the addresses of visited nodes in a hash and if you see an address that already exists in hash then there is a loop.
// C++ program to detect loop in a linked list
#include <bits/stdc++.h>
using namespace std;
 
// Link list node
struct Node {
    int data;
    struct Node* next;
    int flag;
};
 
void push(struct Node** head_ref, int new_data)
{
    // allocate node
    struct Node* new_node = new Node;
 
    // put in the data
    new_node->data = new_data;
 
    new_node->flag = 0;
 
    /* link the old list off the new node 
    new_node->next = (*head_ref);
 
    /* move the head to point to the new node
    (*head_ref) = new_node;
}
 
// Returns true if there is a loop in linked list
// else returns false.
bool detectLoop(struct Node* h)
{
    while (h != NULL) {
        // If this node is already traverse
        // it means there is a cycle
        // (Because you we encountering the
        // node for the second time).
        if (h->flag == 1)
            return true;
 
        // If we are seeing the node for
        // the first time, mark its flag as 1
        h->flag = 1;
 
        h = h->next;
    }
 
    return false;
}
 
/* Driver program to test above function
int main()
{
    /* Start with the empty list 
    struct Node* head = NULL;
 
    push(&head, 20);
    push(&head, 4);
    push(&head, 15);
    push(&head, 10);
 
    /* Create a loop for testing
    head->next->next->next->next = head;
 
    if (detectLoop(head))
        cout << "Loop found";
    else
        cout << "No Loop";
 
    return 0;
}
*/
