/*
 * @lc app=leetcode.cn id=5 lang=cpp
 *
 * [5] 最长回文子串
 */

// @lc code=start
class Solution {
public:
    string longestPalindrome(string s) {
        int len = s.length();
        if(len < 2) return s;
        vector<vector<int>> dp(len, vector<int>(len, 0));
        dp[0][0] = 1;
        int start = 0, end = 0;
        for(int r = 1; r < len; r++){
            for(int l = 0; l < r; l++){
                if(s[l] == s[r] && (r - l <= 2 || dp[l+1][r-1])){
                    dp[l][r] = 1;
                    if(r - l + 1 > end - start + 1){
                        start = l, end = r;
                    }
                }
            }
        }
        return s.substr(start, end - start + 1);
    }
};
// @lc code=end

