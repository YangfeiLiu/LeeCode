/*
 * @lc app=leetcode.cn id=2 lang=cpp
 *
 * [2] 两数相加
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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        // ListNode* head1 = l1, *head2 = l2;
        // ListNode* newHead = new ListNode(-1);
        // ListNode* p = newHead;
        // int jinwei = 0;
        // while(head1 && head2){
        //     int val = head1->val + head2->val + jinwei;
        //     jinwei = val / 10;
        //     val = val % 10;
        //     ListNode* node = new ListNode(val);
        //     p->next = node;
        //     p = p->next;
        //     head1 = head1->next;
        //     head2 = head2->next;
        // }
        // while(head1){
        //     int val = head1->val + jinwei;
        //     jinwei = val / 10;
        //     val %= 10;
        //     ListNode* node = new ListNode(val);
        //     p->next = node;
        //     p = p->next;
        //     head1 = head1->next;
        // }
        // while(head2){
        //     int val = head2->val + jinwei;
        //     jinwei = val / 10;
        //     val %= 10;
        //     ListNode* node = new ListNode(val);
        //     p->next = node;
        //     p = p->next;
        //     head2 = head2->next;
        // }
        // if(jinwei){
        //     ListNode* node = new ListNode(jinwei);
        //     p->next = node;
        //     p = p->next;
        // }
        // return newHead->next;
        // 用long long也不够存
        // 用string存
        string num1, num2;
        while (l1) {
            int val = l1->val;
            num1 = num1 + to_string(val);
            l1 = l1->next;
        }
        while (l2) {
            int val = l2->val;
            num2 = num2 + to_string(val);
            l2 = l2->next;
        }
        string ans;
        int i = 0, j = 0;
        int val = 0, jinwei = 0;
        while (i < num1.length() && j < num2.length()) {
            val = num1[i] - '0' + num2[j] - '0' + jinwei;
            jinwei = val / 10;
            val %= 10;
            ans = ans + to_string(val);
            i++;
            j++;
        }
        while (i < num1.length()) {
            val = num1[i] - '0' + jinwei;
            jinwei = val / 10;
            val %= 10;
            ans = ans + to_string(val);
            i++;
        }
        while (j < num2.length()) {
            val = num2[j] - '0' + jinwei;
            jinwei = val / 10;
            val %= 10;
            ans = ans + to_string(val);
            j++;
        }
        if (jinwei) ans = ans + to_string(jinwei);
        if (ans.length() == 0) return nullptr;
        int k = 0;
        ListNode* head = new ListNode(ans[k] - '0');
        k++;
        ListNode* p = head;
        while (k < ans.length()) {
            int val = ans[k] - '0';
            ListNode* node = new ListNode(val);
            p->next = node;
            p = p->next;
            k++;
        }
        return head;
    }
};
// @lc code=end
