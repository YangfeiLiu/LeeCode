/*
 * @lc app=leetcode.cn id=22 lang=cpp
 *
 * [22] 括号生成
 */

// @lc code=start
class Solution {
public:
    vector<string> generateParenthesis(int n) {
        vector<vector<string>> dp(n + 1); //用来保存所有前面生成的括号
        dp[0] = {""};
        dp[1] = {"()"};
        if(n < 2) return dp[n];
        //对于每一组生成，n组生成可以由( p组 ) n - 1 - p组生成，
        for(int i = 2; i <= n; i++){
            for(int j = 0; j < i; j++){
                for(string p: dp[j]){
                    for(string q: dp[i - j - 1]){
                        string str = "(" + p + ")" + q;
                        dp[i].push_back(str);
                    }
                }
            }
        }
        return dp[n];
    }
};
// @lc code=end

