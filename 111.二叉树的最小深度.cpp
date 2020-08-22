/*
 * @lc app=leetcode.cn id=111 lang=cpp
 *
 * [111] 二叉树的最小深度
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
    int minDepth(TreeNode* root) {
        int depth = 1;
        if(!root) return 0;
        queue<TreeNode*> qu;
        qu.push(root);
        queue<TreeNode*> cur;
        while(!qu.empty()){
            TreeNode* node = qu.front();
            qu.pop();
            //如果一个节点没有子节点就输出
            if(node && !node->left && !node->right) return depth;
            if(node){
                cur.push(node->left);
                cur.push(node->right);
            }
            if(qu.empty()){
                qu = cur;
                cur = queue<TreeNode*>();
                depth++;
            }
        }
        return depth;
    }
};
// @lc code=end

