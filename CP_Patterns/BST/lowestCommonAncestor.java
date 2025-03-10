// package CP_Patterns.BST;

// import javax.swing.tree.TreeNode;

// public class lowestCommonAncestor {
//     public TreeNode lowestCommonAncestor(TreeNode root, TreeNode p, TreeNode q) {
//         // If the root is null, return null
//         if (root == null) {
//             return null;
//         }

//         // If both p and q are smaller than root, LCA must be in the left subtree
//         if (p.val < root.val && q.val < root.val) {
//             return lowestCommonAncestor(root.left, p, q);
//         }

//         // If both p and q are greater than root, LCA must be in the right subtree
//         if (p.val > root.val && q.val > root.val) {
//             return lowestCommonAncestor(root.right, p, q);
//         }

//         // If p and q are on opposite sides, or one of them is the root, return the root
//         return root;
//     }
// }
