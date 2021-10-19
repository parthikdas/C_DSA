#include <stdio.h>
#include <stdlib.h>
typedef struct inode{
    int data;
    struct inode*next;
} inode;
inode *ihead1, *ihead2, *ihead3;
int isEmpty(inode* ihead){
    return ihead == NULL;
}
void insert(inode **ihead, int data){
    inode* new = (inode*)malloc(sizeof(inode));
    new->data = data;
    if(isEmpty(*ihead)){
        *ihead = new;
        return;
    }
    inode *temp = *ihead;
    while(temp->next != NULL){
        temp = temp->next;
    }
    temp->next = new;
}
void display(inode* ihead){
    if(isEmpty(ihead)) return;
    inode *temp = ihead;
    printf("List : ");
    while(temp != NULL){
        printf("%d->",temp->data);
        temp = temp->next;
    }
    printf("\n");
}
void join(struct inode *ihead1,struct inode *ihead2,struct inode **ihead3) {
    while(ihead1!=NULL && ihead2!=NULL){
        if(ihead1->data > ihead2->data) {
            insert(ihead3,ihead2->data);
            ihead2 = ihead2->next;
        } else {
            insert(ihead3,ihead1->data);
            ihead1 = ihead1->next;
        }
    }
    while(ihead1!=NULL){//if something is left in 1st list
        insert(ihead3,ihead1->data);
        ihead1 = ihead1->next;
    }
    while(ihead2!=NULL){//if something is left in 2nd list
        insert(ihead3,ihead2->data);
        ihead2 = ihead2->next;
    }
}
void join2(struct inode **ihead1,struct inode *ihead2){
    struct inode *temp1 = *ihead1;
    if(temp1->data > ihead2->data){//ihead
        struct inode* temp2 = ihead2;
        ihead2 = ihead2->next;
        temp2->next = temp1;
        *ihead1 = temp2;
    }
    while(ihead2!=NULL){
        if(temp1->next->data > ihead2->data){
            struct inode* temp2 = ihead2;
            ihead2 = ihead2->next;
            temp2->next = temp1->next;
            temp1->next = temp2;
        } else temp1=temp1->next;
    }
    
}
/*
Merge is one of those nice recursive problems where the recursive solution code is much cleaner than the iterative code. You probably wouldn’t want to use the recursive version for production code, however, because it will use stack space which is proportional to the length of the lists.  

struct Node* SortedMerge(struct Node* a, struct Node* b)
{
  struct Node* result = NULL;
 
  // Base cases 
  if (a == NULL)
     return(b);
  else if (b==NULL)
     return(a);
 
  // Pick either a or b, and recur 
  if (a->data <= b->data)
  {
     result = a;
     result->next = SortedMerge(a->next, b);
  }
  else
  {
     result = b;
     result->next = SortedMerge(a, b->next);
  }
  return(result);
}
*/
int main(){
    int n;
    scanf("%d",&n);
    while(n--){
        int x;
        scanf("%d",&x);
        insert(&ihead1,x);
    }
    display(ihead1);
    scanf("%d",&n);
    while(n--){
        int x;
        scanf("%d",&x);
        insert(&ihead2,x);
    }
    display(ihead2);
    //join2(&ihead1,ihead2);
    join(ihead1,ihead2,&ihead3);
    display(ihead3);
    return 0;
}