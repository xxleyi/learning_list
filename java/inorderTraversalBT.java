// Given a binary tree, return the inorder traversal of its nodes' values.

import java.util.List;
import java.util.ArrayList;
import java.util.Stack;

class TreeNode {
    int val;
    TreeNode left;
    TreeNode right;

    TreeNode(int x) {
        val = x;
        left = null;
        right = null;
    }
}


class Solution {
    private Stack<TreeNode> stack = new Stack<>();

    private void goAlongLeftBranch(TreeNode cur) {
        while (cur != null) {
            stack.push(cur);
            cur = cur.left;
        }
    }
    
    public List<Integer> inorderTraversal(TreeNode root) {
        List<Integer> res = new ArrayList<>();
        TreeNode cur = root;
        while (true) {
            goAlongLeftBranch(cur);
            if (stack.empty()) {
                break;
            }
            cur = stack.pop();
            res.add(cur.val);
            cur = cur.right;
        }
        return res;
    }

    public static void main(String[] args) {
        TreeNode root = new TreeNode(4);
        root.left = new TreeNode(1);
        root.right = new TreeNode(5);
        root.left.right = new TreeNode(3);
        root.left.right.left = new TreeNode(2);
        Solution s = new Solution();
        System.out.println(s.inorderTraversal(root));
    }
}