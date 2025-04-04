package CP_Patterns.BST;
import java.util.*;
// Note: Inorder of BST gives a sorted array
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
    98. validBST
    Leaf Similar Trees - the leaves of 2 trees are same
    Print leaf
    Print leaf in alt order - 1st, nth, 2nd, (n-1)th, 3rd,........
    226. Invert Tree - swapping of left and right children
    101. Symmetric Tree - left side is mirror of right
    938. Range Sum of BST - sum of all nodes b/w a range
    1008. Construct Binary Search Tree from Preorder Traversal (DFS to BST)
    108. Convert Sorted Array to Binary Search Tree (inOrder to BST)
    404. Sum of left leaves
    222. Count Complete Tree Nodes - count nodes
    112. Path Sum - path to target sum
    129. Sum Root to Leaf Numbers - amazon asked - root to all leafs path no sum
    230. kthSmallest bst
    2583. Kth Largest Sum in a Binary Tree
    2415. Reverse Odd Levels of Binary Tree
    783. Minimum Distance Between BST Nodes
    1305. All Elements in Two Binary Search Trees
    257. Binary Tree Paths

    2096. Step-By-Step Directions From a Binary Tree Node to Another
    minDistBetweenNodes
    pathToNode
    deleteNode
    balanceTree
    LCA
    1123. Lowest Common Ancestor of Deepest Leaves
    minSum
    988. Smallest String Starting From Leaf
    1130. Minimum Cost Tree From Leaf Values
    1038. Binary Search Tree to Greater Sum Tree
    99. Recover Binary Search Tree
    971. Flip Binary Tree To Match Preorder Traversal
    951. Flip Equivalent Binary Trees
    105. Construct Binary Tree from Preorder and Inorder Traversal
    1161. Maximum Level Sum of a Binary Tree
    222. Count Complete Tree Nodes
    863. All Nodes Distance K in Binary Tree
    124. Binary Tree Maximum Path Sum - hard
    2867. Count Valid Paths in a Tree - hard
    113. Path Sum II
*/
class TreeNode {
    int val;
    TreeNode left;
    TreeNode right;
    TreeNode() {}
    TreeNode(int val) {this.val = val;}
}
public class AllQue {
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
    public static void inOrder2(TreeNode root) {
        Stack<TreeNode> stack = new Stack<>();
        while (root != null || !stack.isEmpty()) { // Start from the root node
            while (root != null) { // Go to the leftmost node
                stack.push(root);
                root = root.left;
            }
            // Pop the top node from the stack (this is the node we visit)
            root = stack.pop();
            System.out.print(root.val + " ");
            // Move to the right subtree
            root = root.right;
        }

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
    public static void printLeaf(TreeNode root) { // 1 4 6 8
        if(root == null) return;
        printLeaf(root.left);
        if(root.left == null && root.right == null) System.out.print(root.val + " ");
        printLeaf(root.right);
    }
    //---------------------------------------------------------------------------------------
    public static void printLeafinAltOrder(TreeNode root) { // 1 8 4 6
        if(root == null) return;
        // Approach 1 using extra space:
        List<Integer> l = new ArrayList<>();
        Stack<TreeNode> s = new Stack<>();
        s.add(root);
        while(!s.isEmpty()) {
            TreeNode cur = s.pop();
            if(cur.right!=null) s.add(cur.right);
            if(cur.left!=null) s.add(cur.left);
            if(cur.left == null && cur.right == null) l.add(cur.val);
        }
        for(int i = 0; i < l.size()/2;i++) System.out.print(l.get(i) + " " + l.get(l.size()-i-1) + " ");
    }
    //---------------------------------------------------------------------------------------
    public static TreeNode invertTree(TreeNode root) { // 8 7 6 5 4 3 1
        if (root == null) {
            return null;
        }
        // Swap the left and right children
        TreeNode temp = root.left;
        root.left = root.right;
        root.right = temp;
        // Recursively invert the left and right subtrees
        invertTree(root.left);
        invertTree(root.right);
        return root;
    }
    //---------------------------------------------------------------------------------------
    public static boolean symmetric(TreeNode root1, TreeNode root2) {
        if (root1 == null && root2 == null)
        return true;
        // For two trees to be mirror images, the following
        // three conditions must be true
        // 1.) Their root node's key must be same
        // 2.) left subtree of left tree and right subtree of
        // right tree have to be mirror images
        // 3.) right subtree of left tree and left subtree of
        // right tree have to be mirror images
        if (root1 != null && root2 != null && root1.val == root2.val)
            return symmetric(root1.left, root2.right) && symmetric(root1.right, root2.left);
        // if none of above conditions is true then root1 and root2 are not mirror images
        return false;
    }
    //---------------------------------------------------------------------------------------
    public static int rangeSum(TreeNode r, int l, int h) { // using inorder traversal u can use any traversal,  O(n), O(h) can be O(n) if tree unbalanced
        if (r == null) return 0;  // If the node is null, return 0
        int sum = 0;
        sum += rangeSum(r.left, l, h); // Traverse left subtree and get the sum
        if (r.val >= l && r.val <= h) sum += r.val; // If the current node value is within the range [low, high], add it to the sum
        sum += rangeSum(r.right, l, h); // Traverse right subtree and get the sum
        return sum; // Return the accumulated sum
    }
    //---------------------------------------------------------------------------------------
    public TreeNode bstFromPreorder(int[] preorder) {
        TreeNode root = null;
        for(int n: preorder) root = insert(root, n);
        return root;
    }
    //---------------------------------------------------------------------------------------
    public TreeNode bstFromInorder(int a[], int l, int r) { // using binary search to get to the middle, as in inorder root is in middle always
        if(l > r) return null;
        int mid = l + (r-l) / 2;
        TreeNode node = new TreeNode(a[mid]);
        node.left = bstFromInorder(a,l,mid-1);
        node.right = bstFromInorder(a,mid+1,r);
        return node;
    }
    //---------------------------------------------------------------------------------------
    public static int sumOfLeftLeaves(TreeNode r) { // using inorder u can use any
        if (r == null) return 0;
        int sum = 0;
        sum += sumOfLeftLeaves(r.left);
        if(r.left != null && r.left.left == null && r.left.right == null) {
            sum+=r.left.val;
        }
        sum += sumOfLeftLeaves(r.right);
        return sum;
    }
    //---------------------------------------------------------------------------------------
    public int countNodes(TreeNode root) {
        if(root==null) return 0;
        if(root.left == null && root.right == null) return 1;
        return 1+countNodes(root.left) + countNodes(root.right);
    }
    //---------------------------------------------------------------------------------------
    public boolean hasPathSum(TreeNode root, int targetSum) {
        if(root == null) return false;
        if(root.left == null && root.right == null) return root.val == targetSum; // Check only if its a leaf
        return hasPathSum(root.left,targetSum - root.val) || hasPathSum(root.right, targetSum-root.val);
    }
    //---------------------------------------------------------------------------------------
    public static int sumabc(TreeNode root,int currentSum){
        if (root==null) return 0;
        currentSum = currentSum * 10 + root.val;
        if (root.left==null && root.right==null) return currentSum;
        return sumabc(root.left,currentSum) + sumabc(root.right,currentSum);
    }
    //---------------------------------------------------------------------------------------
    public int kthSmallest(TreeNode root, int k) {
        Stack<TreeNode> stack = new Stack<>();
        TreeNode curr = root;
        while (curr != null || !stack.isEmpty()) {
            while (curr != null) {
                stack.push(curr);
                curr = curr.left;
            }
            curr = stack.pop();
            k--;
            if (k == 0) return curr.val;
            curr = curr.right;
        }
        return -1; // Should not reach here if k is valid
    }
    // recur version
    int res = 0, count = 0;  // To track how many nodes we've processed so far
    public void inOrder(TreeNode root, int k) {
        if (root == null) return;
        inOrder(root.left, k);// Traverse the left subtree
        count++;
        if (count == k) { res = root.val; return; }
        inOrder(root.right, k);
    }
    // For kth largest swap left right lines
    //---------------------------------------------------------------------------------------
    public long kthLargestLevelSum(TreeNode root, int k) { // O(nlogk), O(n)
        PriorityQueue<Long> minHeap = new PriorityQueue<>(); // O(k) - space
        Queue<TreeNode> q = new LinkedList<>(); // O(n) - space
        q.add(root);
        while (!q.isEmpty()) {// bfs O(n)
            int levelSize = q.size();
            long sum = 0;
            for (int i = 0; i < levelSize; i++) {
                TreeNode current = q.poll(); // poll O(logk)
                sum += current.val;
                if (current.left != null) q.add(current.left);
                if (current.right != null) q.add(current.right);
            }
            minHeap.offer(sum); // add O(logk)
            if (minHeap.size() > k) minHeap.poll();
        }
        return minHeap.size() < k ? -1 : minHeap.peek();
    }
    //---------------------------------------------------------------------------------------
    // Reverse odd levels 
    // Bfs iterative O(n), O(n)
    public TreeNode reverseOddLevels(TreeNode root) {
        if (root == null) return null;
        Queue<TreeNode> q = new LinkedList<>();
        q.add(root);
        int level = 1;
        while (!q.isEmpty()) {
            int row = q.size();
            TreeNode[] levelNodes = new TreeNode[row]; // as array is faster than list, worst case space is O(n/2)
            for (int i = 0; i < row; i++) {
                TreeNode cur = q.poll();
                levelNodes[i] = cur;
                if (cur.left != null) q.offer(cur.left);
                if (cur.right != null) q.offer(cur.right);
            }
            if ((level & 1) == 0) { // if even level swap, O(k)
                int start = 0, end = row - 1;
                while (start < end) {
                    int temp = levelNodes[start].val;
                    levelNodes[start].val = levelNodes[end].val;
                    levelNodes[end].val = temp;
                    start++;
                    end--;
                }
            }
            level++;
        }
        return root;
    }
    // DFS recur O(n), O(h) -> height of tree, balanced tree-O(logn), unbalanced(O(n))
    public TreeNode reverseOddLevels1(TreeNode root) {
        dfs(root.left,root.right,1);
        return root;
    }
    void dfs(TreeNode lnode,TreeNode rnode,int lvl){
        if(lnode == null || rnode == null) 
            return;
        if((lvl & 1) == 1){
            int t = lnode.val;
            lnode.val = rnode.val;
            rnode.val = t;
        }
        dfs(lnode.left,rnode.right,lvl+1);
        dfs(lnode.right,rnode.left,lvl+1);
    }
    //---------------------------------------------------------------------------------------
    private int prev = -1; // to store the previous node value during in-order traversal
    private int minDiff = Integer.MAX_VALUE; // to store the minimum difference
    public void inorder(TreeNode root) {
        if (root == null) return;
        inorder(root.left);
        if (prev != -1) {
            minDiff = Math.min(minDiff, root.val - prev);
        }
        prev = root.val;
        inorder(root.right);
    }
    //---------------------------------------------------------------------------------------
    public static void inOrder(TreeNode root, List<Integer> ans) {
        if(root == null) return;
        inOrder(root.left, ans);
        ans.add(root.val);
        inOrder(root.right, ans);
    }
    public List<Integer> getAllElements(TreeNode root1, TreeNode root2) {
        List<Integer> ans = new ArrayList<>();
        inOrder(root1, ans);
        inOrder(root2, ans);
        Collections.sort(ans);
        return ans;
    }
    //---------------------------------------------------------------------------------------
    public List<String> binaryTreePaths(TreeNode root) {
        List<String> output = new ArrayList();
        buildBinaryTreePaths(root, new StringBuilder(), output);
        return output;
    }
    public void buildBinaryTreePaths(TreeNode root, StringBuilder sb, List<String> output) {
        if(root == null) return;
        int length = sb.length();
        sb.append(root.val);
        if(root.left == null && root.right == null) output.add(sb.toString()); // this is a leaf
        else {
            sb.append("->");
            buildBinaryTreePaths(root.left, sb, output);
            buildBinaryTreePaths(root.right, sb, output);
        }
        sb.setLength(length);  // Once you've finished exploring a child (or both children), you reset the StringBuilder back to its previous length to backtrack and avoid affecting the path for the next sibling node or the parent node.
    }
    public static void main(String[] args) {
        TreeNode root = null;
        int a[] = {5, 3, 1, 4, 7, 6, 8};
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
        System.out.print("ValidBST: " + validBST(root, Integer.MIN_VALUE, Integer.MAX_VALUE));
        System.out.println("\nAll Leafs: ");printLeaf(root);
        System.out.println("\nAll Leafs in Alt order: ");printLeafinAltOrder(root);
        System.out.println("\nInverted Tree inorder: ");
        invertTree(root);
        inOrder(root);
        System.out.println("Tree is symmetric : " + symmetric(root.left, root.right));
        System.out.println("Range sum between 4 and 6 : "+ rangeSum(root, 4, 7));
        System.out.println("Sum of left leaves : " + sumOfLeftLeaves(root));
        System.out.println("Sum of all path to leaf : " + sumabc(root, 0));
    }
}
