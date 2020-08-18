/*
 * @lc app=leetcode.cn id=110 lang=cpp
 *
 * [110] 平衡二叉树
 */

// @lc code=start
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    bool ans = true;
    bool isBalanced(TreeNode* root) {
        Depth(root);
        return ans;
    }

    int Depth(TreeNode* root){
        if(root == nullptr) return 0;
        int left = Depth(root->left) + 1;
        int right = Depth(root->right) + 1;
        if(abs(left - right) > 1) ans = false;
        return max(left, right);
    }
};
// @lc code=end

