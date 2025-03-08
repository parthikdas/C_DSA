// Leetcode Validate BST - 98
import java.util.ArrayList;
import java.util.List;
import java.util.Stack;
class TreeNode{
    int val;
    TreeNode left;
    TreeNode right;
    TreeNode() {}
    TreeNode(int val) { this.val = val; }
    TreeNode(int val, TreeNode left, TreeNode right ) {
        this.val = val;
        this.left = left;
        this.right = right;
    }
};
public class checkValidBST {
    // APPROACH 1 - BEATS 13% - 2ms
    List<Integer> ans = new ArrayList<>();
    public void inOrder(TreeNode root) {
        if(root == null) return;
        inOrder(root.left);
        ans.add(root.val);
        inOrder(root.right);
    }
    public boolean isValidBST1(TreeNode root) {
        inOrder(root); // inorder traversal of bst gives sorted array
        for(int i =0 ; i < ans.size();i++) {
            if(ans.get(i) <= ans.get(i-1)) return false; // normal check is prev is smaller or not
        }
        return true;
    }
    // APPROACH 2 - BEATS 13% - 2ms
    public boolean isValidBST2(TreeNode root) {
        Stack<TreeNode> stack = new Stack<>();
        Long prev = Long.MIN_VALUE; // Use a long to prevent overflow issues
        // Inorder
        while(!stack.isEmpty() || root!=null) {
            // Push all left children to stack
            while(root!=null) {
                stack.push(root);
                root = root.left;
            }
            //Pop top element (leftmost ele)
            root = stack.pop();
            // Check if current node is greater than previous
            if(root.val <= prev) {
                return false; // violates BST property
            }
            // Update prev to the current node's value
            prev = (long) root.val;
            // Move to the right child
            root = root.right;
        }
        return true;
    }
    // APPROACH 1 - BEATS 100% - 1ms
    // Keep using recursion and main for each iteration a range[min, max] if node lie between ok else no
    public boolean check(TreeNode root, long min, long max) {
        if(root == null) return true;
        if(root.val<=min || root.val>=max) return false;
        return check(root.left, min, root.val) && check(root.right, root.val, max);
    }
    public boolean checkValidBST3(TreeNode root) {
        return check(root, Long.MIN_VALUE, Long.MAX_VALUE);
    }
}
