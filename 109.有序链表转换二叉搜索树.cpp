/*
 * @lc app=leetcode.cn id=109 lang=cpp
 *
 * [109] 有序链表转换二叉搜索树
 */

// @lc code=start
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    TreeNode* sortedListToBST(ListNode* head) {
        vector<int> vec;
        ListNode* p = head;
        while(p){
            vec.push_back(p->val);
            p = p->next;
        }
        return build(vec, 0, vec.size() - 1);
    }

    TreeNode* build(vector<int>& vec, int l, int r){
        if(l > r) return nullptr;
        int mid = l + (r - l) / 2;
        TreeNode* node = new TreeNode(vec[mid]);
        node->left = build(vec, l, mid - 1);
        node->right = build(vec, mid + 1, r);
        return node;
    }
};
// @lc code=end

