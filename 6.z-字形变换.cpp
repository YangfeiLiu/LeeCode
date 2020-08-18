/*
 * @lc app=leetcode.cn id=6 lang=cpp
 *
 * [6] Z 字形变换
 */

// @lc code=start
class Solution {
public:
    string convert(string s, int numRows) {
        if(numRows < 2) return s;
        vector<string> vec(numRows);
        int flag = -1;
        int r = 0;
        for(int i = 0; s[i] != '\0'; i++){
            vec[r] += s[i];
            if(r == 0 || r == numRows - 1) flag *= -1;
            r += flag;
        }
        string ans;
        for(int i = 0; i < numRows; i++){
            ans += vec[i];
        }
        return ans;
    }
};
// @lc code=end

