/*
 * @lc app=leetcode.cn id=657 lang=cpp
 *
 * [657] 机器人能否返回原点
 */

// @lc code=start
class Solution {
public:
    bool judgeCircle(string moves) {
        int i = 0, j = 0;
        for(char ch: moves){
            if(ch == 'U') i--;
            if(ch == 'D') i++;
            if(ch == 'L') j--;
            if(ch == 'R') j++;
        }
        return i == 0 && j == 0;
    }
};
// @lc code=end

