import java.util.ArrayList;
import java.util.LinkedList;
import java.util.Queue;

class TreeNode {
    int data;
    TreeNode left, right;

    public TreeNode(int data) {
        this.data = data;
        this.left = this.right = null;
    }
}

class height_levelOrder {
    TreeNode root;

    public TreeNode insert(TreeNode root, int data) {
        // If the tree/subtree is empty, create a new node
        if (root == null)  return new TreeNode(data);
        // Recursively insert into the left or right subtree
        if (data <= root.data) {
            root.left = insert(root.left, data);
        } else {
            root.right = insert(root.right, data);
        }
        return root; // Return the updated root
    }

    // Preorder Traversal (Root, Left, Right)
    public void preOrder(TreeNode root) {
        if (root == null) return;
        System.out.print(root.data + " ");
        preOrder(root.left);
        preOrder(root.right);
    }

    // ------------- Height-------------------------
    // My way
    // public int height(int m,int c, TreeNode root) {
    //     if(root == null) return c;
    //     m = max(height(m, c+1, root.left), height(m, c+1, root.right));
    //     return m;
    // }
    public int height(TreeNode root) {
        if (root == null) return 0;  // Base case: height of an empty tree is 0
        return 1 + Math.max(height(root.left), height(root.right));  // Max height formula
    }
    // ------------- Height ends -------------------------

    // ------------- Level order -------------------------
    public void levelOrder(TreeNode root) {
        if(root == null) return;
        Queue<TreeNode> que = new LinkedList<>();
        que.add(root);
        while (!que.isEmpty()) {
            int levelSize = que.size(); // Number of nodes at the current level
    
            for (int i = 0; i < levelSize; i++) {
                TreeNode temp = que.poll();
                System.out.print(temp.data + " "); // Print nodes in the same level
    
                if (temp.left != null) que.add(temp.left);
                if (temp.right != null) que.add(temp.right);
            }
            System.out.println(); // Move to a new line after finishing a level
        }
    }
    // ------------- Level order ends -------------------------

    public static void main(String[] args) {
        height_levelOrder tree = new height_levelOrder();

        // Insert values into the tree
        int[] values = {5, 3, 7, 2, 4, 6, 8, 1}; // Example values
        for (int value : values) {
            tree.root = tree.insert(tree.root, value); // Updating root
        }

        // Print Preorder Traversal
        System.out.println("Preorder Traversal:");
        tree.preOrder(tree.root);
        System.out.println();
        System.out.println(tree.height(tree.root));
        System.out.println();
        tree.levelOrder(tree.root);
    }
}
