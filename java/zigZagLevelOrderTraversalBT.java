// Given a binary tree, return the zigzag level order traversal of its nodes' values. 
// (ie, from left to right, then right to left for the next level and alternate between).

import java.util.ArrayList;
import java.util.Deque;
import java.util.LinkedList;
import java.util.List;

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
    public List<List<Integer>> zigZagLevelOrder(TreeNode root) {
        List<List<Integer>> res = new ArrayList<>();
        if (root == null) {
            return res;
        }
        Deque<TreeNode> q1 = new LinkedList<>();
        Deque<TreeNode> q2 = new LinkedList<>();
        TreeNode cur = root;
        q1.add(cur);
        Boolean leftToRight = true;
        while (true) {
            List<Integer> sub_res = new ArrayList<>();
            while (q1.size() > 0) {
                cur = q1.poll();
                sub_res.add(cur.val);
                if (leftToRight) {
                    if (cur.left != null) {
                        q2.addFirst(cur.left);
                    }
                    if (cur.right != null) {
                        q2.addFirst(cur.right);
                    }
                } else {
                    if (cur.right != null) {
                        q2.addFirst(cur.right);
                    }
                    if (cur.left != null) {
                        q2.addFirst(cur.left);
                    }
                }
            }
            res.add(sub_res);
            if (q2.size() == 0)
                break;
            leftToRight = !leftToRight;
            q1 = q2;
            q2 = new LinkedList<>();
        }
        return res;
    }

    public static void main(String[] args) {
        TreeNode root = new TreeNode(4);
        root.left = new TreeNode(1);
        root.right = new TreeNode(5);
        root.left.right = new TreeNode(3);
        root.left.right.left = new TreeNode(2);
        root.left.right.right = new TreeNode(3);
        root.left.left = new TreeNode(8);
        root.left.left.left = new TreeNode(4);
        root.left.left.right = new TreeNode(5);
        Solution s = new Solution();
        System.out.println(s.zigZagLevelOrder(root));
    }
}