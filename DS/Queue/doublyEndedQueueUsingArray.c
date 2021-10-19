#include <stdio.h>
#define N 100
int queue[N],front=-1,rear=-1;
int isEmpty(){
  return (front==-1&&rear==-1);
}
void enqueue() {
 if(rear==N-1) return;
  else {
    int x;
    scanf("%d",&x);
    if(isEmpty()){
    	front=rear=0;
    	queue[rear]=x;
  	}else{
   		queue[++rear]=x; 
  	}
  }
}
void front_dequeue(){
 if(isEmpty()) printf("Underflow\n");
  else if(front==rear) front=rear=-1;
  else front++;
}
void rear_dequeue(){
 if(isEmpty()) printf("Underflow\n");
  else if(front==rear) front=rear=-1;
  else rear--;
}
void display(){
 int i;
  for(i=front;i<=rear;i++){
    printf("%d->",queue[i]);
  }
  printf("\n");
}
int main() {
	while(1){
     int ch;
      scanf("%d",&ch);
      if(ch==1) enqueue();
      else if(ch==2) front_dequeue();
      else if(ch==3) rear_dequeue();
      else if(ch==4) display();
      else if(ch==0) return 0;
    }
	return 0;
}
/* Test case 1:
1
6
1
8
1
5
1
9
4
2
4
3
4
1
10
4
0
output:
6->8->5->9->
8->5->9
8->5->
8->5->10
Test case 2:
1
3
1
5
1
6
1
8
1
10
4
3
2
4
3
2
2
3
0
output:
3->5->6->8->10->
5->6->8->
Underflow
*/
