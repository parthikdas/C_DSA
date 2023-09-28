/* https://leetcode.com/problems/add-two-numbers/
    You are given two non-empty linked lists representing two non-negative integers. The digits are stored in reverse order, and each of their nodes contains a single digit. Add the two numbers and return the sum as a linked list.

You may assume the two numbers do not contain any leading zero, except the number 0 itself.

Input: l1 = [2,4,3], l2 = [5,6,4]
Output: [7,0,8]
Explanation: 342 + 465 = 807.
Example 2:

Input: l1 = [0], l2 = [0]
Output: [0]
Example 3:

Input: l1 = [9,9,9,9,9,9,9], l2 = [9,9,9,9]
Output: [8,9,9,9,0,0,0,1]

Constraints:

The number of nodes in each linked list is in the range [1, 100].
0 <= Node.val <= 9
It is guaranteed that the list represents a number that does not have leading zeros.

*/

/* Question Explanation
l1 =[2,4,9]
ll representation = 2->4->9->NULL;

l2 =[5,6,4,9]
ll represenation = 5->6->4->9->NULL;

The two No. represented by ll are 942 and 9465
942 + 9465 = 10407; { Here the sol which we will get in form of linked list is read from backward}

How the sum is calculated

2+5=7 (carry=0)

ans 7->

4+6=10 (carry=1)
ans 7->0->

9+4+carry=14 (carry=1)

ans 7->0->4->

0+9+carray (carry=1)
ans 7->0->4->0->1(carry)->null { we will add carry to linked list beacuse we have itterated both the ll)

I hope this help :)
*/

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode* newList = new ListNode(); // make new
        ListNode* temp = newList; // iterator
        int carry = 0;
        while(l1 || l2 || carry) {
            int sum = carry;
            if(l1) {
                sum+=l1->val;
                l1 = l1->next;
            }
            if(l2) {
                sum+=l2->val;
                l2 = l2->next;
            }
            carry = sum/10; // tens digit
            ListNode* newNode = new ListNode(sum%10); // unit digit
            temp->next = newNode;
            temp = temp->next;
        }
        return newList->next; // 1st one is empty so send the second ele as head
    }
};