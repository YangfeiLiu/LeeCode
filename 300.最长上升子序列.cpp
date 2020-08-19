/*
 * @lc app=leetcode.cn id=300 lang=cpp
 *
 * [300] 最长上升子序列
 */

// @lc code=start
class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        if(nums.size() == 0) return 0;
        int* dp = new int[nums.size()];
        dp[0] = 1; // 表示0-i最长上升子序列长度
        int maxlen = 1;
        for(int i = 1; i < nums.size(); i++){
            dp[i] = 1;
            for(int j = 0; j < i; j++){
                if(nums[i] > nums[j])
                    dp[i] = max(dp[i], dp[j] + 1);
            }
            maxlen = max(maxlen, dp[i]);
        }
        return maxlen;
    }
};
// @lc code=end

