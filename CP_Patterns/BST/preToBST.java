package CP_Patterns.BST;

import javax.swing.tree.TreeNode;

public class preToBST {
    /*
     * ✅ O(log N) (balanced BST)
✅ O(N) (worst-case, skewed BST)
     */
    // Helper function to insert a new value into the BST
    public TreeNode insert(TreeNode root, int val) {
        if (root == null) return new TreeNode(val);
        
        // If val is smaller than root, insert into the left subtree
        if (val < root.val) {
            root.left = insert(root.left, val);
        } 
        // If val is greater than root, insert into the right subtree
        else {
            root.right = insert(root.right, val);
        }
        
        return root;
    }

    // Function to construct a BST from preorder traversal
    public TreeNode bstFromPreorder(int[] preorder) {
        TreeNode root = null;
        for (int val : preorder) {
            root = insert(root, val);  // Insert each value in preorder into the BST
        }
        return root;
    }
}
