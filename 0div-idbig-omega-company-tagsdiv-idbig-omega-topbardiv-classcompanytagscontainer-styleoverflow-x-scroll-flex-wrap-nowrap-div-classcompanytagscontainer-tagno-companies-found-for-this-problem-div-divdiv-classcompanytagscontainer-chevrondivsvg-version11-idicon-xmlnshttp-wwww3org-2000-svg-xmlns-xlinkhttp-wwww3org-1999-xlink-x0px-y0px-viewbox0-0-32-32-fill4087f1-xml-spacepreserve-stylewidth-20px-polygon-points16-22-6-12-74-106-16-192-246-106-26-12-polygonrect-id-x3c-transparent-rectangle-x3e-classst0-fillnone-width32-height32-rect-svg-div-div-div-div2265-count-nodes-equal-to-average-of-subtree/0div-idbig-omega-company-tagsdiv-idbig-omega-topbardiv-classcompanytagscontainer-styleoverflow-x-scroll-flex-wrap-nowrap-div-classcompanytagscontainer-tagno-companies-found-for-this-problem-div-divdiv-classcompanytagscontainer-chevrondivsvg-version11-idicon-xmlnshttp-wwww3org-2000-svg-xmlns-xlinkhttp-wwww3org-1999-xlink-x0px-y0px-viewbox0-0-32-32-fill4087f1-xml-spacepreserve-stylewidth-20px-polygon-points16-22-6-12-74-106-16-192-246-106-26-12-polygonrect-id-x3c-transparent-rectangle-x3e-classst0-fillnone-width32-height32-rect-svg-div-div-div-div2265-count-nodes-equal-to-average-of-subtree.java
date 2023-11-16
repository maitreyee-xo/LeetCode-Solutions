/**
 * Definition for a binary tree node.
 * public class TreeNode {
 *     int val;
 *     TreeNode left;
 *     TreeNode right;
 *     TreeNode() {}
 *     TreeNode(int val) { this.val = val; }
 *     TreeNode(int val, TreeNode left, TreeNode right) {
 *         this.val = val;
 *         this.left = left;
 *         this.right = right;
 *     }
 * }
 */
class Solution {
    public int count = 0;    
    public int averageOfSubtree(TreeNode root) {
        dfs(root);
        return count;
    }    
    public int[] dfs(TreeNode node) {
        if (node == null)   return new int[]{0, 0};
        int[] left = dfs(node.left);
        int[] right = dfs(node.right);        
        int totalSum = left[0] + right[0] + node.val;
        int totalCount = left[1] + right[1] + 1;        
        if (node.val == totalSum/totalCount)count++;        
        return new int[]{totalSum, totalCount};
    }
}