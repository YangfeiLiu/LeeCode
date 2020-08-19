/*
 * @lc app=leetcode.cn id=647 lang=cpp
 *
 * [647] 回文子串
 */

// @lc code=start
class Solution {
public:
    /*
    //暴力，时间复杂度是O(n^2logn)
    int countSubstrings(string s) {
        int len = s.length();
        if(len < 2) return len;
        int cnt = len;
        for(int i = 0; i < len - 1; i++){
            for(int j = i + 1; j < len; j++){
                if(fun(s, i, j)) cnt++;
            }
        }
        return cnt;
    }

    bool fun(string s, int i, int j){
        while(i < j){
            if(s[i] != s[j]) return false;
            else{
                i++;
                j--;
            }
        }
        return true;
    }
    */
   //动态规划方法
   int countSubstrings(string s) {
        int len = s.length();
        if(len < 2) return len;
        int cnt = 0;
        vector<vector<bool>> dp(len, vector<bool>(len, false));
        for(int j = 0; j < len; j++){
            for(int i = 0; i <= j; i++){
                if(i == j){
                    dp[i][j] = true;
                    cnt++;
                }
                if(j - i == 1 && s[i] == s[j]){
                    dp[i][j] = true;
                    cnt++;
                }
                if(j - i > 1 && s[i] == s[j] && dp[i+1][j-1]){
                    dp[i][j] = true;
                    cnt++;
                }
            }
        }
        return cnt;
   }
};
// @lc code=end

