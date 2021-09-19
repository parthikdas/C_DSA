/*Runtime: 0 ms, faster than 100.00% of C online submissions for Valid Parentheses.Memory Usage: 5.6 MB, less than 84.93% of C online submissions                 for Valid Parentheses. - Leetcode compliment*/
#include <stdio.h>
#include <string.h>
#define maxSize 10000
char stack[maxSize];
int top = -1;
int isFull();
int isEmpty();
void display();
void display() {
	int i;
	printf("Elements in Stack: ");
	for(i=top;i>=0;i--) {
		printf("%c ",stack[i]);
	}
	printf("\n");
	return;
}
void push(char data) {
	if(isFull()) {
		return;
	} else {
		stack[++top] = data;
	}
}
int pop() {
	if(isEmpty()) {
		return -10;
	} else {
		return stack[top--];
	}
}
int peek() {
	if(isEmpty()) {
		return -10;
	} else {
		return stack[top];
	}
}
int isFull() {
	return top == maxSize-1;
}
int isEmpty() {
	return top == -1;
}
int checkParenthesis(char *s) {
    int i;
    int isBalanced = 1;
    for(i=0;i<strlen(s);i++) {
        if(s[i] == '(' || s[i] == '{' || s[i] == '[') push(s[i]);
         if(s[i]==')') {
            if(peek() == '(') pop();
            else {isBalanced = 0;break;}
        }
         if(s[i]=='}') {
            if(peek() == '{') pop();
            else {isBalanced = 0;break;}
        }
         if(s[i]==']') {
            if(peek() == '[') pop();
            else {isBalanced = 0;break;}
        }
    }
    if(!isEmpty() || !isBalanced) {//if Stack is not empty or not balanced
        while(isEmpty()!=1) {pop();}//Suppose there are multiple testcases so after 1 testcase which is false the remaining element is still present in stack and it will affect the next test case so ,if the testcase is true then stack is empty but if it is false then we will make the stack empty before next test case
        return 0;
    }
    return 1;
}
int main()
{
    int t;
    scanf("%d",&t);
    while(t--) {
    char s[100];
    scanf("%s",s);
    if(checkParenthesis(s)) printf("String is balanced!\n");
    else printf("String is unbalanced!\n");
    }
    return 0;
}
