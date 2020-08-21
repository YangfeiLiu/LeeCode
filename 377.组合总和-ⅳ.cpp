/*
 * @lc app=leetcode.cn id=377 lang=cpp
 *
 * [377] 组合总和 Ⅳ
 */

// @lc code=start
class Solution {
public:
    /*
    // 回溯的方法超时了
    int cnt = 0;
    int combinationSum4(vector<int>& nums, int target) {
        if(nums.size() == 0) return cnt;
        dfs(nums, target, 0);
        return cnt;
    }

    void dfs(vector<int>& nums, int target, int index){
        if(target == 0){
            cnt++;
            return;
        }
        for(int i = index; i < nums.size() && target >= 0; i++){
            dfs(nums, target - nums[i], 0);//注意这里不用的顺序也算，因此每次从0开始
        }
    }
    */
    int combinationSum4(vector<int>& nums, int target) {
        if(nums.size() == 0) return 0;
        vector<unsigned long long> dp(target + 1, 0); // dp[i]表示目标为i的总数
        dp[0] = 1;
        for(int i = 1; i <= target; i++){
            for(int j = 0; j < nums.size(); j++){
                dp[i] += ((i - nums[j] >= 0) ? dp[i - nums[j]] : 0);
            }
        }
        return dp[target];
    }
};
// @lc code=end

