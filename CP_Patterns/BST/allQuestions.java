package CP_Patterns.BST;
import java.util.ArrayList;
import java.util.Collections;
import java.util.LinkedList;
import java.util.List;
import java.util.Queue;
import java.util.Stack;
/*
        5
        /\
       3  7
      /\  /\
     1 4 6  8
 */
/*
    Insert
    PreOrder, InOrder, PostOrder, LevelOrder, zigzagLevelOrder, DFS, BFS
    Search
    height - Longest path from the node to a leaf
    depth -  Number of edges from the root to the node
    validBST
    Leaf Similar Trees - the leaves of 2 trees are same

    minDistBetweenNodes
    allElementsIn2BST - 1305
    pathToNode
    deleteNode
    balanceTree
    Flip tree / mirror
    Reverse
    LCA
    Print leaf
    Range Sum
    PreOrderToBST (DFS to BST)
    SortedArrToBST (inOrder to BST)
    treeSumTotal
    minSum
    kthLargest
    kthSmallest
*/
class TreeNode {
    int val;
    TreeNode left;
    TreeNode right;
    TreeNode() {}
    TreeNode(int val) {this.val = val;}
}
public class allQuestions {
    public static TreeNode insert(TreeNode root, int val) { // O(h), worst case - O(n)
        if(root == null) return new TreeNode(val);
        if(root.val > val) root.left = insert(root.left, val);
        else root.right = insert(root.right, val);
        return root;
    }
    //---------------------------------------------------------------------------------------
    public static void preOrder(TreeNode root) { // 5 3 1 4 7 6 8 - DFS - O(n)
        if(root == null) return;
        System.out.print(root.val + " ");
        preOrder(root.left);
        preOrder(root.right);
    }
    //---------------------------------------------------------------------------------------
    public static void inOrder(TreeNode root) { // 1 3 4 5 6 7 8 - Sorted - O(n)
        if(root == null) return;
        inOrder(root.left);
        System.out.print(root.val + " ");
        inOrder(root.right);
    }
    //---------------------------------------------------------------------------------------
    public static void postOrder(TreeNode root) { // 1 4 3 6 8 7 5 - O(n)
        if(root == null) return;
        postOrder(root.left);
        postOrder(root.right);
        System.out.print(root.val + " ");
    }
    //---------------------------------------------------------------------------------------
    public static void levelOrder(TreeNode root) { // 5 3 7 1 4 6 8 - BFS - O(n)
        if(root == null) return;
        Queue<TreeNode> q = new LinkedList<>();
        q.add(root);
        while(!q.isEmpty()) {
            int size = q.size();
            for(int i = 0; i < size; i++) {
                TreeNode cur = q.poll();
                System.out.print(cur.val + " ");
                if(cur.left != null) q.add(cur.left);
                if(cur.right != null) q.add(cur.right);
            }
        }
    }
    //---------------------------------------------------------------------------------------
    public static List<List<Integer>> zigzagLevelOrder(TreeNode root) { // 5 7 3 1 4 6 8 - BFS - O(n)
        List<List<Integer>> ans = new ArrayList<>();
        if (root == null) return ans;
        Queue<TreeNode> q = new LinkedList<>();
        q.add(root);
        boolean flag = false;  // flag to alternate the level order
        while (!q.isEmpty()) {
            int size = q.size();
            List<Integer> row = new ArrayList<>();
            for (int i = 0; i < size; i++) {
                TreeNode cur = q.poll();
                row.add(cur.val);
                // Add children in the appropriate order based on the flag
                if (cur.left != null) q.add(cur.left);
                if (cur.right != null) q.add(cur.right);
            }
            if (flag) Collections.reverse(row); // If the flag is true, reverse the row (right to left)
            // Note: if u try to add the ele based on flag then the insertion of ele will not be correct we just need print in rev order not putting the ele in stack in rev so Collection.rev
            flag = !flag; // Toggle the flag after each level
            ans.add(row); // Add the current row to the result
        }

        return ans;
    }
    //---------------------------------------------------------------------------------------
    public static void DFS(TreeNode root) { // 5 3 1 4 7 6 8 - iterative version of DFS - O(n)
        if(root == null) return;
        Stack<TreeNode> s = new Stack<>();
        s.push(root);
        while(!s.isEmpty()) {
            TreeNode cur = s.pop();
            System.out.print(cur.val + " ");
            if(cur.right != null) s.add(cur.right);
            if(cur.left != null) s.add(cur.left);
        }
    }
    //---------------------------------------------------------------------------------------
    public static boolean search(TreeNode root, int val) {
        if(root == null) return false;
        if(root.val > val) return search(root.left, val);
        if(root.val < val) return search(root.right, val);
        return true;
    }
    //---------------------------------------------------------------------------------------
    public static int height(TreeNode root) {
        if(root == null) return 0;
        return Math.max(height(root.left), height(root.right)) + 1;
    }
    //---------------------------------------------------------------------------------------
    public static int depth(TreeNode root, int val, int c) {
        if(root == null) return 0;
        if(root.val == val) return c;
        if(root.val > val) return depth(root.left, val, c+1);
        else return depth(root.right, val, c+1);
    }
    //---------------------------------------------------------------------------------------
    public static boolean validBST(TreeNode root, int min, int max) {
        if(root == null) return true; // Base case: an empty tree is a valid BST
        if(root.val < min || root.val > max) return false; // if out of range
        return validBST(root.left, min, root.val) && validBST(root.right, root.val, max);
    }
    //---------------------------------------------------------------------------------------
    private void collectLeaves(TreeNode root, List<Integer> leaves) {
        if (root == null) return;        
        if (root.left == null && root.right == null) {
            leaves.add(root.val);
            return;
        }
        collectLeaves(root.left, leaves);
        collectLeaves(root.right, leaves);
    }
    //---------------------------------------------------------------------------------------
    public boolean leafSimilar(TreeNode root1, TreeNode root2) {
        List<Integer> leaves1 = new ArrayList<>();
        List<Integer> leaves2 = new ArrayList<>();
        collectLeaves(root1, leaves1);
        collectLeaves(root2, leaves2);
        return leaves1.equals(leaves2);
    }
    //---------------------------------------------------------------------------------------


    public static void main(String[] args) {
        TreeNode root = null;
        int a[] = {5, 3, 7, 1, 4, 6, 8};
        for(int i: a) root = insert(root, i);
        System.out.println("PreOrder: ");
        preOrder(root);
        System.out.println("\nInOrder: ");
        inOrder(root);
        System.out.println("\nPostOrder: ");
        postOrder(root);
        System.out.println("\nLevelOrder: ");
        levelOrder(root);
        System.out.println("\nDFS iterative: ");
        DFS(root);
        System.out.println();
        System.out.println("Search 8: " + search(root, 8));
        System.out.println("height:" + height(root));
        System.out.println("Depth 8: " + depth(root, 8, 0));
        System.out.println("ValidBST: " + validBST(root, Integer.MIN_VALUE, Integer.MAX_VALUE));
    }
}
