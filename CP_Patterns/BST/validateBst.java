package CP_Patterns.BST;

import javax.swing.tree.TreeNode;

public class validateBst {
    // 98 leetcode
    public boolean check(TreeNode root, long mini, long maxi){
    if(root==null)return true;
    if(root.val <= mini || root.val >= maxi)return false;
    return check(root.left,mini,root.val) && check(root.right, root.val, maxi);
}
    public boolean isValidBST(TreeNode root) {
        return check(root, Long.MIN_VALUE, Long.MAX_VALUE);
    }
}
