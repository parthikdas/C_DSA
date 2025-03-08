/*
 * 
 * 1290. Convert Binary Number in a Linked List to Integer
Solved
Easy

Topics
Companies

Hint
Given head which is a reference node to a singly-linked list. The value of each node in the linked list is either 0 or 1. The linked list holds the binary representation of a number.

Return the decimal value of the number in the linked list.

The most significant bit is at the head of the linked list.

 

Example 1:


Input: head = [1,0,1]
Output: 5
Explanation: (101) in base 2 = (5) in base 10
Example 2:

Input: head = [0]
Output: 0
 

Constraints:

The Linked List is not empty.
Number of nodes will not exceed 30.
Each node's value is either 0 or 1.
 */
package specifics_leetcode.String;

import java.lang.classfile.components.ClassPrinter.ListNode;

/**
 * Definition for singly-linked list.
 * public class ListNode {
 *     int val;
 *     ListNode next;
 *     ListNode() {}
 *     ListNode(int val) { this.val = val; }
 *     ListNode(int val, ListNode next) { this.val = val; this.next = next; }
 * }
 */
/*
 * I have used a for loop to calculate the length of the list. Then using recursion i am calculating the number. using the concept of stack in recursion let it call it itself so that the last element of the list is at the top of stack and simultanouly reducing the length.
 */
class binaryToLinkedList {
    int number =0;
    public void recur(ListNode head, int i) {
        if(head == null) return;
        recur(head.next,--i);
        if(head.val == 1)
            this.number += Math.pow(2,i);
    }
    public int getDecimalValue(ListNode head) {
        int length =0 ;
        ListNode lol = head;
        while(lol!=null) {
            length++;
            lol=lol.next;
        }
        recur(head, length);
        return this.number;
    }
}
