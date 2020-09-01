/*
 * @lc app=leetcode.cn id=486 lang=cpp
 *
 * [486] 预测赢家
 */

// @lc code=start
class Solution {
public:
    bool PredictTheWinner(vector<int>& nums) {
        int len = nums.size();
        vector<vector<int>> dp(len, vector<int>(len, 0));
        //dp[i][j]表示从nums[i..j]拿，先手超后手的分数
        for(int i = 0; i < len; i++) dp[i][i] = nums[i];//只有一个数，先手拿走
        for(int i = len-1; i >= 0; i--){
            for(int j = i+1; j < len; j++){
                //如果先手拿走nums[i],后手可选区间为[i+1, j],dp[i+1][j]区间是后手先拿，此时后手变先手，因此用负号
                dp[i][j] = max(nums[i] - dp[i+1][j], nums[j] - dp[i][j-1]);
            }
        }
        return dp[0][len-1] >= 0;
    }
};
// @lc code=end

