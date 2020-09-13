/*
 * @lc app=leetcode.cn id=5 lang=cpp
 *
 * [5] 最长回文子串
 */

// @lc code=start
class Solution {
public:
    string longestPalindrome(string s) {
        // 动态规划  时间复杂度O(N^2)
        /*
        int len = s.length();
        if(len < 2) return s;
        vector<vector<int>> dp(len, vector<int>(len, 0));//dp[i][j]表示从i到j是否是回文串
        dp[0][0] = 1;
        int start = 0, end = 0;
        for(int r = 1; r < len; r++){
            for(int l = 0; l < r; l++){
                if(s[l] == s[r] && (r - l <= 2 || dp[l+1][r-1])){
                    dp[l][r] = 1;
                    if(r - l + 1 > end - start + 1){//如果长度更长，就更新
                        start = l, end = r;
                    }
                }
            }
        }
        return s.substr(start, end - start + 1);
        */
       // 中心扩散法 时间复杂度O(NlogN)
       int len = s.length();
       string ans;
       int maxl = 0;
       if(len < 2) return s;
       for(int i = 0; i < len - 1; i++){
           string s1 = longest(s, i, i);
           string s2 = longest(s, i, i + 1);
           string temp = s1.length() > s2.length() ? s1 : s2;
           if(temp.length() > maxl){
               ans = temp;
               maxl = temp.length();
           }
       }
       return ans;
    }
    // 确定以 l, r为中心的最长的回文串
    string longest(string s, int l, int r){
        while(l >= 0 && r < s.length()){
            if(s[l] == s[r]){
                l--;
                r++;
            }
            else break;
        }
        return s.substr(l + 1, r - l - 1); // 注意这里的取值
    }
};
// @lc code=end

