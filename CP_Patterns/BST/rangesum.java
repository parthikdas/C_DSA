package CP_Patterns.BST;

import javax.swing.tree.TreeNode;

public class rangesum {
    // 938. Range Sum of BST
    public int inOrder(TreeNode r, int l, int h) {
        if (r == null) return 0;  // If the node is null, return 0
        
        int sum = 0;

        // Traverse left subtree and get the sum
        sum += inOrder(r.left, l, h);

        // If the current node value is within the range [low, high], add it to the sum
        if (r.val >= l && r.val <= h) {
            sum += r.val;
        }

        // Traverse right subtree and get the sum
        sum += inOrder(r.right, l, h);

        return sum;  // Return the accumulated sum
    }

    // Main function to calculate the range sum
    public int rangeSumBST(TreeNode root, int low, int high) {
        return inOrder(root, low, high);  // Start the in-order traversal from the root
    }
}
