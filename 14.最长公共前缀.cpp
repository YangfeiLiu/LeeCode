/*
 * @lc app=leetcode.cn id=14 lang=cpp
 *
 * [14] 最长公共前缀
 */

// @lc code=start
class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        int len = 0;
        if(strs.size() == 0) return "";
        while(true)
        {
            if(len >= strs[0].length()) return strs[0].substr(0, len);
            char ch = strs[0].at(len);
            for(int i = 1; i < strs.size(); i++)
            {
                if(len >= strs[i].length()) return strs[i];
                if(strs[i].at(len) != ch) return strs[i].substr(0, len);
            }
            len++;
        }
    }
};
// @lc code=end

