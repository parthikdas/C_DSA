package CP_Patterns.BST;

import java.lang.classfile.components.ClassPrinter.ListNode;

import javax.swing.tree.TreeNode;
// both approach having O(n) and O(nlogn) for recursion stack
public class sortedArr_ListToBST {
    // 108. leetcode     Sorted Array to BST   BinarySearch + bst
    public TreeNode helper(int a[], int l, int r) {
        if(l > r) return null;
        int mid = l + (r-l) / 2;
        TreeNode node = new TreeNode(a[mid]);
        node.left = helper(a,l,mid-1);
        node.right = helper(a,mid+1,r);
        return node;
    }
    public TreeNode sortedArrayToBST(int[] nums) {
        return helper(nums, 0, nums.length-1);
    }
//--------------------------------------------------------------
    // 109. leetcode Sorted List to BST
    private ListNode current;

    public TreeNode sortedListToBST(ListNode head) { // if u dont understand what to do just make it as a array and do like above
        if (head == null) return null;
        int n = getLength(head);
        current = head; // Pointer to traverse linked list
        return buildTree(0, n - 1);
    }

    private int getLength(ListNode head) {
        int length = 0;
        while (head != null) {
            length++;
            head = head.next;
        }
        return length;
    }

    private TreeNode buildTree(int left, int right) {
        if (left > right) return null;
        int mid = left + (right - left) / 2;

        // Recursively construct the left subtree
        TreeNode leftChild = buildTree(left, mid - 1);

        // Create the root node
        TreeNode root = new TreeNode(current.val);
        current = current.next; // Move to the next list node

        // Recursively construct the right subtree
        root.left = leftChild;
        root.right = buildTree(mid + 1, right);

        return root;
    }
}
/*
 why here we first making the node but the code u have is calling left then making node
 cuz : ✅ First, create the root node, then construct the left and right subtrees.
✅ Works efficiently for arrays, where we have O(1) access to elements.


✅ First, build the left subtree, then create the root node, and finally build the right subtree.
✅ Necessary for linked lists, because we cannot access elements randomly (O(1)) like arrays.

Why is the Order Different?
For an array:
We can access mid in O(1) time, so we create the node first and then process left & right subtrees.
Time Complexity: O(n), Space Complexity: O(log n) (recursion stack)
For a linked list:
We must traverse sequentially, so we recursively build the left subtree first, then create the node.
This ensures that when we reach mid, current is already pointing to the right element.
Time Complexity: O(n), Space Complexity: O(log n)
Key Takeaway
Array → Create node first, then recurse (direct O(1) access).
Linked List → Recurse left first, then create node (sequential traversal).
 */