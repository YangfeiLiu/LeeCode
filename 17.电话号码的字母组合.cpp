/*
 * @lc app=leetcode.cn id=17 lang=cpp
 *
 * [17] 电话号码的字母组合
 */

// @lc code=start
class Solution {
public:
    vector<string> ans;
    string str;
    vector<string> map{"", "", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};
    vector<string> letterCombinations(string digits) {
        if(digits.length() == 0) return ans;
        dfs(digits, 0);
        return ans;
    }

    void dfs(string digits, int begin){
        if(begin == digits.length()){
            ans.push_back(str);
            return;
        }
        int val = digits[begin] - '0';
        for(int i = 0; i < map[val].length(); i++){
            str += map[val][i];
            dfs(digits, begin+1);
            str.erase(str.length() - 1);
        }
    }
};
// @lc code=end

