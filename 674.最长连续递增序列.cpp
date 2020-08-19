/*
 * @lc app=leetcode.cn id=674 lang=cpp
 *
 * [674] 最长连续递增序列
 */

// @lc code=start
class Solution {
public:
    int findLengthOfLCIS(vector<int>& nums) {
        if(nums.size() == 0) return 0;
        int len = 0;
        int maxv = 1;
        int i = 0;
        for(i; i < nums.size(); i++){
            if(i > 0 && nums[i] <= nums[i - 1]){
                maxv = max(maxv, i - len);
                len = i;
            }
        }
        maxv = max(maxv, i - len);
        return maxv;
    }
};
// @lc code=end

