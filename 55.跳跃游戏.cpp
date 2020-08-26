/*
 * @lc app=leetcode.cn id=55 lang=cpp
 *
 * [55] 跳跃游戏
 */

// @lc code=start
class Solution {
public:
    bool canJump(vector<int>& nums) {
        int len = nums.size();
        int maxlen = 0;
        for(int i = 0; i < len; i++){
            if(i > maxlen) return false;
            maxlen = max(maxlen, i + nums[i]);
            if(maxlen >= len) return true;
        }
        return true;//最后返回true，已经跳到了最后的位置
    }
};
// @lc code=end

