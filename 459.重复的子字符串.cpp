/*
 * @lc app=leetcode.cn id=459 lang=cpp
 *
 * [459] 重复的子字符串
 */

// @lc code=start
class Solution {
public:
    bool repeatedSubstringPattern(string s) {
        return (s + s).find(s, 1) != s.length();
        //构造一个双倍字符串，如果原来的s有循环节，则
        //find返回从1查找到的s的起始位置，该位置一定不是s的长度，如果没有循环节
        //则find返回的位置一定等于s的长度
    }
};
// @lc code=end

