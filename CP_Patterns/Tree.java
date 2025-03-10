package CP_Patterns;

import java.util.Stack;

public class Tree {
    static class TreeNode {
        int val;
        TreeNode left, right;
        TreeNode(int x) { val = x; }
    }
    // 1. Validate BST
    boolean isValidBST(TreeNode root) {
        return validate(root, null, null);
    }
    boolean validate(TreeNode node, Integer low, Integer high) {
        if (node == null) return true;
        if ((low != null && node.val <= low) || (high != null && node.val >= high)) return false;
        return validate(node.left, low, node.val) && validate(node.right, node.val, high);
    }
    // 2. Convert Sorted Array to BST
    TreeNode sortedArrayToBST(int[] nums) {
        return buildBST(nums, 0, nums.length - 1);
    }
    TreeNode buildBST(int[] nums, int l, int r) {
        if (l > r) return null;
        int mid = (l + r) / 2;
        TreeNode node = new TreeNode(nums[mid]);
        node.left = buildBST(nums, l, mid - 1);
        node.right = buildBST(nums, mid + 1, r);
        return node;
    }
    // 3. Minimum Absolute Difference in BST
    int minDiff = Integer.MAX_VALUE, prev = -1;
    int getMinimumDifference(TreeNode root) {
        if (root == null) return minDiff;
        getMinimumDifference(root.left);
        if (prev != -1) minDiff = Math.min(minDiff, root.val - prev);
        prev = root.val;
        getMinimumDifference(root.right);
        return minDiff;
    }
    // 4. Kth Smallest Element in BST
    int count, res;
    int kthSmallest(TreeNode root, int k) {
        count = k;
        inorder(root);
        return res;
    }
    void inorder(TreeNode root) {
        if (root == null) return;
        inorder(root.left);
        if (--count == 0) { res = root.val; return; }
        inorder(root.right);
    }
    // 5. Lowest Common Ancestor
    TreeNode lowestCommonAncestor(TreeNode root, TreeNode p, TreeNode q) {
        if (root.val > p.val && root.val > q.val) return lowestCommonAncestor(root.left, p, q);
        if (root.val < p.val && root.val < q.val) return lowestCommonAncestor(root.right, p, q);
        return root;
    }
    // 6. Insert into BST
    TreeNode insertIntoBST(TreeNode root, int val) {
        if (root == null) return new TreeNode(val);
        if (val < root.val) root.left = insertIntoBST(root.left, val);
        else root.right = insertIntoBST(root.right, val);
        return root;
    }
    // 7. Delete Node in BST
    TreeNode deleteNode(TreeNode root, int key) {
        if (root == null) return null;
        if (key < root.val) root.left = deleteNode(root.left, key);
        else if (key > root.val) root.right = deleteNode(root.right, key);
        else {
            if (root.left == null) return root.right;
            if (root.right == null) return root.left;
            TreeNode temp = minValueNode(root.right);
            root.val = temp.val;
            root.right = deleteNode(root.right, temp.val);
        }
        return root;
    }
    TreeNode minValueNode(TreeNode node) {
        while (node.left != null) node = node.left;
        return node;
    }
    // 8. Range Sum of BST
    int rangeSumBST(TreeNode root, int low, int high) {
        if (root == null) return 0;
        return (root.val >= low && root.val <= high ? root.val : 0) +
               rangeSumBST(root.left, low, high) + rangeSumBST(root.right, low, high);
    }
    // 9. Convert BST to Greater Tree
    int sum = 0;
    TreeNode convertBST(TreeNode root) {
        if (root == null) return null;
        convertBST(root.right);
        root.val += sum;
        sum = root.val;
        convertBST(root.left);
        return root;
    }
    // 10. BST Iterator
    static class BSTIterator {
        Stack<TreeNode> stack = new Stack<>();
        BSTIterator(TreeNode root) { pushLeft(root); }
        void pushLeft(TreeNode node) { while (node != null) { stack.push(node); node = node.left; } }
        int next() { TreeNode node = stack.pop(); pushLeft(node.right); return node.val; }
        boolean hasNext() { return !stack.isEmpty(); }
    }
}
