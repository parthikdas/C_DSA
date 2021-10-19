#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define maxSize 500
char stack[maxSize];
int top = -1;
int isFull() {
	return top == maxSize-1;
}
int isEmpty() {
	return top == -1;
}
void push(char data) {
	if(isFull()) {
		printf("Overflow\n");
		return;
	} else {
		stack[++top] = data;
	}
}
int pop() {
	if(isEmpty()) {
		printf("Stack is empty\n");
		return -10;
	} else {
		return stack[top--];
	}
}
int peek() {
	if(isEmpty()) {
		printf("pStack is empty\n");
		return -10;
	} else {
		return stack[top];
	}
}
int Prec(char n){
    switch (n) {
    case '+':
    case '-':
        return 1;
    case '*':
    case '/':
        return 2;
    case '^':
        return 3;
    }
    return -1;
}
char* infixToPostfix(char* s){
    char* p=(char*)malloc(maxSize*sizeof(char));
    int k=0,i;
    for(int i=0;i<strlen(s);i++){
     if((s[i]>='a'&&s[i]<='z')||(s[i]>='A'&&s[i]<='Z')||(s[i]>='1'&&s[i]<='9')) p[k++]=s[i];//opearand
     else if(s[i]=='(') push(s[i]);//opening bracket
     else if(s[i]==')'){ //closing bracket
        while (!isEmpty() && peek() != '(') p[k++] = pop();//while '(' found pop and add
        if (!isEmpty() && peek() != '(') return "invalid expression";//if stack is empty and '(' not found not balanced parenthesis       
        else pop();//we have done the loop till peek() is ( so now pop to remove it
     } else {//operator
        while (!isEmpty() && Prec(s[i]) <= Prec(peek())) p[k++] = pop();//if the precedence of topmost is >= s[i] pop and add
        push(s[i]);
     }
    }
    while (!isEmpty()) {//for the remaining ones
        if(peek()!='('&&peek()!=')') p[k++] = pop();
        else pop();
    }
    return p;
}
int main(){
 char s[maxSize];
 scanf("%s",s);
 printf("%s",infixToPostfix(s));
 return 0;   
}