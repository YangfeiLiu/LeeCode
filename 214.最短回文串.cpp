/*
 * @lc app=leetcode.cn id=214 lang=cpp
 *
 * [214] 最短回文串
 */

// @lc code=start
class Solution {
public:
    string shortestPalindrome(string s) {
        int len = s.length();
        if(len < 2) return s;
        int i = 0, j = len - 1;
        int k = j;
        int cnt = 0;
        while(true){
            while(i < j && s[i] == s[j]){
                i++;
                j--;
            }
            if(i < j){
                cnt++;
                i = 0;
                j = k - cnt;
            }
            else break;
        }
        string ss = s;
        for(int i = len - cnt; i < len; i++)
            ss = s[i] + ss;
        return ss;
    }
};
// @lc code=end

