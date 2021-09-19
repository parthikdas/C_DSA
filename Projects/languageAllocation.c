/*
A university is receiving applications from students to register for language courses offered in six different languages. Each language has limited seats
and time of submission of request is to be used for making a decision. The following are the fields provided in the application:
Register Number, Name, Time and date of submission, Preference of language {Option1, Option2, Option3}
Devise a solution that would automate the process of allocating the languages based on the order of preference given by students. Use appropriate data 
structures to process the data. Include provision for swapping of the language that has been allocated for a student on mutual consent.
*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
// 0:japanese, 1:chinese, 2:french, 3:german, 4:korean, 5:spanish
int lang[6]={2,2,2,2,2,2};// Limited seats for Foreign languages
int seatsFull(){// function to tell whether seats are full or not
    for(int i=0;i<6;i++){
        if(lang[i]!=0) return 0;
    }
    return 1;
}
//struct node
typedef struct node{
    int regNo;
    char name[50];
    int *pref;
    struct node *next;
} Node;
Node *arr[6];//array of LL to store data of students in particular language
void insert(Node* temp, int index){
    if(arr[index] == NULL) arr[index] = temp;
    else{
        Node* curr = arr[index];
        while(curr->next != NULL){
            curr=curr->next;
        }
        curr->next = temp;
    }
}
void display(){// to see the array, update it to make it look good
    for(int i=0;i<6;i++){
        if(i==0) printf("Japanese ");
        else if(i==1) printf("Chinese ");
        else if(i==2) printf("French ");
        else if(i==3) printf("German ");
        else if(i==4) printf("Korean ");
        else if(i==5) printf("Spanish ");

        if(arr[i]==NULL) printf("seats are empty");
        else {
            printf(": ");
            Node* curr = arr[i];
            while(curr != NULL){
                if(curr->next != NULL) printf("%s(%d), ",curr->name,curr->regNo);
                else printf("%s(%d)",curr->name,curr->regNo);
                curr=curr->next;
            }
        }
        printf("\n");
    }
}
//Queue
Node *front, *rear;//insertion in rear, deletion from front
int isEmpty(){
    return front == NULL;
}
void enqueue(int regNo, char *name, int *pref){
    Node *newNode = (Node*)malloc(sizeof(Node));
    newNode->regNo = regNo;
    strcpy(newNode->name, name);
    newNode->pref = pref;
    
    if(isEmpty()){
        front = rear = newNode;
        return;
    }
    rear->next = newNode;
    rear = newNode;
}
Node* dequeue(){
    if(isEmpty()) return NULL;
    Node* temp;
    if(front == rear){//if only 1 element is left
        temp = front;
        front = rear = NULL;
    } else {//more elements are there
        temp = front;
        front = front->next;
    }
    temp->next = NULL;
    return temp;// we want the node
}
void input(){
    printf("------Welcome to SRM Univeristy---------");
    printf("\n  ---Language allocation service---\n");
    int n;
    printf("\nEnter number of Students : ");
    scanf("%d",&n);
    while(n--){
        int regNo;
        int *pref = (int*)malloc(6*sizeof(int));//for six subjects
        char name[50];
        printf("\nEnter your registration number : ");
        scanf("%d",&regNo);
        printf("\nEnter your name : ");
        scanf("%s",name);
        printf("\nEnter your preference\n0:japanese, 1:chinese, 2:french, 3:german, 4:korean, 5:spanish\n");
        for(int i=0;i<6;i++) scanf("%d",&pref[i]);
        enqueue(regNo, name, pref);
    }
}
void allocate(){//after evry allocation do limited seats --
    Node* temp = dequeue();//dequeue the topmost
    //temp will store the dequeued node
    //According to preference
    for(int i=0;i<6;i++){
        if(lang[temp->pref[i]-1]>0){// if seats are there, then only
            insert(temp,temp->pref[i]-1);// insert in the array
            lang[temp->pref[i]-1]--;// reduce the seats
            return;//return if the work is done
        }
    }
}
void writeFile(){// To put the final record in a .txt file
    FILE *ptr;
    ptr = fopen("record.txt", "w");
    if ( ptr == NULL ){
        printf("record.txt file failed to open.\n") ;
    } else {
        fputs("Updated Seats..\n\n",ptr);
        for(int i=0;i<6;i++){
            if(i==0) fputs("Japanese ",ptr);
            else if(i==1) fputs("Chinese ",ptr);
            else if(i==2) fputs("French ",ptr);
            else if(i==3) fputs("German ",ptr);
            else if(i==4) fputs("Korean ",ptr);
            else if(i==5) fputs("Spanish ",ptr);

            if(arr[i]==NULL) fputs("seats are empty",ptr);
            else {
                fputs(": ",ptr);
                Node* curr = arr[i];
                while(curr != NULL){
                    fputs(curr->name,ptr);
                    char s[20] = "";
                    sprintf(s, "(%d)", curr->regNo);
                    fputs(s,ptr);
                    if(curr->next != NULL) fputs(", ",ptr);
                    curr=curr->next;
                }
            }
            fputs("\n",ptr);
        }
    }
}
int indexTeller(int regNo){// tells the index of the array where the element is present
    for(int i=0;i<6;i++){
        if(arr[i]->regNo == regNo) return i;// if its present in the head
        else {
            Node* temp = arr[i];
            while(temp->next != NULL){// else traverse till we find it
                if(temp->next->regNo == regNo) return i;
                temp=temp->next;
            }
        }
    }
    return -1;//does not exist in the array
}
void swap(int ind1, int reg1, int ind2, int reg2){
    Node *x = arr[ind1], *prevX = NULL;// x is the current node and prevX is the node before it
    while(x->regNo != reg1){// as this function is called we know the values are in there
        prevX = x;
        x = x->next;
    }
    Node *y = arr[ind2], *prevY = NULL;
    while(y->regNo != reg2){
        prevY = y;
        y = y->next;
    }
    // If the previous node is empty, that means current node is the head node
    if(prevX == NULL && prevY == NULL){//both of the nodes are head
        arr[ind1] = arr[ind1]->next;// move first head
        arr[ind2] = arr[ind2]->next;// move second head
        y->next = arr[ind1];// put second pointer's next as first list's head
        arr[ind1] = y;// make it the head
        x->next = arr[ind2];// put first pointer's next as second list's head
        arr[ind2] = x;// make it the head
    } else if(prevX == NULL && prevY != NULL){//first node is head
        arr[ind1] = arr[ind1]->next;// move first head
        x->next = y->next;
        prevY->next = x;
        y->next = arr[ind1];// put second pointer's next as first list's head
        arr[ind1] = y;// make it the head
    } else if(prevX != NULL && prevY == NULL){//second node is head
        arr[ind2] = arr[ind2]->next;// move second head
        y->next = x->next;
        prevX->next = y;
        x->next = arr[ind2];// put first pointer's next as second list's head
        arr[ind2] = x;// make it the head
    } else {// the nodes are not head
        Node *temp = prevX->next;
        prevX->next = prevY->next;
        prevY->next = temp;
    }
}
int main(){
    input();//take the input of queue
    while(!isEmpty()){// till the queue is empty do it
        allocate();
        if(seatsFull()) break;
    }
    int count = 0;
    while(!isEmpty()){//if there are remaining elements left
        count++;
        free(dequeue());
    }
    printf("Seats Allocated..\n");
    display();//Seats are allocated
    if(count>0) printf("Seats are Full!!\n%d students did't got seats\n",count);
    while(1){
        int ch;
        printf("\nWant to swap languages on mutual consent(1/0) : ");
        scanf("%d",&ch);
        if(ch == 0) {
            printf("\nUpdated seats..\n");
            display();
            writeFile();
            return 0;
        }
        int reg1, reg2;
        printf("\nEnter the registration number of 2 students : ");
        scanf("%d%d",&reg1,&reg2);//first storing the registration number
        int ind1 = indexTeller(reg1);//again using to get the index of array where it is present
        int ind2 = indexTeller(reg2);
        if(ind1 == -1 || ind2 == -1) printf("Please enter a valid number\n");
        else if(ind1 == ind2) printf("Both students had same language.\nPlease enter a valid number\n");
        else {
            swap(ind1, reg1, ind2, reg2);
            printf("Swapped..\n");
        }
        //swapping
    }
    return 0;
}
/*
16
10
parthik
1 2 3 4 5 6
20
shashank
6 5 4 3 2 1
30
elina
4 3 2 5 1 6
40
akshika
3 1 5 2 4 6
50
bhavya
2 3 1 5 6 4
60
ansh
5 3 2 1 6 4
70
lakshmi
1 3 4 2 5 6
80
zaid
4 3 5 2 1 6
90
tisha
6 3 2 5 1 4
100
subham
3 6 4 1 5 2
110
himanshu
1 5 3 2 6 4
120
adarsh
2 4 3 1 5 6
130
useless
1 2 3 4 5 6
131
useless1
1 2 3 4 5 6
132
useless2
1 2 3 4 5 6
133
useless3
1 2 3 4 5 6
*/
