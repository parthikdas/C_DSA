/*Given a complete binary tree with N nodes and each node have an distinct integer a(base i) attached with it, find the minimum number of swaps you can make to convert the binary tree into binary search tree. In one swap, you can select any two nodes and swap their values.You will be given the array representation of the binary tree. Root of the tree will be at a1. Left child of root will be at a2 and right child of root will be at a3. Left child of node at array position k will be at a2∗k and right child of node at array position k will be at a2∗k+1.Mandatory declaration are "struct node *rightside;","struct node *leftside;"Input format:First line contains an integer, N (1≤N≤105), denoting the number of nodes. Second line contains N space separated integers, ai(1≤ai≤105),, denoting the value attached to ith node.Output format:Print a single integer, denoting the minimum number of swaps needed to convert binary tree into a binary search tree.</a>
Given a complete binary tree with N nodes and each node have an distinct integer a(base i) attached with it, find the minimum number of swaps you can make to convert the binary tree into binary search tree. In one swap, you can select any two nodes and swap their values.
You will be given the array representation of the binary tree. Root of the tree will be at a1. Left child of root will be at a2 and right child of root will be at a3. Left child of node at array position k will be at a2∗k and right child of node at array position k will be at a2∗k+1.
Mandatory declaration are "struct node *rightside;","struct node *leftside;"
Input format:
First line contains an integer, 
N (1≤N≤105), denoting the number of nodes. Second line contains N space separated integers, 
ai(1≤ai≤105),, denoting the value attached to ith node.
Output format:
Print a single integer, denoting the minimum number of swaps needed to convert binary tree into a binary search tree.

Testcase1: input: 3 1 2 3
ouput: 1
Testcase2: input: 3 4 8 12
ouput: 1 */

#include <stdio.h>
#include <stdlib.h>
struct node{
  int data;
  struct node *rightside;
  struct node *leftside;
};
int *a, *b, k=0;//b is to store the inorder traversal, k is to help elements to go inside b in inorder
void inorder(int a[],int n,int ind){
  if(ind>=n) return;
  inorder(a,n,2*ind+1);
  b[k++]=a[ind];
  inorder(a,n,2*ind+2);
}
void swap(int *a,int *b){
 int t=*a;*a=*b;*b=t; 
}
void sort(int a[],int n){
 int i,j;
  for(i=0;i<n-1;i++){
    for(j=0;j<n-i-1;j++){
      if(a[j]>a[j+1]) swap(&a[j],&a[j+1]);
    }
  }
}
int minSwap(int *b, int n){
  int i,ans=0;
  for(i=0;i<n;i++) a[i]=b[i];
  sort(a,n);//sort a
  for(i=0;i<n;i++){
    if(a[i]!=b[i]){
     ans++;swap(&a[i],&b[i]); 
    }
  }
  return ans;
}
int main() {
	int n,i;
  scanf("%d",&n);
  a=(int*)malloc(sizeof(int)*n);
  for(i=0;i<n;i++) scanf("%d",&a[i]);
  b=(int*)malloc(sizeof(int)*n);
  inorder(a,n,0);
  printf("%d",minSwap(b,n)-1);
	return 0;
}