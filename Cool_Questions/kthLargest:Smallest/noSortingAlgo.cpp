/* // K th largest/ smallest using Linked List without sorting algo
    #include <iostream>
    #include <stdlib.h>
    using namespace std;
    typedef struct node {
       int data;
       struct node *next;
    } Node;
    Node *head;
    Node* createNewNode(int data) {
       Node *newNode = (Node*) malloc(sizeof(Node));
       newNode->data = data;
       newNode->next = NULL;
       return newNode;
    }
    void insert(int data) {
        Node *newNode = createNewNode(data);
        if(head == NULL) {
            head = newNode;
        } else {
            if(newNode->data < head->data) { // head changing condition
                newNode->next = head;
                head = newNode;
            } else { // rest body
                Node *temp = head;
                while(temp) {
                    if(temp->next) { // temp is not last node
                        if(newNode->data > temp->data && newNode->data < temp->next->data) {
                            newNode->next = temp->next;
                            temp->next = newNode;
                            return;
                        }
                    temp = temp->next; // increment as here we didn't added anything
                    } else { // last node
                        temp->next = newNode;
                        return;
                    }
                }
            }
        }
    }
    void display() {
        if(head == NULL) return;
        while(head) {
            cout<<head->data<<" ";
            head = head->next;
        }
    }
    int main() {
        int n;
        cin>>n;
        for(int i=0;i<n;i++) {
            int data;
            cin>>data;
            insert(data);
        }
        display();
        // now to find the kth smallest element just do while(k--) and increment head u will reach, for kth largest do k = n-k then while(k--)
        return 0;
    }

    testcases : 
    5 4 3 2 1
    1 2 3 4 5
    3 4 1 2 5
    1 3 5 2 4
    2 5 3 1 4

    Explanation of input: 2 4 1 3
    First head is empty so 2 becomes head
    head is not empty and 4 is not > head(2) so came to "else" line 24, here temp->next does not exist as LL has only 1 element so line 35, 2->4
    head is not empty and 1 is < head(2) so line 21, 1->2->4
    head is not empty and 3 is not > head(1) so came to "else" line 24, here temp->next does exist. So line 28, 3>1 && 3<2 fails, so increment temp, now temp is 2 now line 28, 3>2 && 3<4 so 1->2->3->4
*/
// --------------------------------------------------------------------------------------------------------------------------------
/* Using Priority Queue, in c++ its built in
    priority_queue<int> p;
    for(int i=0;i<n;i++){
        int data;
        cin>>data;
        p.push(data);
    }
    so its sorted if u print it
*/