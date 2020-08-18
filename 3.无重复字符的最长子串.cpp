/*
 * @lc app=leetcode.cn id=3 lang=cpp
 *
 * [3] 无重复字符的最长子串
 */

// @lc code=start
class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        unordered_set<char> us;
        int i = 0, left = 0;
        int maxv = 0;
        for(i; s[i] != '\0'; i++){
            while(us.find(s[i]) != us.end()){
                us.erase(s[left]);
                left++;
            }
            maxv = max(maxv, i - left + 1);
            us.insert(s[i]);
        }
        return maxv;
    }
};
// @lc code=end

