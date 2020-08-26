/*
 * @lc app=leetcode.cn id=45 lang=cpp
 *
 * [45] 跳跃游戏 II
 */

// @lc code=start
class Solution {
public:
    int jump(vector<int>& nums) {
        int len = nums.size();
        if(len < 2) return 0;
        /*
        // 超时
       vector<int> dp(len, len);
        dp[len - 1] = 0;
        for(int i = len - 2; i >= 0; i--){
            if(nums[i] == 0) continue;
            if(nums[i] + i >= len - 1) dp[i] = 1;
            else{
                for(int j = i + 1; j <= nums[i] + i; j++)
                    dp[i] = min(dp[i], dp[j] + 1);
            }
        }
        return dp[0];
        */
       int end = 0;
       int step = 0;
       int maxlen = 0;
       for(int i = 0; i < len - 1; i++){
           maxlen = max(maxlen, nums[i] + i); // 能跳的最远位置
           if(i == end && maxlen >= len) return step + 1;
           if(i == end){//如果到了边界，就从边界起跳，更新边界
                step++;
                end = maxlen;
           }
       }
       return step;
    }
};
// @lc code=end

