/*
 * @lc app=leetcode.cn id=19 lang=cpp
 *
 * [19] 删除链表的倒数第N个节点
 */

// @lc code=start
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode* p1 = head, *p2 = head;
        while(n--){
            p1 = p1->next;
        }
        if(!p1) return head->next; // 删除头节点
        while(p1->next){
            p1 = p1->next;
            p2 = p2->next;
        }
        ListNode* delnode = p2->next;
        p2->next = p2->next->next;// 删除当前节点，但是这时有个问题，被删除的节点没有被释放掉
        delete delnode;
        return head;
    }
};
// @lc code=end

